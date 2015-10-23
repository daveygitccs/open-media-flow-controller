/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 12854 $ of $ 
 *
 * $Id:$
 */
/*
 * standard Net-SNMP includes 
 */
#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>

/*
 * include our parent header 
 */
#include "jmfcNamespaceRtspClientTable.h"
#include "jmfcNamespaceRtspClientTable_data_access.h"

#include "snmp_util.h"

/** @defgroup data_access data_access: Routines to access data
 *
 * These routines are used to locate the data used to satisfy
 * requests.
 * 
 * @{
 */
/**********************************************************************
 **********************************************************************
 ***
 *** Table jmfcNamespaceRtspClientTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * JUNIPER-MFC-MIB::jmfcNamespaceRtspClientTable is subid 4 of jmfcNamespace.
 * Its status is Current.
 * OID: .1.3.6.1.4.1.2636.1.2.1.4.4, length: 12
*/

/**
 * initialization for jmfcNamespaceRtspClientTable data access
 *
 * This function is called during startup to allow you to
 * allocate any resources you need for the data table.
 *
 * @param jmfcNamespaceRtspClientTable_reg
 *        Pointer to jmfcNamespaceRtspClientTable_registration
 *
 * @retval MFD_SUCCESS : success.
 * @retval MFD_ERROR   : unrecoverable error.
 */
int
jmfcNamespaceRtspClientTable_init_data
    (jmfcNamespaceRtspClientTable_registration *
     jmfcNamespaceRtspClientTable_reg)
{
    DEBUGMSGTL(("verbose:jmfcNamespaceRtspClientTable:jmfcNamespaceRtspClientTable_init_data","called\n"));

    /*
     * TODO:303:o: Initialize jmfcNamespaceRtspClientTable data.
     */
    /*
    ***************************************************
    ***             START EXAMPLE CODE              ***
    ***---------------------------------------------***/
    /*
     * if you are the sole writer for the file, you could
     * open it here. However, as stated earlier, we are assuming
     * the worst case, which in this case means that the file is
     * written to by someone else, and might not even exist when
     * we start up. So we can't do anything here.
     */
    /*
    ***---------------------------------------------***
    ***              END  EXAMPLE CODE              ***
    ***************************************************/

    return MFD_SUCCESS;
} /* jmfcNamespaceRtspClientTable_init_data */

/**
 * container overview
 *
 */

/**
 * container initialization
 *
 * @param container_ptr_ptr A pointer to a container pointer. If you
 *        create a custom container, use this parameter to return it
 *        to the MFD helper. If set to NULL, the MFD helper will
 *        allocate a container for you.
 * @param  cache A pointer to a cache structure. You can set the timeout
 *         and other cache flags using this pointer.
 *
 *  This function is called at startup to allow you to customize certain
 *  aspects of the access method. For the most part, it is for advanced
 *  users. The default code should suffice for most cases. If no custom
 *  container is allocated, the MFD code will create one for your.
 *
 *  This is also the place to set up cache behavior. The default, to
 *  simply set the cache timeout, will work well with the default
 *  container. If you are using a custom container, you may want to
 *  look at the cache helper documentation to see if there are any
 *  flags you want to set.
 *
 * @remark
 *  This would also be a good place to do any initialization needed
 *  for you data source. For example, opening a connection to another
 *  process that will supply the data, opening a database, etc.
 */
void
jmfcNamespaceRtspClientTable_container_init(netsnmp_container **
                                            container_ptr_ptr,
                             netsnmp_cache *cache)
{
    DEBUGMSGTL(("verbose:jmfcNamespaceRtspClientTable:jmfcNamespaceRtspClientTable_container_init","called\n"));
    
    if (NULL == container_ptr_ptr) {
        snmp_log(LOG_ERR,
                 "bad container param to jmfcNamespaceRtspClientTable_container_init\n");
        return;
    }

    /*
     * For advanced users, you can use a custom container. If you
     * do not create one, one will be created for you.
     */
    *container_ptr_ptr = NULL;

    if (NULL == cache) {
        snmp_log(LOG_ERR,
                 "bad cache param to jmfcNamespaceRtspClientTable_container_init\n");
        return;
    }

    /*
     * TODO:345:A: Set up jmfcNamespaceRtspClientTable cache properties.
     *
     * Also for advanced users, you can set parameters for the
     * cache. Do not change the magic pointer, as it is used
     * by the MFD helper. To completely disable caching, set
     * cache->enabled to 0.
     */
    cache->timeout = JMFCNAMESPACERTSPCLIENTTABLE_CACHE_TIMEOUT; /* seconds */
} /* jmfcNamespaceRtspClientTable_container_init */

/**
 * container shutdown
 *
 * @param container_ptr_ptr A pointer to the container.
 *
 *  This function is called at shutdown to allow you to customize certain
 *  aspects of the access method. For the most part, it is for advanced
 *  users. The default code should suffice for most cases.
 *
 *  This function is called before jmfcNamespaceRtspClientTable_container_free().
 *
 * @remark
 *  This would also be a good place to do any cleanup needed
 *  for you data source. For example, closing a connection to another
 *  process that supplied the data, closing a database, etc.
 */
void
jmfcNamespaceRtspClientTable_container_shutdown(netsnmp_container *
                                                container_ptr)
{
    DEBUGMSGTL(("verbose:jmfcNamespaceRtspClientTable:jmfcNamespaceRtspClientTable_container_shutdown","called\n"));
    
    if (NULL == container_ptr) {
        snmp_log(LOG_ERR,
                 "bad params to jmfcNamespaceRtspClientTable_container_shutdown\n");
        return;
    }

} /* jmfcNamespaceRtspClientTable_container_shutdown */

/**
 * load initial data
 *
 * TODO:350:M: Implement jmfcNamespaceRtspClientTable data load
 * This function will also be called by the cache helper to load
 * the container again (after the container free function has been
 * called to free the previous contents).
 *
 * @param container container to which items should be inserted
 *
 * @retval MFD_SUCCESS              : success.
 * @retval MFD_RESOURCE_UNAVAILABLE : Can't access data source
 * @retval MFD_ERROR                : other error.
 *
 *  This function is called to load the index(es) (and data, optionally)
 *  for the every row in the data set.
 *
 * @remark
 *  While loading the data, the only important thing is the indexes.
 *  If access to your data is cheap/fast (e.g. you have a pointer to a
 *  structure in memory), it would make sense to update the data here.
 *  If, however, the accessing the data invovles more work (e.g. parsing
 *  some other existing data, or peforming calculations to derive the data),
 *  then you can limit yourself to setting the indexes and saving any
 *  information you will need later. Then use the saved information in
 *  jmfcNamespaceRtspClientTable_row_prep() for populating data.
 *
 * @note
 *  If you need consistency between rows (like you want statistics
 *  for each row to be from the same time frame), you should set all
 *  data here.
 *
 */
int
jmfcNamespaceRtspClientTable_container_load(netsnmp_container *container)
{
    jmfcNamespaceRtspClientTable_rowreq_ctx *rowreq_ctx;
    size_t                 count = 0;

    /*
     * temporary storage for index values
     */
        /*
         * jmfcNamespaceName(2)/OCTETSTR/ASN_OCTET_STR/char(char)//L/A/w/e/R/d/h
         */
   char   jmfcNamespaceName[32];
   size_t      jmfcNamespaceName_len;

    
    /*
     * this example code is based on a data source that is a
     * text file to be read and parsed.
     */
    int err = 0, num_names = 0, idx = 0, rc = 0;
    tstr_array *names = NULL;
    const char *ns_name = NULL;
    node_name_t cnt_name = {0};
    uint64 value = 0;
    struct counter64 cnt64;

    DEBUGMSGTL(("verbose:jmfcNamespaceRtspClientTable:jmfcNamespaceRtspClientTable_container_load","called\n"));

    /*
    ***************************************************
    ***             START EXAMPLE CODE              ***
    ***---------------------------------------------***/
    err = snmp_ns_get_names(&names);
    if (err) {
	rc = MFD_RESOURCE_UNAVAILABLE;
	bail_error(err);
    }
    num_names = tstr_array_length_quick(names);
    /* there are no namespaces, this is not an error */
    if (0 == num_names) {
	rc = MFD_END_OF_DATA;
	bail_error(0);
    }
    /*
    ***---------------------------------------------***
    ***              END  EXAMPLE CODE              ***
    ***************************************************/
    /*
     * TODO:351:M: |-> Load/update data in the jmfcNamespaceRtspClientTable container.
     * loop over your jmfcNamespaceRtspClientTable data, allocate a rowreq context,
     * set the index(es) [and data, optionally] and insert into
     * the container.
     */
    while( 1 ) {
    /*
    ***************************************************
    ***             START EXAMPLE CODE              ***
    ***---------------------------------------------***/
	if (idx >=  num_names) {
	    rc = MFD_END_OF_DATA;
        break;
	}
	ns_name = tstr_array_get_str_quick(names, idx);
	if (NULL == ns_name) {
	    idx++;
	    continue;
	}
	/* XXX - check for buffer overrun */
	bzero(jmfcNamespaceName, sizeof(jmfcNamespaceName));
	strncpy(jmfcNamespaceName, ns_name, sizeof(jmfcNamespaceName));
	jmfcNamespaceName[sizeof(jmfcNamespaceName) -1 ] = '\0';
	jmfcNamespaceName_len = strlen(jmfcNamespaceName);
    /*
    ***---------------------------------------------***
    ***              END  EXAMPLE CODE              ***
    ***************************************************/

        /*
         * TODO:352:M: |   |-> set indexes in new jmfcNamespaceRtspClientTable rowreq context.
         */
        rowreq_ctx = jmfcNamespaceRtspClientTable_allocate_rowreq_ctx();
        if (NULL == rowreq_ctx) {
            snmp_log(LOG_ERR, "memory allocation failed\n");
            return MFD_RESOURCE_UNAVAILABLE;
        }
        if (MFD_SUCCESS !=
            jmfcNamespaceRtspClientTable_indexes_set(rowreq_ctx,
                                                     jmfcNamespaceName,
                                                     jmfcNamespaceName_len))
        {
            snmp_log(LOG_ERR,
                     "error setting index while loading "
                     "jmfcNamespaceRtspClientTable data.\n");
            jmfcNamespaceRtspClientTable_release_rowreq_ctx(rowreq_ctx);
            continue;
        }

        /*
         * TODO:352:r: |   |-> populate jmfcNamespaceRtspClientTable data context.
         * Populate data context here. (optionally, delay until row prep)
         */
    /*
     * TRANSIENT or semi-TRANSIENT data:
     * copy data or save any info needed to do it in row_prep.
     */
    /*
     * setup/save data for jmfcNamespaceRtspClientRequests
     * jmfcNamespaceRtspClientRequests(1)/COUNTER64/ASN_COUNTER64/U64(U64)//l/A/w/e/r/d/h
     */
    /** no mapping */
	snprintf(cnt_name, sizeof(cnt_name), "ns.%s.rtsp.client.requests",
		tstr_array_get_str_quick(names, idx));
	value = nkncnt_get_uint64(cnt_name);
	cnt64.high = value >> 32;;
	cnt64.low = value & 0xFFFFFFFF ;

        rowreq_ctx->data.jmfcNamespaceRtspClientRequests.high =
            cnt64.high;
        rowreq_ctx->data.jmfcNamespaceRtspClientRequests.low =
            cnt64.low;
    
    /*
     * setup/save data for jmfcNamespaceRtspClientResponses
     * jmfcNamespaceRtspClientResponses(2)/COUNTER64/ASN_COUNTER64/U64(U64)//l/A/w/e/r/d/h
     */
    /** no mapping */
	snprintf(cnt_name, sizeof(cnt_name), "ns.%s.rtsp.client.responses",
		tstr_array_get_str_quick(names, idx));
	value = nkncnt_get_uint64(cnt_name);
	cnt64.high = value >> 32;;
	cnt64.low = value & 0xFFFFFFFF ;

        rowreq_ctx->data.jmfcNamespaceRtspClientResponses.high =
            cnt64.high;
        rowreq_ctx->data.jmfcNamespaceRtspClientResponses.low =
            cnt64.low;
    
    /*
     * setup/save data for jmfcNamespaceRtspClientCacheHit
     * jmfcNamespaceRtspClientCacheHit(3)/COUNTER64/ASN_COUNTER64/U64(U64)//l/A/w/e/r/d/h
     */
    /** no mapping */
	snprintf(cnt_name, sizeof(cnt_name), "ns.%s.rtsp.client.cache_hits",
		tstr_array_get_str_quick(names, idx));
	value = nkncnt_get_uint64(cnt_name);
	cnt64.high = value >> 32;;
	cnt64.low = value & 0xFFFFFFFF ;

        rowreq_ctx->data.jmfcNamespaceRtspClientCacheHit.high =
            cnt64.high;
        rowreq_ctx->data.jmfcNamespaceRtspClientCacheHit.low =
            cnt64.low;
    
    /*
     * setup/save data for jmfcNamespaceRtspClientCacheMiss
     * jmfcNamespaceRtspClientCacheMiss(4)/COUNTER64/ASN_COUNTER64/U64(U64)//l/A/w/e/r/d/h
     */
    /** no mapping */
	snprintf(cnt_name, sizeof(cnt_name), "ns.%s.rtsp.client.cache_miss",
		tstr_array_get_str_quick(names, idx));
	value = nkncnt_get_uint64(cnt_name);
	cnt64.high = value >> 32;;
	cnt64.low = value & 0xFFFFFFFF ;

        rowreq_ctx->data.jmfcNamespaceRtspClientCacheMiss.high =
            cnt64.high;
        rowreq_ctx->data.jmfcNamespaceRtspClientCacheMiss.low =
            cnt64.low;
    
    /*
     * setup/save data for jmfcNamespaceRtspClientCachePartialHit
     * jmfcNamespaceRtspClientCachePartialHit(5)/COUNTER64/ASN_COUNTER64/U64(U64)//l/A/w/e/r/d/h
     */
    /** no mapping */
	snprintf(cnt_name, sizeof(cnt_name), "ns.%s.rtsp.client.cache_partial",
		tstr_array_get_str_quick(names, idx));
	value = nkncnt_get_uint64(cnt_name);
	cnt64.high = value >> 32;;
	cnt64.low = value & 0xFFFFFFFF ;

        rowreq_ctx->data.jmfcNamespaceRtspClientCachePartialHit.high =
            cnt64.high;
        rowreq_ctx->data.jmfcNamespaceRtspClientCachePartialHit.low =
            cnt64.low;
    
    /*
     * setup/save data for jmfcNamespaceRtspClientInBytes
     * jmfcNamespaceRtspClientInBytes(6)/COUNTER64/ASN_COUNTER64/U64(U64)//l/A/w/e/r/d/h
     */
    /** no mapping */
	snprintf(cnt_name, sizeof(cnt_name), "ns.%s.rtsp.client.in_bytes",
		tstr_array_get_str_quick(names, idx));
	value = nkncnt_get_uint64(cnt_name);
	cnt64.high = value >> 32;;
	cnt64.low = value & 0xFFFFFFFF ;

        rowreq_ctx->data.jmfcNamespaceRtspClientInBytes.high =
            cnt64.high;
        rowreq_ctx->data.jmfcNamespaceRtspClientInBytes.low =
            cnt64.low;
    
    /*
     * setup/save data for jmfcNamespaceRtspClientOutBytes
     * jmfcNamespaceRtspClientOutBytes(7)/COUNTER64/ASN_COUNTER64/U64(U64)//l/A/w/e/r/d/h
     */
    /** no mapping */
	snprintf(cnt_name, sizeof(cnt_name), "ns.%s.rtsp.client.out_bytes",
		tstr_array_get_str_quick(names, idx));
	value = nkncnt_get_uint64(cnt_name);
	cnt64.high = value >> 32;;
	cnt64.low = value & 0xFFFFFFFF ;
        rowreq_ctx->data.jmfcNamespaceRtspClientOutBytes.high =
            cnt64.high;
        rowreq_ctx->data.jmfcNamespaceRtspClientOutBytes.low =
            cnt64.low;
    
    /*
     * setup/save data for jmfcNamespaceRtspClientConns
     * jmfcNamespaceRtspClientConns(8)/GAUGE/ASN_GAUGE/u_long(u_long)//l/A/w/e/r/d/h
     */
    /** no mapping */
	snprintf(cnt_name, sizeof(cnt_name), "ns.%s.http.client.conns",
		tstr_array_get_str_quick(names, idx));
	value = nkncnt_get_uint32(cnt_name);
        rowreq_ctx->data.jmfcNamespaceRtspClientConns = value;
    
    /*
     * setup/save data for jmfcNamespaceRtspClientActiveConns
     * jmfcNamespaceRtspClientActiveConns(9)/GAUGE/ASN_GAUGE/u_long(u_long)//l/A/w/e/r/d/h
     */
    /** no mapping */
	snprintf(cnt_name, sizeof(cnt_name), "ns.%s.rtsp.client.active_conns",
		tstr_array_get_str_quick(names, idx));
	value = nkncnt_get_uint32(cnt_name);
        rowreq_ctx->data.jmfcNamespaceRtspClientActiveConns = value;
    
    /*
     * setup/save data for jmfcNamespaceRtspClientIdleConns
     * jmfcNamespaceRtspClientIdleConns(10)/GAUGE/ASN_GAUGE/u_long(u_long)//l/A/w/e/r/d/h
     */
    /** no mapping */
	snprintf(cnt_name, sizeof(cnt_name), "ns.%s.rtsp.client.idle_conns",
		tstr_array_get_str_quick(names, idx));
	value = nkncnt_get_uint32(cnt_name);
        rowreq_ctx->data.jmfcNamespaceRtspClientIdleConns = value;
    
    /*
     * setup/save data for jmfcNamespaceRtspClientStatus2xx
     * jmfcNamespaceRtspClientStatus2xx(11)/COUNTER64/ASN_COUNTER64/U64(U64)//l/A/w/e/r/d/h
     */
    /** no mapping */
	snprintf(cnt_name, sizeof(cnt_name), "ns.%s.rtsp.client.resp_2xx",
		tstr_array_get_str_quick(names, idx));
	value = nkncnt_get_uint64(cnt_name);
	cnt64.high = value >> 32;;
	cnt64.low = value & 0xFFFFFFFF ;

        rowreq_ctx->data.jmfcNamespaceRtspClientStatus2xx.high =
            cnt64.high;
        rowreq_ctx->data.jmfcNamespaceRtspClientStatus2xx.low =
            cnt64.low;
    
    /*
     * setup/save data for jmfcNamespaceRtspClientStatus3xx
     * jmfcNamespaceRtspClientStatus3xx(12)/COUNTER64/ASN_COUNTER64/U64(U64)//l/A/w/e/r/d/h
     */
    /** no mapping */
	snprintf(cnt_name, sizeof(cnt_name), "ns.%s.rtsp.client.resp_3xx",
		tstr_array_get_str_quick(names, idx));
	value = nkncnt_get_uint64(cnt_name);
	cnt64.high = value >> 32;;
	cnt64.low = value & 0xFFFFFFFF ;

        rowreq_ctx->data.jmfcNamespaceRtspClientStatus3xx.high =
            cnt64.high;
        rowreq_ctx->data.jmfcNamespaceRtspClientStatus3xx.low =
            cnt64.low;
    
    /*
     * setup/save data for jmfcNamespaceRtspClientStatus4xx
     * jmfcNamespaceRtspClientStatus4xx(13)/COUNTER64/ASN_COUNTER64/U64(U64)//l/A/w/e/r/d/h
     */
    /** no mapping */
	snprintf(cnt_name, sizeof(cnt_name), "ns.%s.rtsp.client.resp_4xx",
		tstr_array_get_str_quick(names, idx));
	value = nkncnt_get_uint64(cnt_name);
	cnt64.high = value >> 32;;
	cnt64.low = value & 0xFFFFFFFF ;

        rowreq_ctx->data.jmfcNamespaceRtspClientStatus4xx.high =
            cnt64.high;
        rowreq_ctx->data.jmfcNamespaceRtspClientStatus4xx.low =
            cnt64.low;
    
    /*
     * setup/save data for jmfcNamespaceRtspClientStatus5xx
     * jmfcNamespaceRtspClientStatus5xx(14)/COUNTER64/ASN_COUNTER64/U64(U64)//l/A/w/e/r/d/h
     */
    /** no mapping */
	snprintf(cnt_name, sizeof(cnt_name), "ns.%s.rtsp.client.resp_5xx",
		tstr_array_get_str_quick(names, idx));
	value = nkncnt_get_uint64(cnt_name);
	cnt64.high = value >> 32;;
	cnt64.low = value & 0xFFFFFFFF ;

        rowreq_ctx->data.jmfcNamespaceRtspClientStatus5xx.high =
            cnt64.high;
        rowreq_ctx->data.jmfcNamespaceRtspClientStatus5xx.low =
            cnt64.low;
    
        
        /*
         * insert into table container
         */
        CONTAINER_INSERT(container, rowreq_ctx);
        ++count;
	++idx;
    }

    /*
    ***************************************************
    ***             START EXAMPLE CODE              ***
    ***---------------------------------------------***/
    /*
    ***---------------------------------------------***
    ***              END  EXAMPLE CODE              ***
    ***************************************************/

    DEBUGMSGT(("verbose:jmfcNamespaceRtspClientTable:jmfcNamespaceRtspClientTable_container_load", "inserted %d records\n", (int)count));

bail:
    return rc;
} /* jmfcNamespaceRtspClientTable_container_load */

/**
 * container clean up
 *
 * @param container container with all current items
 *
 *  This optional callback is called prior to all
 *  item's being removed from the container. If you
 *  need to do any processing before that, do it here.
 *
 * @note
 *  The MFD helper will take care of releasing all the row contexts.
 *
 */
void
jmfcNamespaceRtspClientTable_container_free(netsnmp_container *container)
{
    DEBUGMSGTL(("verbose:jmfcNamespaceRtspClientTable:jmfcNamespaceRtspClientTable_container_free","called\n"));

    /*
     * TODO:380:M: Free jmfcNamespaceRtspClientTable container data.
     */
} /* jmfcNamespaceRtspClientTable_container_free */

/**
 * prepare row for processing.
 *
 *  When the agent has located the row for a request, this function is
 *  called to prepare the row for processing. If you fully populated
 *  the data context during the index setup phase, you may not need to
 *  do anything.
 *
 * @param rowreq_ctx pointer to a context.
 *
 * @retval MFD_SUCCESS     : success.
 * @retval MFD_ERROR       : other error.
 */
int
jmfcNamespaceRtspClientTable_row_prep
    (jmfcNamespaceRtspClientTable_rowreq_ctx * rowreq_ctx)
{
    DEBUGMSGTL(("verbose:jmfcNamespaceRtspClientTable:jmfcNamespaceRtspClientTable_row_prep","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

    /*
     * TODO:390:o: Prepare row for request.
     * If populating row data was delayed, this is the place to
     * fill in the row for this request.
     */

    return MFD_SUCCESS;
} /* jmfcNamespaceRtspClientTable_row_prep */

/** @} */