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
#ifndef SAHPISENSORTHDUPMINORTABLE_H
#define SAHPISENSORTHDUPMINORTABLE_H

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

  typedef struct saHpiSensorThdUpMinorTable_context_s
  {
    netsnmp_index index;

    /** TruthValue = ASN_INTEGER */
    long            saHpiSensorThdUpMinorIsReadable;
    
    /** TruthValue = ASN_INTEGER */
    long            saHpiSensorThdUpMinorIsWritable;
    
    /** TruthValue = ASN_INTEGER */
    long            saHpiSensorThdUpMinorIsFixed;
    
    /** INTEGER = ASN_INTEGER */
    long            saHpiSensorThdUpMinorValuesPresent;

    /** UNSIGNED32 = ASN_UNSIGNED */
    unsigned long   saHpiSensorThdUpMinorRaw;

	/** OCTETSTR = ASN_OCTET_STR */
    unsigned char
      saHpiSensorThdUpMinorInterpreted[SENSOR_THD_INTER_MAX];
    size_t saHpiSensorThdUpMinorInterpreted_len;



    long sensor_id;
    long resource_id;
    long domain_id;
    long hash;


  } saHpiSensorThdUpMinorTable_context;

/*************************************************************
 * function declarations
 */

  void initialize_table_saHpiSensorThdUpMinorTable (void);

  int
    delete_ThdUpMinor_row (SaHpiDomainIdT domain_id,
			       SaHpiResourceIdT resource_id,
			       SaHpiSensorNumT num);

  int populate_ThdUpMinor (SaHpiDomainIdT domain_id,
			       SaHpiResourceIdT resource_id,
			       SaHpiSensorNumT sensor_id,
			       SaHpiSensorThdDefnT *threshold_def,
			       SaHpiSensorReadingT * reading);


  int set_ThdUpMinor (saHpiSensorThdUpMinorTable_context *ctx);

  int
    saHpiSensorThdUpMinorTable_get_value (netsnmp_request_info *,
					      netsnmp_index *,
					      netsnmp_table_request_info *);


/*************************************************************
 * oid declarations
 */
  extern oid saHpiSensorThdUpMinorTable_oid[];
  extern size_t saHpiSensorThdUpMinorTable_oid_len;

#define saHpiSensorThdUpMinorTable_TABLE_OID hpiSensor_OID,13

/*************************************************************
 * column number definitions for table saHpiSensorThdUpMinorTable
 */
#define COLUMN_SAHPISENSORTHDUPMINORISREADABLE 1
#define COLUMN_SAHPISENSORTHDUPMINORISWRITABLE 2
#define COLUMN_SAHPISENSORTHDUPMINORISFIXED 3
#define COLUMN_SAHPISENSORTHDUPMINORVALUESPRESENT 4
#define COLUMN_SAHPISENSORTHDUPMINORRAW 5
#define COLUMN_SAHPISENSORTHDUPMINORINTERPRETED 6
#define saHpiSensorThdUpMinorTable_COL_MIN 1
#define saHpiSensorThdUpMinorTable_COL_MAX 6

  int
    saHpiSensorThdUpMinorTable_extract_index
    (saHpiSensorThdUpMinorTable_context * ctx, netsnmp_index * hdr);

  void saHpiSensorThdUpMinorTable_set_reserve1 (netsnmp_request_group *);
  void saHpiSensorThdUpMinorTable_set_reserve2 (netsnmp_request_group *);
  void saHpiSensorThdUpMinorTable_set_action (netsnmp_request_group *);
  void saHpiSensorThdUpMinorTable_set_commit (netsnmp_request_group *);
  void saHpiSensorThdUpMinorTable_set_free (netsnmp_request_group *);
  void saHpiSensorThdUpMinorTable_set_undo (netsnmp_request_group *);

    saHpiSensorThdUpMinorTable_context
    * saHpiSensorThdUpMinorTable_duplicate_row
    (saHpiSensorThdUpMinorTable_context *);
    netsnmp_index
    * saHpiSensorThdUpMinorTable_delete_row
    (saHpiSensorThdUpMinorTable_context *);

  int
    saHpiSensorThdUpMinorTable_can_delete
    (saHpiSensorThdUpMinorTable_context * undo_ctx,
     saHpiSensorThdUpMinorTable_context * row_ctx,
     netsnmp_request_group * rg);



    saHpiSensorThdUpMinorTable_context
    * saHpiSensorThdUpMinorTable_create_row (netsnmp_index *);

#ifdef __cplusplus
};
#endif

#endif /** SAHPISENSORTHDUPMINORTABLE_H */