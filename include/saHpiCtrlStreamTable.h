/*
 * Note: this file originally auto-generated by mib2c using
 *        : mib2c.array-user.conf,v 5.18.2.2 2004/02/09 18:21:47 rstory Exp $
 *
 * $Id$
 *
 * Yes, there is lots of code here that you might not use. But it is much
 * easier to remove code than to add it!
 */
#ifndef SAHPICTRLSTREAMTABLE_H
#define SAHPICTRLSTREAMTABLE_H

#ifdef __cplusplus
extern "C" {
#endif


#include <net-snmp/net-snmp-config.h>
#include <net-snmp/library/container.h>
#include <net-snmp/agent/table_array.h>

/** Index saHpiDomainId is external */
/** Index saHpiResourceId is external */
/** Index saHpiResourceIsHistorical is external */
/** Index saHpiCtrlStreamEntryId is internal */

typedef struct saHpiCtrlStreamTable_context_s {
	netsnmp_index index; /** THIS MUST BE FIRST!!! */

	/*************************************************************
	 * You can store data internally in this structure.
	 *
	 * TODO: You will probably have to fix a few types here...
	 */
	/** TODO: add storage for external index(s)! */
	/** SaHpiEntryId = ASN_UNSIGNED */
	unsigned long saHpiCtrlStreamEntryId;
	
	/** SaHpiInstrumentId = ASN_UNSIGNED */
	unsigned long saHpiCtrlStreamNum;
	
	/** SaHpiCtrlOutputType = ASN_INTEGER */
	long saHpiCtrlStreamOutputType;
	
	/** SaHpiCtrlMode = ASN_INTEGER */
	long saHpiCtrlStreamDefaultMode;
	
	/** SaHpiCtrlMode = ASN_INTEGER */
	long saHpiCtrlStreamMode;
	
	/** TruthValue = ASN_INTEGER */
	long saHpiCtrlStreamIsReadOnly;
	
	/** TruthValue = ASN_INTEGER */
	long saHpiCtrlStreamIsWriteOnly;
	
	/** TruthValue = ASN_INTEGER */
	long saHpiCtrlStreamDefaultRepeat;
	
        /** SaHpiText = ASN_OCTET_STR */
        unsigned char saHpiCtrlStreamDefaultState[SAHPI_CTRL_MAX_STREAM_LENGTH];
        long saHpiCtrlStreamDefaultState_len;

	/** TruthValue = ASN_INTEGER */
	long saHpiCtrlStreamRepeat;
	
	/** SaHpiText = ASN_OCTET_STR */
        unsigned char saHpiCtrlStreamState[SAHPI_CTRL_MAX_STREAM_LENGTH];
        long saHpiCtrlStreamState_len;

	/** UNSIGNED32 = ASN_UNSIGNED */
	unsigned long saHpiCtrlStreamOem;
	
	/** RowPointer = ASN_OBJECT_ID */
	oid saHpiCtrlStreamRDR[MAX_OID_LEN];
	long saHpiCtrlStreamRDR_len;
	
	
	/*
	 * OR
	 *
	 * Keep a pointer to your data
	 */
	void * data;
	
	/*
	 *add anything else you want here
	 */
	
} saHpiCtrlStreamTable_context;

/*************************************************************
 * set funtions
 */
int set_table_ctrl_stream_mode (saHpiCtrlStreamTable_context *row_ctx);
int set_table_ctrl_stream_state (saHpiCtrlStreamTable_context *row_ctx);


/*************************************************************
 * function declarations
 */
SaErrorT populate_ctrl_stream(SaHpiSessionIdT sessionid, 
			      SaHpiRdrT *rdr_entry,
			      SaHpiRptEntryT *rpt_entry,
			      oid *full_oid, size_t full_oid_len,
			      oid *child_oid, size_t *child_oid_len);

/*************************************************************
 * function declarations
 */
void init_saHpiCtrlStreamTable(void);
void initialize_table_saHpiCtrlStreamTable(void);
const saHpiCtrlStreamTable_context * saHpiCtrlStreamTable_get_by_idx(netsnmp_index *);
const saHpiCtrlStreamTable_context * saHpiCtrlStreamTable_get_by_idx_rs(netsnmp_index *,
									int row_status);
int saHpiCtrlStreamTable_get_value(netsnmp_request_info *, netsnmp_index *, 
				   netsnmp_table_request_info *);


/*************************************************************
 * oid declarations
 */
extern oid saHpiCtrlStreamTable_oid[];
extern size_t saHpiCtrlStreamTable_oid_len;

#define saHpiCtrlStreamTable_TABLE_OID 1,3,6,1,4,1,18568,2,1,1,4,7,9

/* Number of table Indexes */
#define CTRL_STREAM_INDEX_NR 4 
#define saHpiDomainId_INDEX 0
#define saHpiResourceEntryId_INDEX 1
#define saHpiResourceIsHistorical_INDEX 2
#define saHpiCtrlStreamEntryId_INDEX 3

/*************************************************************
 * column number definitions for table saHpiCtrlStreamTable
 */
#define COLUMN_SAHPICTRLSTREAMENTRYID 1
#define COLUMN_SAHPICTRLSTREAMNUM 2
#define COLUMN_SAHPICTRLSTREAMOUTPUTTYPE 3
#define COLUMN_SAHPICTRLSTREAMDEFAULTMODE 4
#define COLUMN_SAHPICTRLSTREAMMODE 5
#define COLUMN_SAHPICTRLSTREAMISREADONLY 6
#define COLUMN_SAHPICTRLSTREAMISWRITEONLY 7
#define COLUMN_SAHPICTRLSTREAMDEFAULTREPEAT 8
#define COLUMN_SAHPICTRLSTREAMDEFAULTSTATE 9
#define COLUMN_SAHPICTRLSTREAMREPEAT 10
#define COLUMN_SAHPICTRLSTREAMSTATE 11
#define COLUMN_SAHPICTRLSTREAMOEM 12
#define COLUMN_SAHPICTRLSTREAMRDR 13
#define saHpiCtrlStreamTable_COL_MIN 2
#define saHpiCtrlStreamTable_COL_MAX 13

/* comment out the following line if you don't handle SET-REQUEST for saHpiCtrlStreamTable */
#define saHpiCtrlStreamTable_SET_HANDLING

/* comment out the following line if you can't create new rows */
#define saHpiCtrlStreamTable_ROW_CREATION

/* comment out the following line if you don't want the secondary index */
#define saHpiCtrlStreamTable_IDX2

/* uncommend the following line if you allow modifications to an
 * active row */
/** define saHpiCtrlStreamTable_CAN_MODIFY_ACTIVE_ROW */

#ifdef saHpiCtrlStreamTable_SET_HANDLING

int saHpiCtrlStreamTable_extract_index( saHpiCtrlStreamTable_context * ctx, netsnmp_index * hdr );

void saHpiCtrlStreamTable_set_reserve1( netsnmp_request_group * );
void saHpiCtrlStreamTable_set_reserve2( netsnmp_request_group * );
void saHpiCtrlStreamTable_set_action( netsnmp_request_group * );
void saHpiCtrlStreamTable_set_commit( netsnmp_request_group * );
void saHpiCtrlStreamTable_set_free( netsnmp_request_group * );
void saHpiCtrlStreamTable_set_undo( netsnmp_request_group * );

saHpiCtrlStreamTable_context * saHpiCtrlStreamTable_duplicate_row( saHpiCtrlStreamTable_context* );
netsnmp_index * saHpiCtrlStreamTable_delete_row( saHpiCtrlStreamTable_context* );

int saHpiCtrlStreamTable_can_activate(saHpiCtrlStreamTable_context *undo_ctx,
					      saHpiCtrlStreamTable_context *row_ctx,
					      netsnmp_request_group * rg);
int saHpiCtrlStreamTable_can_deactivate(saHpiCtrlStreamTable_context *undo_ctx,
						saHpiCtrlStreamTable_context *row_ctx,
						netsnmp_request_group * rg);
int saHpiCtrlStreamTable_can_delete(saHpiCtrlStreamTable_context *undo_ctx,
					    saHpiCtrlStreamTable_context *row_ctx,
					    netsnmp_request_group * rg);


#ifdef saHpiCtrlStreamTable_ROW_CREATION
	saHpiCtrlStreamTable_context * saHpiCtrlStreamTable_create_row( netsnmp_index* );
#endif
#endif

#ifdef saHpiCtrlStreamTable_IDX2
	saHpiCtrlStreamTable_context * saHpiCtrlStreamTable_get( const char *name, int len );
#endif

#ifdef __cplusplus
};
#endif

#endif /** SAHPICTRLSTREAMTABLE_H */
