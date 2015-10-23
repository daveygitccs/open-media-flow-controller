TRANSL_ENTRY(PREPEND_TRANS_STR"service-elementsanalyticscache-ingestsize-threshold*")
TRANSL_NUM_NDS(1)
TRANSL_NDS("/nkn/nvsd/am/config/cache_ingest_size_threshold",
	    TYPE_UINT32,
	    ND_NORMAL,
	    0,NULL,
	    0,0,0,0)
TRANSL_END_NDS
TRANSL_ENTRY_END

TRANSL_ENTRY(PREPEND_TRANS_STR"service-elementsanalyticscache-promotion*")
TRANSL_NUM_NDS(1)
TRANSL_NDS_BASIC("/nkn/nvsd/am/config/cache_promotion_enabled",
            TYPE_BOOL,
            ND_HARDCODED,
            0,"true")
TRANSL_END_NDS
TRANSL_ENTRY_END

TRANSL_ENTRY(PREPEND_TRANS_STR"service-elementsanalyticscache-promotionenable*")
TRANSL_NUM_NDS(1)
TRANSL_NDS_BASIC("/nkn/nvsd/am/config/cache_promotion_enabled",
	    TYPE_BOOL,
	    ND_HARDCODED,
	    0,"true")
TRANSL_END_NDS
TRANSL_ENTRY_END

TRANSL_ENTRY(PREPEND_TRANS_STR"service-elementsanalyticscache-promotiondisable*")
TRANSL_NUM_NDS(1)
TRANSL_NDS_BASIC("/nkn/nvsd/am/config/cache_promotion_enabled",
	    TYPE_BOOL,
	    ND_HARDCODED,
	    0,"false")
TRANSL_END_NDS
TRANSL_ENTRY_END

TRANSL_ENTRY(PREPEND_TRANS_STR"service-elementsanalyticscache-promotionhotness-threshold*")
TRANSL_NUM_NDS(1)
TRANSL_NDS("/nkn/nvsd/am/config/cache_promotion/hotness_threshold",
	    TYPE_UINT32,
	    ND_NORMAL,
	    0,NULL,
	    0,0,0,0)
TRANSL_END_NDS
TRANSL_ENTRY_END

TRANSL_ENTRY(PREPEND_TRANS_STR"service-elementsanalyticsmemory-limit*")
TRANSL_NUM_NDS(1)
TRANSL_NDS("/nkn/nvsd/am/config/memory_limit",
	    TYPE_UINT32,
	    ND_NORMAL,
	    0,NULL,
	    0,0,0,0)
TRANSL_END_NDS
TRANSL_ENTRY_END

TRANSL_ENTRY(PREPEND_TRANS_STR"service-elementsanalyticscache-ingestobject-timeout*")
TRANSL_NUM_NDS(1)
TRANSL_NDS("/nkn/nvsd/am/config/cache_ingest_object_timeout",
	    TYPE_UINT32,
	    ND_NORMAL,
	    0,NULL,
	    0,0,0,0)
TRANSL_END_NDS
TRANSL_ENTRY_END

TRANSL_ENTRY(PREPEND_TRANS_STR"service-elementsanalyticscache-ingestqueue-depth*")
TRANSL_NUM_NDS(1)
TRANSL_NDS("/nkn/nvsd/am/config/cache_ingest_queue_depth",
	    TYPE_UINT32,
	    ND_NORMAL,
	    0,NULL,
	    0,0,0,0)
TRANSL_END_NDS
TRANSL_ENTRY_END

TRANSL_ENTRY(PREPEND_TRANS_STR"service-elementsanalyticscache-ingestpolicy*")
TRANSL_NUM_NDS(1)
TRANSL_NDS_EXT_VAL("/nkn/nvsd/am/config/cache_ingest_policy",
	    TYPE_UINT32,
	    ND_NORMAL,
	    0,NULL)
TRANSL_NDS_VAL_MAP_START(3)
TRANSL_NDS_VAL_MAP(0,"auto","1")
TRANSL_NDS_VAL_MAP(1,"namespace-based","2")
TRANSL_NDS_VAL_MAP(2,"hybrid","3")
TRANSL_NDS_VAL_MAP_END
TRANSL_END_NDS
TRANSL_ENTRY_END