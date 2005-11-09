/*
 * (C) Copyright IBM Corp. 2005
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  This
 * file and program are licensed under a BSD style license.  See
 * the Copying file included with the OpenHPI distribution for
 * full licensing terms.
 *
 * Authors:
 *   David Judkovics  <djudkovi@us.ibm.com>
 *   Daniel de Araujo <ddearauj@us.ibm.com>
 *
 * Note: this file originally auto-generated by mib2c using
 *        : mib2c.array-user.conf,v 5.18.2.2 2004/02/09 18:21:47 rstory Exp $
 *
 * $Id$
 *
 * Yes, there is lots of code here that you might not use. But it is much
 * easier to remove code than to add it!
 */
#ifndef SAHPIRESOURCEEVENTTABLE_H
#define SAHPIRESOURCEEVENTTABLE_H

#ifdef __cplusplus
extern "C" {
#endif

    
#include <net-snmp/net-snmp-config.h>
#include <net-snmp/library/container.h>
#include <net-snmp/agent/table_array.h>

#include <hpiSubagent.h>
        /** Index saHpiDomainId is external */
        /** Index saHpiResourceId is external */
        /** Index saHpiEventSeverity is external */
        /** Index saHpiResourceEventEntryId is internal */

typedef struct saHpiResourceEventTable_context_s {
    netsnmp_index index; /** THIS MUST BE FIRST!!! */

    /*************************************************************
     * You can store data internally in this structure.
     *
     * TODO: You will probably have to fix a few types here...
     */
    /** TODO: add storage for external index(s)! */
        /** SaHpiEntryId = ASN_UNSIGNED */
            unsigned long saHpiResourceEventEntryId;

        /** SaHpiTime = ASN_OCTET_STR */
            unsigned char saHpiResourceEventTimestamp[SAF_UNSIGNED_64_LEN];
	    long saHpiResourceEventTimestamp_len;

        /** INTEGER = ASN_INTEGER */
            long saHpiResourceEventType;


    /*
     * OR
     *
     * Keep a pointer to your data
     */
    void * data;

    /*
     *add anything else you want here
     */

} saHpiResourceEventTable_context;

/*************************************************************
 * function declarations
 */
void init_saHpiResourceEventTable(void);
void initialize_table_saHpiResourceEventTable(void);
const saHpiResourceEventTable_context * saHpiResourceEventTable_get_by_idx(netsnmp_index *);
const saHpiResourceEventTable_context * saHpiResourceEventTable_get_by_idx_rs(netsnmp_index *,
                                        int row_status);
int saHpiResourceEventTable_get_value(netsnmp_request_info *, netsnmp_index *, netsnmp_table_request_info *);

/*************************************************************
 * function declarations
 */
SaErrorT populate_saHpiResourceEventTable(SaHpiSessionIdT sessionid, 
                                          SaHpiEventT *event,
                                          oid * event_oid, 
                                          size_t *event_oid_len);

SaErrorT async_resource_event_add(SaHpiSessionIdT sessionid,
                                  SaHpiEventT *event,
		                  SaHpiRdrT *rdr,
		                  SaHpiRptEntryT *rpt_entry,				  
                                  oid * this_child_oid, 
                                  size_t *this_child_oid_len);

/*************************************************************
 * oid declarations
 */
extern oid saHpiResourceEventTable_oid[];
extern size_t saHpiResourceEventTable_oid_len;

#define saHpiResourceEventTable_TABLE_OID 1,3,6,1,4,1,18568,2,1,1,3,1,6
    
/*************************************************************
 * column number definitions for table saHpiResourceEventTable
 */
#define RESOURCE_EVENT_INDEX_NR 4
#define COLUMN_SAHPIRESOURCEEVENTENTRYID 1
#define COLUMN_SAHPIRESOURCEEVENTTIMESTAMP 2
#define COLUMN_SAHPIRESOURCEEVENTTYPE 3
#define saHpiResourceEventTable_COL_MIN 2
#define saHpiResourceEventTable_COL_MAX 3

/* comment out the following line if you don't handle SET-REQUEST for saHpiResourceEventTable */
#define saHpiResourceEventTable_SET_HANDLING

/* comment out the following line if you can't create new rows */
#define saHpiResourceEventTable_ROW_CREATION

/* comment out the following line if you don't want the secondary index */
#define saHpiResourceEventTable_IDX2

/* uncommend the following line if you allow modifications to an
 * active row */
/** define saHpiResourceEventTable_CAN_MODIFY_ACTIVE_ROW */

#ifdef saHpiResourceEventTable_SET_HANDLING

int saHpiResourceEventTable_extract_index( saHpiResourceEventTable_context * ctx, netsnmp_index * hdr );

void saHpiResourceEventTable_set_reserve1( netsnmp_request_group * );
void saHpiResourceEventTable_set_reserve2( netsnmp_request_group * );
void saHpiResourceEventTable_set_action( netsnmp_request_group * );
void saHpiResourceEventTable_set_commit( netsnmp_request_group * );
void saHpiResourceEventTable_set_free( netsnmp_request_group * );
void saHpiResourceEventTable_set_undo( netsnmp_request_group * );

saHpiResourceEventTable_context * saHpiResourceEventTable_duplicate_row( saHpiResourceEventTable_context* );
netsnmp_index * saHpiResourceEventTable_delete_row( saHpiResourceEventTable_context* );

int saHpiResourceEventTable_can_activate(saHpiResourceEventTable_context *undo_ctx,
                      saHpiResourceEventTable_context *row_ctx,
                      netsnmp_request_group * rg);
int saHpiResourceEventTable_can_deactivate(saHpiResourceEventTable_context *undo_ctx,
                        saHpiResourceEventTable_context *row_ctx,
                        netsnmp_request_group * rg);
int saHpiResourceEventTable_can_delete(saHpiResourceEventTable_context *undo_ctx,
                    saHpiResourceEventTable_context *row_ctx,
                    netsnmp_request_group * rg);
    
    
#ifdef saHpiResourceEventTable_ROW_CREATION
saHpiResourceEventTable_context * saHpiResourceEventTable_create_row( netsnmp_index* );
#endif
#endif

#ifdef saHpiResourceEventTable_IDX2
saHpiResourceEventTable_context * saHpiResourceEventTable_get( const char *name, int len );
#endif

#ifdef __cplusplus
};
#endif

#endif /** SAHPIRESOURCEEVENTTABLE_H */
