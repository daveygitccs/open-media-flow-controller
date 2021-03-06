/*	$Id: variables.c,v 1.1.1.1 2003/09/19 17:05:56 gregs Exp $	*/

/*
 * Copyright (c) 1997-2001 Sandro Sigala.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"

#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "zile.h"
#include "extern.h"
#include "htable.h"

/*
 * Default variables values table.
 */
static struct var_entry {
	char *var;	/* Variable name. */
	char *fmt;	/* Variable format (boolean, color, etc.). */
	char *val;	/* Default value. */
} def_vars[] = {
#define X(zile_var, fmt, val, doc) { zile_var, fmt, val },
#include "tbl_vars.h"
#undef X
};

static htable var_table;

void init_variables(void)
{
	struct var_entry *p;

	var_table = htable_new();

	for (p = &def_vars[0]; p < &def_vars[sizeof(def_vars) / sizeof(def_vars[0])]; p++)
		set_variable(p->var, p->val);
}

void free_variables(void)
{
	htable_delete(var_table);
}

void set_variable(char *var, char *val)
{
	htable_store(var_table, var, zstrdup(val));

	/* Force refresh of cached variables. */
	cur_tp->refresh_cached_variables();
}

void unset_variable(char *var)
{
	char *p = htable_fetch(var_table, var);
	htable_remove(var_table, var);
	free(p);
}

char *get_variable(char *var)
{
	return htable_fetch(var_table, var);
}

int is_variable_equal(char *var, char *val)
{
	char *v = htable_fetch(var_table, var);
	return v != NULL && !strcmp(v, val);
}

int lookup_bool_variable(char *var)
{
	char *p;

	if ((p = htable_fetch(var_table, var)) != NULL)
		return !strcmp(p, "true");

#if 0
	minibuf_error("Warning: used uninitialized variable `@v%s@@'", var);
	waitkey(2 * 1000);
#endif

	return FALSE;
}

static historyp make_variable_history(void)
{
	alist al;
	historyp hp;
	hpair *pair;

	al = htable_list(var_table);
	hp = new_history(FALSE);
	for (pair = alist_first(al); pair != NULL; pair = alist_next(al))
		alist_append(hp->completions, zstrdup(pair->key));
	alist_delete(al);

	return hp;
}

char *minibuf_read_variable_name(char *msg)
{
	char *ms;
	historyp hp;

	hp = make_variable_history();

	for (;;) {
		ms = minibuf_read_history(msg, "", hp);

		if (ms == NULL) {
			free_history(hp);
			cancel();
			return NULL;
		}

		if (ms[0] == '\0') {
			free_history(hp);
			minibuf_error("No variable name given");
			return NULL;
		} else if (get_variable(ms) == NULL) {
			minibuf_error("Undefined variable name");
			waitkey(2 * 1000);
		} else {
			minibuf_clear();
			break;
		}
	}

	free_history(hp);

	return ms;
}

static char *get_variable_format(char *var)
{
	struct var_entry *p;
	for (p = &def_vars[0]; p < &def_vars[sizeof(def_vars) / sizeof(def_vars[0])]; p++)
		if (!strcmp(p->var, var))
			return p->fmt;

	return NULL;
}

DEFUN("set-variable", set_variable)
/*+
Set a variable value to the user specified value.
+*/
{
	char buf[128], *var, *val, *fmt;

	var = minibuf_read_variable_name("Set variable: ");
	if (var == NULL)
		return FALSE;

	/* `tab-width' and `fill-column' are local to buffers. */
	if (!strcmp(var, "tab-width"))
		sprintf(buf, "%d", cur_bp->tab_width);
	else if (!strcmp(var, "fill-column"))
		sprintf(buf, "%d", cur_bp->fill_column);
	else
		strcpy(buf, get_variable(var));
	fmt = get_variable_format(var);
	if (!strcmp(fmt, "c")) {
		if ((val = minibuf_read_color("Set %s to value: ", var)) == NULL)
			return cancel();
	} else if (!strcmp(fmt, "b")) {
		int i;
		if ((i = minibuf_read_boolean("Set %s to value: ", var)) == -1)
			return cancel();
		val = (i == TRUE) ? "true" : "false";
	} else { /* Non color, boolean or such fixed value varabile. */
		if ((val = minibuf_read("Set %s to value: ", buf, var)) == NULL)
			return cancel();
	}

	/*
	 * The `tab-width' and `fill-column' variables are local
	 * to the buffer (automatically becomes buffer-local when
	 * set in any fashion).
	 */
	if (!strcmp(var, "tab-width")) {
		int i = atoi(val);
		if (i < 1) {
			minibuf_error("Invalid tab-width value `@v%s@@'", val);
			waitkey(2 * 1000);
		} else
			cur_bp->tab_width = i;

	} else if (!strcmp(var, "fill-column")) {
		int i = atoi(val);
		if (i < 2) {
			minibuf_error("Invalid fill-column value `@v%s@@'", val);
			waitkey(2 * 1000);
		} else
			cur_bp->fill_column = i;
	} else
		set_variable(var, val);

	return TRUE;
}

static int sorter(const void *p1, const void *p2)
{
	return strcmp((*(hpair **)p1)->key, (*(hpair **)p2)->key);
}

static void write_variables_list(va_list ap)
{
	windowp old_wp = va_arg(ap, windowp);
	alist al;
	hpair *pair;

	bprintf("Global variables:\n\n");
	bprintf("%-30s %s\n", "Variable", "Value");
	bprintf("%-30s %s\n", "--------", "-----");

	al = htable_list(var_table);
	alist_sort(al, sorter);
	for (pair = alist_first(al); pair != NULL; pair = alist_next(al))
		if (pair->data != NULL)
			bprintf("%-30s \"%s\"\n", pair->key, pair->data);
	alist_delete(al);

	bprintf("\nLocal buffer variables:\n\n");
	bprintf("%-30s %s\n", "Variable", "Value");
	bprintf("%-30s %s\n", "--------", "-----");
	bprintf("%-30s \"%d\"\n", "fill-column", old_wp->bp->fill_column);
	bprintf("%-30s \"%d\"\n", "tab-width", old_wp->bp->tab_width);
}

DEFUN("list-variables", list_variables)
/*+
List defined variables.
+*/
{
	write_temp_buffer("*Variable List*", write_variables_list, cur_wp);
	return TRUE;
}
