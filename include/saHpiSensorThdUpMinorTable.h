/*
 * Note: this file originally auto-generated by mib2c using
 *        : mib2c.array-user.conf,v 5.18 2003/11/07 17:03:52 rstory Exp $
 *
 * $Id$
 *
 * Yes, there is lots of code here that you might not use. But it is much
 * easier to remove code than to add it!
 */
#ifndef SAHPISENSORTHDUPMINORTABLE_H
#define SAHPISENSORTHDUPMINORTABLE_H

#ifdef __cplusplus
extern "C" {
#endif

    
#include <net-snmp/net-snmp-config.h>
#include <net-snmp/library/container.h>
#include <net-snmp/agent/table_array.h>

        /** Index saHpiDomainId is external */
        /** Index saHpiResourceId is external */
        /** Index saHpiSensorNum is external */

typedef struct saHpiSensorThdUpMinorTable_context_s {
    netsnmp_index index; /** THIS MUST BE FIRST!!! */

    /*************************************************************
     * You can store data internally in this structure.
     *
     * TODO: You will probably have to fix a few types here...
     */
    /** TODO: add storage for external index(s)! */
        /** TruthValue = ASN_INTEGER */
            long saHpiSensorThdUpMinorIsReadable;

        /** TruthValue = ASN_INTEGER */
            long saHpiSensorThdUpMinorIsWritable;

        /** SaHpiSensorReadingType = ASN_INTEGER */
            long saHpiSensorThdUpMinorType;

        /** SaHpiSensorReadingValue = ASN_OCTET_STR */
            unsigned char saHpiSensorThdUpMinorValue[65535];
            long saHpiSensorThdUpMinorValue_len;


    /*
     * OR
     *
     * Keep a pointer to your data
     */
    void * data;

    /*
     *add anything else you want here
     */

} saHpiSensorThdUpMinorTable_context;

/*************************************************************
 * function declarations
 */
void init_saHpiSensorThdUpMinorTable(void);
void initialize_table_saHpiSensorThdUpMinorTable(void);
const saHpiSensorThdUpMinorTable_context * saHpiSensorThdUpMinorTable_get_by_idx(netsnmp_index *);
const saHpiSensorThdUpMinorTable_context * saHpiSensorThdUpMinorTable_get_by_idx_rs(netsnmp_index *,
                                        int row_status);
int saHpiSensorThdUpMinorTable_get_value(netsnmp_request_info *, netsnmp_index *, netsnmp_table_request_info *);


/*************************************************************
 * oid declarations
 */
extern oid saHpiSensorThdUpMinorTable_oid[];
extern size_t saHpiSensorThdUpMinorTable_oid_len;

#define saHpiSensorThdUpMinorTable_TABLE_OID 1,3,6,1,4,1,18568,1,1,1,6,3,7,12
    
/*************************************************************
 * column number definitions for table saHpiSensorThdUpMinorTable
 */
#define COLUMN_SAHPISENSORTHDUPMINORISREADABLE 1
#define COLUMN_SAHPISENSORTHDUPMINORISWRITABLE 2
#define COLUMN_SAHPISENSORTHDUPMINORTYPE 3
#define COLUMN_SAHPISENSORTHDUPMINORVALUE 4
#define saHpiSensorThdUpMinorTable_COL_MIN 1
#define saHpiSensorThdUpMinorTable_COL_MAX 4

/* comment out the following line if you don't handle SET-REQUEST for saHpiSensorThdUpMinorTable */
#define saHpiSensorThdUpMinorTable_SET_HANDLING

/* comment out the following line if you can't create new rows */
#define saHpiSensorThdUpMinorTable_ROW_CREATION

/* comment out the following line if you don't want the secondary index */
#define saHpiSensorThdUpMinorTable_IDX2

/* uncommend the following line if you allow modifications to an
 * active row */
/** define saHpiSensorThdUpMinorTable_CAN_MODIFY_ACTIVE_ROW */

#ifdef saHpiSensorThdUpMinorTable_SET_HANDLING

int saHpiSensorThdUpMinorTable_extract_index( saHpiSensorThdUpMinorTable_context * ctx, netsnmp_index * hdr );

void saHpiSensorThdUpMinorTable_set_reserve1( netsnmp_request_group * );
void saHpiSensorThdUpMinorTable_set_reserve2( netsnmp_request_group * );
void saHpiSensorThdUpMinorTable_set_action( netsnmp_request_group * );
void saHpiSensorThdUpMinorTable_set_commit( netsnmp_request_group * );
void saHpiSensorThdUpMinorTable_set_free( netsnmp_request_group * );
void saHpiSensorThdUpMinorTable_set_undo( netsnmp_request_group * );

saHpiSensorThdUpMinorTable_context * saHpiSensorThdUpMinorTable_duplicate_row( saHpiSensorThdUpMinorTable_context* );
netsnmp_index * saHpiSensorThdUpMinorTable_delete_row( saHpiSensorThdUpMinorTable_context* );

int saHpiSensorThdUpMinorTable_can_activate(saHpiSensorThdUpMinorTable_context *undo_ctx,
                      saHpiSensorThdUpMinorTable_context *row_ctx,
                      netsnmp_request_group * rg);
int saHpiSensorThdUpMinorTable_can_deactivate(saHpiSensorThdUpMinorTable_context *undo_ctx,
                        saHpiSensorThdUpMinorTable_context *row_ctx,
                        netsnmp_request_group * rg);
int saHpiSensorThdUpMinorTable_can_delete(saHpiSensorThdUpMinorTable_context *undo_ctx,
                    saHpiSensorThdUpMinorTable_context *row_ctx,
                    netsnmp_request_group * rg);
    
    
#ifdef saHpiSensorThdUpMinorTable_ROW_CREATION
saHpiSensorThdUpMinorTable_context * saHpiSensorThdUpMinorTable_create_row( netsnmp_index* );
#endif
#endif

#ifdef saHpiSensorThdUpMinorTable_IDX2
saHpiSensorThdUpMinorTable_context * saHpiSensorThdUpMinorTable_get( const char *name, int len );
#endif

#ifdef __cplusplus
};
#endif

#endif /** SAHPISENSORTHDUPMINORTABLE_H */
