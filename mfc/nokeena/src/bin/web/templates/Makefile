    # Makefile
# Note: The customer-defines.tem and tms-layout.tem files are in:
#       src/oem/<OEM>/web/templates 
# because they have OEM specific text.

include ${PROD_TREE_ROOT}/src/mk/common.mk

FILES_INSTALL_DIR=/lib/web/templates

FILES= \
	customer-defines.tem \
        servicecfg-layout.tem \
	mon-network.tem	\
	mon-summary.tem	\
	mon-summary-common.tem \
	setup-ezconfig.tem \
	mon-stats.tem \
	mon-stats-common.tem \
	mon-bandwidth.tem \
	get-mon-stats.tem \
        servicecfg-network.tem \
        servicecfg-analytics.tem \
        servicecfg-namespace.tem \
        servicecfg-uri.tem \
        servicecfg-originfetch.tem \
        servicecfg-delivery.tem \
        servicecfg-logging.tem \
        servicecfg-virplayer.tem \
        servicecfg-type1.tem \
        servicecfg-type2.tem \
        servicecfg-type3.tem \
        servicecfg-type4.tem \
        servicecfg-type0.tem \
        servicecfg-media-cache.tem \
        setup-tech-support.tem  \
        servicelog.tem \
        get-servicelog-lines.tem \
        errorlog.tem \
        dashboard-dashboard.tem \
        dashboard-bandwidth-savings.tem \
        dashboard-disk-cache.tem \
        dashboard-cache-hit.tem \
        dashboard-ns-report.tem \
        dashboard-layout.tem \
        logging.tem \
        reports-layout.tem \
        reports-intf.tem \
        reports-intfhr.tem \
        reports-intfday.tem \
        reports-bandwidth.tem \
        mon-namespace.tem \
	cachelog.tem \
        get-cachelog-lines.tem \
	tracelog.tem \
        get-tracelog-lines.tem \
        login.tem \
	servicecfg-shownm.tem \
	servicecfg-showvp.tem \
	streamlog.tem \
        get-streamlog-lines.tem \
	log-layout.tem \
	fuselog.tem \
        get-fuselog-lines.tem \
	servicecfg-nsconfig.tem \
	tms-layout.tem \
	fmsaccesslog.tem \
        get-fmsaccesslog-lines.tem \
	fmsedgelog.tem \
        get-fmsedgelog-lines.tem \
	show_documents.tem \
        get-errorlog-lines.tem \
        servicecfg-type5.tem \
	ns-object-delete-result.tem \
	setup-snmp.tem \
        servicecfg-servermap.tem \
        servicecfg-showsm.tem \
        servicecfg-smconfig.tem \
	publishlog.tem \
        get-publishlog-lines.tem \
	mfp-layout.tem \
	mfp-nfs-list.tem \
	mfp-common.tem \
	mfp-config.tem \
	servicecfg-mfpconfig.tem \
        servicecfg-type7.tem \
        servicecfg-type6.tem \
	mfp-dashboard.tem \
	mfp-nfsmount.tem \
	mon-resourcepool.tem \
	mon-resourcepool-common.tem \
	get-mon-resourcepool.tem \
	get-mon-namespace.tem \
        mon-namespace-common.tem \
	mon-ns-complete.tem \
	servicecfg-filemfpconfig.tem \
	servicecfg-mfpfilespts.tem \
	setup-interface.tem \
	setup-restart.tem \
	setup-ntp.tem \
	servicecfg-mfpfilemp4.tem \


include ${PROD_TREE_ROOT}/src/mk/files.mk

DO_FILES_POST_INSTALL=${PROD_BUILD_OUTPUT_DIR}/${INSTALL_TREE}/${BIN_DIR}/tmplcompiler/tmplcompiler ${PROD_INSTALL_OUTPUT_DIR}/${INSTALL_TREE}/opt/tms${FILES_INSTALL_DIR}/*.tem
