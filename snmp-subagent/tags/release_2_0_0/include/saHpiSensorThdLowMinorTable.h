/*
 * Note: this file originally auto-generated by mib2c using
 *        : mib2c.array-user.conf,v 5.18.2.2 2004/02/09 18:21:47 rstory Exp $
 *
 * $Id$
 *
 * Yes, there is lots of code here that you might not use. But it is much
 * easier to remove code than to add it!
 */
#ifndef SAHPISENSORTHDLOWMINORTABLE_H
#define SAHPISENSORTHDLOWMINORTABLE_H

#ifdef __cplusplus
extern "C" {
#endif

    
#include <net-snmp/net-snmp-config.h>
#include <net-snmp/library/container.h>
#include <net-snmp/agent/table_array.h>

        /** Index saHpiDomainId is external */
        /** Index saHpiResourceId is external */
        /** Index saHpiResourceIsHistorical is external */
        /** Index saHpiSensorNum is external */

typedef struct saHpiSensorThdLowMinorTable_context_s {
    netsnmp_index index; /** THIS MUST BE FIRST!!! */

    /*************************************************************
     * You can store data internally in this structure.
     *
     * TODO: You will probably have to fix a few types here...
     */
    /** TODO: add storage for external index(s)! */
        /** TruthValue = ASN_INTEGER */
            long saHpiSensorThdLowMinorIsReadable;

        /** TruthValue = ASN_INTEGER */
            long saHpiSensorThdLowMinorIsWritable;

        /** SaHpiSensorReadingType = ASN_INTEGER */
            long saHpiSensorThdLowMinorType;

        /** SaHpiSensorReadingValue = ASN_OCTET_STR */
            unsigned char saHpiSensorThdLowMinorValue[SAHPI_SENSOR_BUFFER_LENGTH];
            long saHpiSensorThdLowMinorValue_len;

        /** TruthValue = ASN_INTEGER */
            long saHpiSensorThdLowMinorNonLinear;


    /*
     * OR
     *
     * Keep a pointer to your data
     */
    void * data;

    /*
     *add anything else you want here
     */

} saHpiSensorThdLowMinorTable_context;

/*************************************************************
 * funtions
 */
int set_table_sen_thds_low_minor (saHpiSensorThdLowMinorTable_context *row_ctx);


SaErrorT populate_sen_thd_low_minor(SaHpiSessionIdT sessionid, 
				   SaHpiRdrT *rdr_entry,
				   SaHpiRptEntryT *rpt_entry,
				   SaHpiSensorThresholdsT *sensor_thresholds);

/*************************************************************
 * function declarations
 */
void init_saHpiSensorThdLowMinorTable(void);
void initialize_table_saHpiSensorThdLowMinorTable(void);
const saHpiSensorThdLowMinorTable_context * saHpiSensorThdLowMinorTable_get_by_idx(netsnmp_index *);
const saHpiSensorThdLowMinorTable_context * saHpiSensorThdLowMinorTable_get_by_idx_rs(netsnmp_index *,
                                        int row_status);
int saHpiSensorThdLowMinorTable_get_value(netsnmp_request_info *, netsnmp_index *, netsnmp_table_request_info *);


/*************************************************************
 * oid declarations
 */
extern oid saHpiSensorThdLowMinorTable_oid[];
extern size_t saHpiSensorThdLowMinorTable_oid_len;

#define saHpiSensorThdLowMinorTable_TABLE_OID 1,3,6,1,4,1,18568,2,1,1,4,9,11

/* Number of table Indexes */
#define SEN_THD_LOW_MINOR_IDX_NR 4
#define saHpiDomainId_INDEX 0
#define saHpiResourceEntryId_INDEX 1
#define saHpiResourceIsHistorical_INDEX 2
#define saHpiSensorNum_INDEX 3
    
/*************************************************************
 * column number definitions for table saHpiSensorThdLowMinorTable
 */
#define COLUMN_SAHPISENSORTHDLOWMINORISREADABLE 1
#define COLUMN_SAHPISENSORTHDLOWMINORISWRITABLE 2
#define COLUMN_SAHPISENSORTHDLOWMINORTYPE 3
#define COLUMN_SAHPISENSORTHDLOWMINORVALUE 4
#define COLUMN_SAHPISENSORTHDLOWMINORNONLINEAR 5
#define saHpiSensorThdLowMinorTable_COL_MIN 1
#define saHpiSensorThdLowMinorTable_COL_MAX 5

/* comment out the following line if you don't handle SET-REQUEST for saHpiSensorThdLowMinorTable */
#define saHpiSensorThdLowMinorTable_SET_HANDLING

/* comment out the following line if you can't create new rows */
#define saHpiSensorThdLowMinorTable_ROW_CREATION

/* comment out the following line if you don't want the secondary index */
#define saHpiSensorThdLowMinorTable_IDX2

/* uncommend the following line if you allow modifications to an
 * active row */
/** define saHpiSensorThdLowMinorTable_CAN_MODIFY_ACTIVE_ROW */

#ifdef saHpiSensorThdLowMinorTable_SET_HANDLING

int saHpiSensorThdLowMinorTable_extract_index( saHpiSensorThdLowMinorTable_context * ctx, netsnmp_index * hdr );

void saHpiSensorThdLowMinorTable_set_reserve1( netsnmp_request_group * );
void saHpiSensorThdLowMinorTable_set_reserve2( netsnmp_request_group * );
void saHpiSensorThdLowMinorTable_set_action( netsnmp_request_group * );
void saHpiSensorThdLowMinorTable_set_commit( netsnmp_request_group * );
void saHpiSensorThdLowMinorTable_set_free( netsnmp_request_group * );
void saHpiSensorThdLowMinorTable_set_undo( netsnmp_request_group * );

saHpiSensorThdLowMinorTable_context * saHpiSensorThdLowMinorTable_duplicate_row( saHpiSensorThdLowMinorTable_context* );
netsnmp_index * saHpiSensorThdLowMinorTable_delete_row( saHpiSensorThdLowMinorTable_context* );

int saHpiSensorThdLowMinorTable_can_activate(saHpiSensorThdLowMinorTable_context *undo_ctx,
                      saHpiSensorThdLowMinorTable_context *row_ctx,
                      netsnmp_request_group * rg);
int saHpiSensorThdLowMinorTable_can_deactivate(saHpiSensorThdLowMinorTable_context *undo_ctx,
                        saHpiSensorThdLowMinorTable_context *row_ctx,
                        netsnmp_request_group * rg);
int saHpiSensorThdLowMinorTable_can_delete(saHpiSensorThdLowMinorTable_context *undo_ctx,
                    saHpiSensorThdLowMinorTable_context *row_ctx,
                    netsnmp_request_group * rg);
    
    
#ifdef saHpiSensorThdLowMinorTable_ROW_CREATION
saHpiSensorThdLowMinorTable_context * saHpiSensorThdLowMinorTable_create_row( netsnmp_index* );
#endif
#endif

#ifdef saHpiSensorThdLowMinorTable_IDX2
saHpiSensorThdLowMinorTable_context * saHpiSensorThdLowMinorTable_get( const char *name, int len );
#endif

#ifdef __cplusplus
};
#endif

#endif /** SAHPISENSORTHDLOWMINORTABLE_H */