/*
 * (C) Copyright IBM Corp. 2004
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  This
 * file and program are licensed under a BSD style license.  See
 * the Copying file included with the OpenHPI distribution for
 * full licensing terms.
 *
 * Authors:
 *   Konrad Rzeszutek <konradr@us.ibm.com>

 * Note: this file originally auto-generated by mib2c using
 *        : mib2c.array-user.conf,v 5.18 2003/11/07 17:03:52 rstory Exp $
 *
 * $Id$
 *
 */
#ifndef SAHPISENSORTHDLOWMAJORTABLE_H
#define SAHPISENSORTHDLOWMAJORTABLE_H

#ifdef __cplusplus
extern "C"
{
#endif


#include <net-snmp/net-snmp-config.h>
#include <net-snmp/library/container.h>
#include <net-snmp/agent/table_array.h>
#include <SaHpi.h>
#include <hpiSubagent.h>


	/** Index saHpiDomainID is external */
	/** Index saHpiResourceID is external */
	/** Index saHpiSensorIndex is external */

  typedef struct saHpiSensorThdLowMajorTable_context_s
  {
    netsnmp_index index;

    /** TruthValue = ASN_INTEGER */
    long            saHpiSensorThdLowMajorIsReadable;
    
    /** TruthValue = ASN_INTEGER */
    long            saHpiSensorThdLowMajorIsWritable;
    
    /** TruthValue = ASN_INTEGER */
    long            saHpiSensorThdLowMajorIsFixed;
    
    /** INTEGER = ASN_INTEGER */
    long            saHpiSensorThdLowMajorValuesPresent;

    /** UNSIGNED32 = ASN_UNSIGNED */
    unsigned long   saHpiSensorThdLowMajorRaw;

	/** OCTETSTR = ASN_OCTET_STR */
    unsigned char
      saHpiSensorThdLowMajorInterpreted[SENSOR_THD_INTER_MAX];
    size_t saHpiSensorThdLowMajorInterpreted_len;



    long sensor_id;
    long resource_id;
    long domain_id;
    long hash;


  } saHpiSensorThdLowMajorTable_context;

/*************************************************************
 * function declarations
 */

  void initialize_table_saHpiSensorThdLowMajorTable (void);

  int
    delete_ThdLowMajor_row (SaHpiDomainIdT domain_id,
			       SaHpiResourceIdT resource_id,
			       SaHpiSensorNumT num);

  int populate_ThdLowMajor (SaHpiDomainIdT domain_id,
			       SaHpiResourceIdT resource_id,
			       SaHpiSensorNumT sensor_id,
			       SaHpiSensorThdDefnT *threshold_def,
			       SaHpiSensorReadingT * reading);


  int set_ThdLowMajor (saHpiSensorThdLowMajorTable_context *ctx);

  int
    saHpiSensorThdLowMajorTable_get_value (netsnmp_request_info *,
					      netsnmp_index *,
					      netsnmp_table_request_info *);


/*************************************************************
 * oid declarations
 */
  extern oid saHpiSensorThdLowMajorTable_oid[];
  extern size_t saHpiSensorThdLowMajorTable_oid_len;

#define saHpiSensorThdLowMajorTable_TABLE_OID hpiSensor_OID,8

/*************************************************************
 * column number definitions for table saHpiSensorThdLowMajorTable
 */
#define COLUMN_SAHPISENSORTHDLOWMAJORISREADABLE 1
#define COLUMN_SAHPISENSORTHDLOWMAJORISWRITABLE 2
#define COLUMN_SAHPISENSORTHDLOWMAJORISFIXED 3
#define COLUMN_SAHPISENSORTHDLOWMAJORVALUESPRESENT 4
#define COLUMN_SAHPISENSORTHDLOWMAJORRAW 5
#define COLUMN_SAHPISENSORTHDLOWMAJORINTERPRETED 6
#define saHpiSensorThdLowMajorTable_COL_MIN 1
#define saHpiSensorThdLowMajorTable_COL_MAX 6

  int
    saHpiSensorThdLowMajorTable_extract_index
    (saHpiSensorThdLowMajorTable_context * ctx, netsnmp_index * hdr);

  void saHpiSensorThdLowMajorTable_set_reserve1 (netsnmp_request_group *);
  void saHpiSensorThdLowMajorTable_set_reserve2 (netsnmp_request_group *);
  void saHpiSensorThdLowMajorTable_set_action (netsnmp_request_group *);
  void saHpiSensorThdLowMajorTable_set_commit (netsnmp_request_group *);
  void saHpiSensorThdLowMajorTable_set_free (netsnmp_request_group *);
  void saHpiSensorThdLowMajorTable_set_undo (netsnmp_request_group *);

    saHpiSensorThdLowMajorTable_context
    * saHpiSensorThdLowMajorTable_duplicate_row
    (saHpiSensorThdLowMajorTable_context *);
    netsnmp_index
    * saHpiSensorThdLowMajorTable_delete_row
    (saHpiSensorThdLowMajorTable_context *);

  int
    saHpiSensorThdLowMajorTable_can_delete
    (saHpiSensorThdLowMajorTable_context * undo_ctx,
     saHpiSensorThdLowMajorTable_context * row_ctx,
     netsnmp_request_group * rg);



    saHpiSensorThdLowMajorTable_context
    * saHpiSensorThdLowMajorTable_create_row (netsnmp_index *);

#ifdef __cplusplus
};
#endif

#endif /** SAHPISENSORTHDLOWMAJORTABLE_H */
