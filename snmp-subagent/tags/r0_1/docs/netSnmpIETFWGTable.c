/*
 * Note: this file originally auto-generated by mib2c using
 *       : mib2c.array-user.conf,v 5.15.2.1 2003/02/27 05:59:41 rstory Exp $
 *
 * $Id$
 *
 *
 * For help understanding NET-SNMP in general, please check the 
 *     documentation and FAQ at:
 *
 *     http://www.net-snmp.org/
 *
 *
 * For help understanding this code, the agent and how it processes
 *     requests, please check the following references.
 *
 *     http://www.net-snmp.org/tutorial/
 *
 *
 * You can also join the #net-snmp channel on irc.openprojects.net
 *     and ask for help there.
 *
 *
 * And if all else fails, send a detailed message to the developers
 *     describing the problem you are having to:
 *
 *    net-snmp-coders@lists.sourceforge.net
 *
 *
 * Yes, there is lots of code here that you might not use. But it is much
 * easier to remove code than to add it!
 */
#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>

#include <net-snmp/library/snmp_assert.h>

#include "netSnmpIETFWGTable.h"

#define AGENT "**** (KONRAD): "
static int number = 1;

static netsnmp_handler_registration *my_handler = NULL;
static netsnmp_table_array_callbacks cb;

oid             netSnmpIETFWGTable_oid[] =
    { netSnmpIETFWGTable_TABLE_OID };
size_t          netSnmpIETFWGTable_oid_len =
OID_LENGTH(netSnmpIETFWGTable_oid);


#ifdef netSnmpIETFWGTable_IDX2
/************************************************************
 * keep binary tree to find context by name
 */
static int      netSnmpIETFWGTable_cmp(const void *lhs, const void *rhs);

/************************************************************
 * compare two context pointers here. Return -1 if lhs < rhs,
 * 0 if lhs == rhs, and 1 if lhs > rhs.
 */
static int
netSnmpIETFWGTable_cmp(const void *lhs, const void *rhs)
{
    netSnmpIETFWGTable_context *context_l =
        (netSnmpIETFWGTable_context *) lhs;
    netSnmpIETFWGTable_context *context_r =
        (netSnmpIETFWGTable_context *) rhs;

	DEBUGMSGTL((AGENT,"netSnmpIETFWGTable_cmp"));
    /*
     * check primary key, then secondary. Add your own code if
     * there are more than 2 indexes
     */
    int             rc;

    /*
     * TODO: implement compare. Remove this ifdef code and
     * add your own code here.
     */
     rc = strcmp( context_l->nsIETFWGName, context_r->nsIETFWGName);
    return rc;
    /*
     * EXAMPLE:
     *   
     * rc = strcmp( context_l->xxName, context_r->xxName);
     *
     * if(rc)
     *   return rc;
     *
     * TODO: fix secondary keys (or delete if there are none)
     *
     * if(context_l->yy < context_r->yy) 
     *   return -1;
     *
     * return (context_l->yy == context_r->yy) ? 0 : 1;
     */
}

/************************************************************
 * search tree
 */
/** TODO: set additional indexes as parameters */
netSnmpIETFWGTable_context *
netSnmpIETFWGTable_get(const char *name, int len)
{
    netSnmpIETFWGTable_context tmp;
	DEBUGMSGTL((AGENT,"netSnmpIETFWGTable_get"));
    /** we should have a secondary index */
    netsnmp_assert(cb.container->next != NULL);

    /*
     * TODO: implement compare. Remove this ifdef code and
     * add your own code here.
     */
#ifdef TABLE_CONTAINER_TODO
    snmp_log(LOG_ERR, "netSnmpIETFWGTable_get not implemented!\n");
    return NULL;
#endif

    //if (len > sizeof(tmp.
    /*
     * EXAMPLE:
     *
     * if(len > sizeof(tmp.xxName))
     *   return NULL;
     *
     * strncpy( tmp.xxName, name, sizeof(tmp.xxName) );
     * tmp.xxName_len = len;
     *
     * return CONTAINER_FIND(cb.container->next, &tmp);
     */
}
#endif


	static oid my_oid[] = 
	{1,3,6,1,4,1,8072,2,2,1.};

/************************************************************
 * Initializes the netSnmpIETFWGTable module
 */
void
init_netSnmpIETFWGTable(void)
{
	netsnmp_index *index;
	netSnmpIETFWGTable_context *x;
	oid tmp[33];

    initialize_table_netSnmpIETFWGTable();

    /*
     * TODO: perform any startup stuff here
     */

	index = SNMP_MALLOC_TYPEDEF(netsnmp_index);
	tmp[0]=3; tmp[1]='A'; tmp[2] ='B'; tmp[3] ='C';

	index->oids = tmp;
	index->len = 4;

	x = netSnmpIETFWGTable_create_row(index);

	CONTAINER_INSERT(cb.container, x);     
	tmp[3]='D';
	DEBUGMSGTL((AGENT,"TMP: %s", tmp));
	x = netSnmpIETFWGTable_create_row(index);
	CONTAINER_INSERT(cb.container, x);
	free(index); index=NULL;
	//free(x); x=NULL;
/*
	snmp_alarm_register(2,
				SA_REPEAT,
				send_notification,
				index);
	snmp_alarm_register(5,
			SA_REPEAT,
			create_,
			NULL);
*/
	snmp_alarm_register(10,
			SA_REPEAT,
			delete_,
			NULL);
	// Do we dealloc x?
}

/************************************************************
 * the *_row_copy routine
 */
static int
netSnmpIETFWGTable_row_copy(netSnmpIETFWGTable_context * dst,
                            netSnmpIETFWGTable_context * src)
{
	DEBUGMSGTL((AGENT,"netSnmpIETFWGTable_row_copy"));
    if (!dst || !src)
        return 1;

    /*
     * copy index, if provided
     */
    if (dst->index.oids)
        free(dst->index.oids);
    if (snmp_clone_mem((void *) &dst->index.oids, src->index.oids,
                       src->index.len * sizeof(oid))) {
        dst->index.oids = NULL;
        return 1;
    }
    dst->index.len = src->index.len;


    /*
     * copy components into the context structure
     */
    memcpy(dst->nsIETFWGName, src->nsIETFWGName, src->nsIETFWGName_len);
    dst->nsIETFWGName_len = src->nsIETFWGName_len;

    memcpy(dst->nsIETFWGChair1, src->nsIETFWGChair1,
           src->nsIETFWGChair1_len);
    dst->nsIETFWGChair1_len = src->nsIETFWGChair1_len;

    memcpy(dst->nsIETFWGChair2, src->nsIETFWGChair2,
           src->nsIETFWGChair2_len);
    dst->nsIETFWGChair2_len = src->nsIETFWGChair2_len;

    return 0;
}

#ifdef netSnmpIETFWGTable_SET_HANDLING

/*
 * the *_extract_index routine
 */
int
netSnmpIETFWGTable_extract_index(netSnmpIETFWGTable_context * ctx,
                                 netsnmp_index * hdr)
{
	DEBUGMSGTL((AGENT,"netSnmpIETFWGTable_extract_index"));
    /*
     * temporary local storage for extracting oid index
     */
    netsnmp_variable_list var_nsIETFWGName;
    int             err;
    oid			tmp[MAX_OID_LEN];
    int			tmpl;
    /*
     * copy index, if provided
     */
    if (hdr) {
        netsnmp_assert(ctx->index.oids == NULL);
        if (snmp_clone_mem((void *) &ctx->index.oids, hdr->oids,
                           hdr->len * sizeof(oid))) {
            return -1;
        }
        ctx->index.len = hdr->len;
    }

    /**
     * Create variable to hold each component of the index
     */
    memset(&var_nsIETFWGName, 0x00, sizeof(var_nsIETFWGName));
    var_nsIETFWGName.type = ASN_OCTET_STR;
    var_nsIETFWGName.next_variable = NULL;
    /*
    var_nsIETFWGName.val.string = "ABC";
    var_nsIETFWGName.val_len =  3; 
   build_oid_noalloc(tmp, sizeof(tmp), &tmpl, my_oid, OID_LENGTH(my_oid), &var_nsIETFWGName);

   var_nsIETFWGName.name = tmp;
   var_nsIETFWGName.name_length = tmpl;
   DEBUGMSGTL((AGENT,"Build the OID: "));
   build_oid_segment(&var_nsIETFWGName);
   
   DEBUGMSGOID((AGENT, var_nsIETFWGName.name, var_nsIETFWGName.name_length));
   */
    /*
     * parse the oid into the individual components
     */
    err = parse_oid_indexes(hdr->oids, hdr->len, &var_nsIETFWGName);

    DEBUGMSGTL((AGENT,"parse_oid_indexs: %d = %d", err, SNMP_ERR_NOERROR));
    if (err == SNMP_ERR_NOERROR) {
        /*
         * copy components into the context structure
         */
        if (var_nsIETFWGName.val_len > sizeof(ctx->nsIETFWGName))
            err = -1;
        else
            memcpy(ctx->nsIETFWGName, var_nsIETFWGName.val.string,
                   var_nsIETFWGName.val_len);
        ctx->nsIETFWGName_len = var_nsIETFWGName.val_len;


        /*
         * TODO: check index for valid values. For EXAMPLE:
         *
         * if ( XXX_check_value( var_nsIETFWGName.val.string, XXX ) ) {
         *    err = -1;
         * }
         */
    }

    /*
     * parsing may have allocated memory. free it.
     */
    snmp_reset_var_buffers(&var_nsIETFWGName);

    return err;
}

/************************************************************
 * the *_can_delete routine is called to determine if a row
 * can be deleted.
 *
 * return 1 if the row can be deleted
 * return 0 if the row cannot be deleted
 */
int
netSnmpIETFWGTable_can_delete(netSnmpIETFWGTable_context * undo_ctx,
                              netSnmpIETFWGTable_context * row_ctx,
                              netsnmp_request_group * rg)
{
	DEBUGMSGTL((AGENT,"netSnmpIETFWGTable_can_delete"));
    /*
     * TODO: check for other deletion requirements here
     */
    return 1;
}

/************************************************************
 * the *_create_row routine is called by the table handler
 * to create a new row for a given index. If you need more
 * information (such as column values) to make a decision
 * on creating rows, you must create an initial row here
 * (to hold the column values), and you can examine the
 * situation in more detail in the *_set_reserve1 or later
 * states of set processing. Simple check for a NULL undo_ctx
 * in those states and do detailed creation checking there.
 *
 * returns a newly allocated netSnmpIETFWGTable_context
 *   structure if the specified indexes are not illegal
 * returns NULL for errors or illegal index values.
 */
netSnmpIETFWGTable_context *
netSnmpIETFWGTable_create_row(netsnmp_index * hdr)
{
    netSnmpIETFWGTable_context *ctx =
        SNMP_MALLOC_TYPEDEF(netSnmpIETFWGTable_context);

    unsigned char chair[4] = "TEST";
    unsigned char chair2[5] = "TEST2";

	DEBUGMSGTL((AGENT,"netSnmpIETFWGTable_create_row"));
    if (!ctx)
        return NULL;

    /*
     * TODO: check indexes, if necessary.
     */
    if (netSnmpIETFWGTable_extract_index(ctx, hdr)) {
        free(ctx->index.oids);
        free(ctx);
        return NULL;
    }

    /*
     * netsnmp_mutex_init(ctx->lock);
     * netsnmp_mutex_lock(ctx->lock); 
     */

    /*
     * TODO: initialize any default values here. This is also
     * first place you really should allocate any memory for
     * yourself to use.  If you allocated memory earlier,
     * make sure you free it for earlier error cases!
     */
     DEBUGMSGTL((AGENT,"index: %s ",ctx->nsIETFWGName));
     strncpy(ctx->nsIETFWGChair1, chair, 4);
     ctx->nsIETFWGChair1_len = 4;
     strncpy(ctx->nsIETFWGChair2 , chair2, 5);
     ctx->nsIETFWGChair2_len = 5;

    return ctx;
}

/************************************************************
 * the *_duplicate row routine
 */
netSnmpIETFWGTable_context *
netSnmpIETFWGTable_duplicate_row(netSnmpIETFWGTable_context * row_ctx)
{
    netSnmpIETFWGTable_context *dup;
	DEBUGMSGTL((AGENT,"netSnmpIETFWGTable_duplicate_row"));
    if (!row_ctx)
        return NULL;

    dup = SNMP_MALLOC_TYPEDEF(netSnmpIETFWGTable_context);
    if (!dup)
        return NULL;

    if (netSnmpIETFWGTable_row_copy(dup, row_ctx)) {
        free(dup);
        dup = NULL;
    }

    return dup;
}

/************************************************************
 * the *_delete_row method is called to delete a row.
 */
netsnmp_index  *
netSnmpIETFWGTable_delete_row(netSnmpIETFWGTable_context * ctx)
{
    /*
     * netsnmp_mutex_destroy(ctx->lock); 
     */
	DEBUGMSGTL((AGENT,"netSnmpIETFWGTable_delete_row"));
    if (ctx->index.oids)
        free(ctx->index.oids);

    /*
     * TODO: release any memory you allocated here...
     */

    /*
     * release header
     */
    free(ctx);

    return NULL;
}


/************************************************************
 * RESERVE is used to check the syntax of all the variables
 * provided, that the values being set are sensible and consistent,
 * and to allocate any resources required for performing the SET.
 * After this stage, the expectation is that the set ought to
 * succeed, though this is not guaranteed. (In fact, with the UCD
 * agent, this is done in two passes - RESERVE1, and
 * RESERVE2, to allow for dependancies between variables).
 *
 * BEFORE calling this routine, the agent will call duplicate_row
 * to create a copy of the row (unless this is a new row; i.e.
 * row_created == 1).
 *
 * next state -> SET_RESERVE2 || SET_FREE
 */
void
netSnmpIETFWGTable_set_reserve1(netsnmp_request_group * rg)
{
    netSnmpIETFWGTable_context *row_ctx =
        (netSnmpIETFWGTable_context *) rg->existing_row;
    netSnmpIETFWGTable_context *undo_ctx =
        (netSnmpIETFWGTable_context *) rg->undo_info;

    netsnmp_variable_list *var;
    netsnmp_request_group_item *current;
    int             rc;

	DEBUGMSGTL((AGENT,"netSnmpIETFWGTable_set_reserve1"));
    /*
     * TODO: loop through columns, check syntax and lengths. For
     * columns which have no dependencies, you could also move
     * the value/range checking here to attempt to catch error
     * cases as early as possible.
     */
    for (current = rg->list; current; current = current->next) {

        var = current->ri->requestvb;
        rc = SNMP_ERR_NOERROR;
	DEBUGMSGTL((AGENT,"Length of char1: %d ", sizeof(row_ctx->nsIETFWGChair1)));

        switch (current->tri->colnum) {

        case COLUMN_NSIETFWGCHAIR1:
            /** OCTETSTR = ASN_OCTET_STR */
            rc = netsnmp_check_vb_type_and_size(var, ASN_OCTET_STR,
                                                sizeof(row_ctx->
                                                       nsIETFWGChair1));
            break;

        case COLUMN_NSIETFWGCHAIR2:
            /** OCTETSTR = ASN_OCTET_STR */
            rc = netsnmp_check_vb_type_and_size(var, ASN_OCTET_STR,
                                                sizeof(row_ctx->
                                                       nsIETFWGChair2));
            break;

        default:/** We shouldn't get here */
            rc = SNMP_ERR_GENERR;
            snmp_log(LOG_ERR, "unknown column in "
                     "netSnmpIETFWGTable_set_reserve1\n");
        }

		DEBUGMSGTL((AGENT,"rc: %d", rc));
		
	 if (rc == SNMP_ERR_WRONGLENGTH) 
	    	rc = SNMP_ERR_NOERROR;
         if (rc)
            netsnmp_set_mode_request_error(MODE_SET_BEGIN, current->ri, rc);

        rg->status = SNMP_MAX(rg->status, current->ri->status);
    }

    /*
     * done with all the columns. Could check row related
     * requirements here.
     */
}

void
netSnmpIETFWGTable_set_reserve2(netsnmp_request_group * rg)
{
    netSnmpIETFWGTable_context *row_ctx =
        (netSnmpIETFWGTable_context *) rg->existing_row;
    netSnmpIETFWGTable_context *undo_ctx =
        (netSnmpIETFWGTable_context *) rg->undo_info;
    netsnmp_request_group_item *current;
    netsnmp_variable_list *var;
    int             rc;
	DEBUGMSGTL((AGENT,"netSnmpIETFWGTable_set_reserve2"));
    rg->rg_void = rg->list->ri;

    /*
     * TODO: loop through columns, check for valid
     * values and any range constraints.
     */
    for (current = rg->list; current; current = current->next) {

        var = current->ri->requestvb;
        rc = SNMP_ERR_NOERROR;

        switch (current->tri->colnum) {

        case COLUMN_NSIETFWGCHAIR1:
            /** OCTETSTR = ASN_OCTET_STR */
            /*
             * TODO: routine to check valid values
             *
             * EXAMPLE:
             *
             * if ( XXX_check_value( var->val.string, XXX ) ) {
             *    rc = SNMP_ERR_INCONSISTENTVALUE;
             *    rc = SNMP_ERR_BADVALUE;
             * }
             */
            break;

        case COLUMN_NSIETFWGCHAIR2:
            /** OCTETSTR = ASN_OCTET_STR */
            /*
             * TODO: routine to check valid values
             *
             * EXAMPLE:
             *
             * if ( XXX_check_value( var->val.string, XXX ) ) {
             *    rc = SNMP_ERR_INCONSISTENTVALUE;
             *    rc = SNMP_ERR_BADVALUE;
             * }
             */
            break;

        default:/** We shouldn't get here */
            netsnmp_assert(0); /** why wasn't this caught in reserve1? */
        }

        if (rc)
            netsnmp_set_mode_request_error(MODE_SET_BEGIN, current->ri,
                                           rc);
    }

    /*
     * done with all the columns. Could check row related
     * requirements here.
     */
}

/************************************************************
 * Assuming that the RESERVE phases were successful, the next
 * stage is indicated by the action value ACTION. This is used
 * to actually implement the set operation. However, this must
 * either be done into temporary (persistent) storage, or the
 * previous value stored similarly, in case any of the subsequent
 * ACTION calls fail.
 *
 * In your case, changes should be made to row_ctx. A copy of
 * the original row is in undo_ctx.
 */
void
netSnmpIETFWGTable_set_action(netsnmp_request_group * rg)
{
    netsnmp_variable_list *var;
    netSnmpIETFWGTable_context *row_ctx =
        (netSnmpIETFWGTable_context *) rg->existing_row;
    netSnmpIETFWGTable_context *undo_ctx =
        (netSnmpIETFWGTable_context *) rg->undo_info;
    netsnmp_request_group_item *current;

	DEBUGMSGTL((AGENT,"netSnmpIETFWGTable_set_action"));
    /*
     * TODO: loop through columns, copy varbind values
     * to context structure for the row.
     */
    for (current = rg->list; current; current = current->next) {

        var = current->ri->requestvb;

        switch (current->tri->colnum) {

        case COLUMN_NSIETFWGCHAIR1:
            /** OCTETSTR = ASN_OCTET_STR */
            memcpy(row_ctx->nsIETFWGChair1, var->val.string, var->val_len);
            row_ctx->nsIETFWGChair1_len = var->val_len;
            break;

        case COLUMN_NSIETFWGCHAIR2:
            /** OCTETSTR = ASN_OCTET_STR */
            memcpy(row_ctx->nsIETFWGChair2, var->val.string, var->val_len);
            row_ctx->nsIETFWGChair2_len = var->val_len;
            break;

        default:/** We shouldn't get here */
            netsnmp_assert(0); /** why wasn't this caught in reserve1? */
        }
    }

    /*
     * done with all the columns. Could check row related
     * requirements here.
     */
    /*
     * TODO: if you have dependencies on other tables, this would be
     * a good place to check those, too.
     */
}

/************************************************************
 * Only once the ACTION phase has completed successfully, can
 * the final COMMIT phase be run. This is used to complete any
 * writes that were done into temporary storage, and then release
 * any allocated resources. Note that all the code in this phase
 * should be "safe" code that cannot possibly fail (cue
 * hysterical laughter). The whole intent of the ACTION/COMMIT
 * division is that all of the fallible code should be done in
 * the ACTION phase, so that it can be backed out if necessary.
 *
 * BEFORE calling this routine, the agent will update the
 * container (inserting a row if row_created == 1, or removing
 * the row if row_deleted == 1).
 *
 * AFTER calling this routine, the agent will delete the
 * undo_info.
 */
void
netSnmpIETFWGTable_set_commit(netsnmp_request_group * rg)
{
    netsnmp_variable_list *var;
    netSnmpIETFWGTable_context *row_ctx =
        (netSnmpIETFWGTable_context *) rg->existing_row;
    netSnmpIETFWGTable_context *undo_ctx =
        (netSnmpIETFWGTable_context *) rg->undo_info;
    netsnmp_request_group_item *current;

	DEBUGMSGTL((AGENT,"netSnmpIETFWGTable_set_commit"));
    /*
     * loop through columns
     */
    for (current = rg->list; current; current = current->next) {

        var = current->ri->requestvb;

        switch (current->tri->colnum) {

        case COLUMN_NSIETFWGCHAIR1:
            /** OCTETSTR = ASN_OCTET_STR */
            break;

        case COLUMN_NSIETFWGCHAIR2:
            /** OCTETSTR = ASN_OCTET_STR */
            break;

        default:/** We shouldn't get here */
            netsnmp_assert(0); /** why wasn't this caught in reserve1? */
        }
    }

    /*
     * done with all the columns. Could check row related
     * requirements here.
     */
}

/************************************************************
 * If either of the RESERVE calls fail, the write routines
 * are called again with the FREE action, to release any resources
 * that have been allocated. The agent will then return a failure
 * response to the requesting application.
 *
 * AFTER calling this routine, the agent will delete undo_info.
 */
void
netSnmpIETFWGTable_set_free(netsnmp_request_group * rg)
{
    netsnmp_variable_list *var;
    netSnmpIETFWGTable_context *row_ctx =
        (netSnmpIETFWGTable_context *) rg->existing_row;
    netSnmpIETFWGTable_context *undo_ctx =
        (netSnmpIETFWGTable_context *) rg->undo_info;
    netsnmp_request_group_item *current;

	DEBUGMSGTL((AGENT,"netSnmpIETFWGTable_set_free"));
    /*
     * loop through columns
     */
    for (current = rg->list; current; current = current->next) {

        var = current->ri->requestvb;

        switch (current->tri->colnum) {

        case COLUMN_NSIETFWGCHAIR1:
            /** OCTETSTR = ASN_OCTET_STR */
            break;

        case COLUMN_NSIETFWGCHAIR2:
            /** OCTETSTR = ASN_OCTET_STR */
            break;

        default:/** We shouldn't get here */
            /** should have been logged in reserve1 */
        }
    }

    /*
     * done with all the columns. Could check row related
     * requirements here.
     */
}

/************************************************************
 * If the ACTION phase does fail (for example due to an apparently
 * valid, but unacceptable value, or an unforeseen problem), then
 * the list of write routines are called again, with the UNDO
 * action. This requires the routine to reset the value that was
 * changed to its previous value (assuming it was actually changed),
 * and then to release any resources that had been allocated. As
 * with the FREE phase, the agent will then return an indication
 * of the error to the requesting application.
 *
 * BEFORE calling this routine, the agent will update the container
 * (remove any newly inserted row, re-insert any removed row).
 *
 * AFTER calling this routing, the agent will call row_copy
 * to restore the data in existing_row from the date in undo_info.
 * Then undo_info will be deleted (or existing row, if row_created
 * == 1).
 */
void
netSnmpIETFWGTable_set_undo(netsnmp_request_group * rg)
{
    netsnmp_variable_list *var;
    netSnmpIETFWGTable_context *row_ctx =
        (netSnmpIETFWGTable_context *) rg->existing_row;
    netSnmpIETFWGTable_context *undo_ctx =
        (netSnmpIETFWGTable_context *) rg->undo_info;
    netsnmp_request_group_item *current;
	DEBUGMSGTL((AGENT,"netSnmpIETFWGTable_set_undo"));
    /*
     * loop through columns
     */
    for (current = rg->list; current; current = current->next) {

        var = current->ri->requestvb;

        switch (current->tri->colnum) {

        case COLUMN_NSIETFWGCHAIR1:
            /** OCTETSTR = ASN_OCTET_STR */
            break;

        case COLUMN_NSIETFWGCHAIR2:
            /** OCTETSTR = ASN_OCTET_STR */
            break;

        default:/** We shouldn't get here */
            netsnmp_assert(0); /** why wasn't this caught in reserve1? */
        }
    }

    /*
     * done with all the columns. Could check row related
     * requirements here.
     */
}

#endif /** netSnmpIETFWGTable_SET_HANDLING */


/************************************************************
 *
 * Initialize the netSnmpIETFWGTable table by defining its contents and how it's structured
 */
void
initialize_table_netSnmpIETFWGTable(void)
{
    netsnmp_table_registration_info *table_info;

    DEBUGMSGTL((AGENT,"init"));
    if (my_handler) {
        snmp_log(LOG_ERR,
                 "initialize_table_netSnmpIETFWGTable_handler called again\n");
        return;
    }

    memset(&cb, 0x00, sizeof(cb));

    /** create the table structure itself */
    table_info = SNMP_MALLOC_TYPEDEF(netsnmp_table_registration_info);

    /*
     * if your table is read only, it's easiest to change the
     * HANDLER_CAN_RWRITE definition below to HANDLER_CAN_RONLY 
     */
    my_handler = netsnmp_create_handler_registration("netSnmpIETFWGTable",
                                                     netsnmp_table_array_helper_handler,
                                                     netSnmpIETFWGTable_oid,
                                                     netSnmpIETFWGTable_oid_len,
                                                     HANDLER_CAN_RWRITE);

    if (!my_handler || !table_info) {
        snmp_log(LOG_ERR, "malloc failed in "
                 "initialize_table_netSnmpIETFWGTable_handler\n");
        return; /** mallocs failed */
    }

    /***************************************************
     * Setting up the table's definition
     */
    /*
     * TODO: add any external indexes here.
     */

    /*
     * internal indexes
     */
        /** index: nsIETFWGName */
    netsnmp_table_helper_add_index(table_info, ASN_OCTET_STR);

    table_info->min_column = netSnmpIETFWGTable_COL_MIN;
    table_info->max_column = netSnmpIETFWGTable_COL_MAX;

    /***************************************************
     * registering the table with the master agent
     */
    cb.get_value = netSnmpIETFWGTable_get_value;
    cb.container = netsnmp_container_find("netSnmpIETFWGTable_primary:"
                                          "netSnmpIETFWGTable:"
                                          "table_container");
#ifdef netSnmpIETFWGTable_IDX2
    netsnmp_container_add_index(cb.container,
                                netsnmp_container_find
                                ("netSnmpIETFWGTable_secondary:"
                                 "netSnmpIETFWGTable:" "table_container"));
    cb.container->next->compare = netSnmpIETFWGTable_cmp;
#endif
#ifdef netSnmpIETFWGTable_SET_HANDLING
    cb.can_set = 1;
    cb.create_row = (UserRowMethod *) netSnmpIETFWGTable_create_row;
    cb.duplicate_row = (UserRowMethod *) netSnmpIETFWGTable_duplicate_row;
    cb.delete_row = (UserRowMethod *) netSnmpIETFWGTable_delete_row;
    cb.row_copy =
        (Netsnmp_User_Row_Operation *) netSnmpIETFWGTable_row_copy;

    cb.can_delete =
        (Netsnmp_User_Row_Action *) netSnmpIETFWGTable_can_delete;

    cb.set_reserve1 = netSnmpIETFWGTable_set_reserve1;
    cb.set_reserve2 = netSnmpIETFWGTable_set_reserve2;
    cb.set_action = netSnmpIETFWGTable_set_action;
    cb.set_commit = netSnmpIETFWGTable_set_commit;
    cb.set_free = netSnmpIETFWGTable_set_free;
    cb.set_undo = netSnmpIETFWGTable_set_undo;
#endif
    DEBUGMSGTL(("initialize_table_netSnmpIETFWGTable",
                "Registering table netSnmpIETFWGTable "
                "as a table array\n"));
    netsnmp_table_container_register(my_handler, table_info, &cb,
                                     cb.container, 1);
}

/************************************************************
 * netSnmpIETFWGTable_get_value
 */
int
netSnmpIETFWGTable_get_value(netsnmp_request_info *request,
                             netsnmp_index * item,
                             netsnmp_table_request_info *table_info)
{
    netsnmp_variable_list *var = request->requestvb;
    netSnmpIETFWGTable_context *context =
        (netSnmpIETFWGTable_context *) item;


	DEBUGMSGTL((AGENT,"netSnmpIETFWGTable_get_value"));

    switch (table_info->colnum) {

    case COLUMN_NSIETFWGNAME:
            /** OCTETSTR = ASN_OCTET_STR */
        snmp_set_var_typed_value(var, ASN_OCTET_STR,
                                 (char *) &context->nsIETFWGName,
                                 context->nsIETFWGName_len);
        break;

    case COLUMN_NSIETFWGCHAIR1:
            /** OCTETSTR = ASN_OCTET_STR */
        snmp_set_var_typed_value(var, ASN_OCTET_STR,
                                 (char *) &context->nsIETFWGChair1,
                                 context->nsIETFWGChair1_len);
        break;

    case COLUMN_NSIETFWGCHAIR2:
            /** OCTETSTR = ASN_OCTET_STR */
        snmp_set_var_typed_value(var, ASN_OCTET_STR,
                                 (char *) &context->nsIETFWGChair2,
                                 context->nsIETFWGChair2_len);
        break;

    default:/** We shouldn't get here */
        snmp_log(LOG_ERR, "unknown column in "
                 "netSnmpIETFWGTable_get_value\n");
        return SNMP_ERR_GENERR;
    }
    return SNMP_ERR_NOERROR;
}

/************************************************************
 * netSnmpIETFWGTable_get_by_idx
 */
const netSnmpIETFWGTable_context *
netSnmpIETFWGTable_get_by_idx(netsnmp_index * hdr)
{
	DEBUGMSGTL((AGENT,"netSnmpIETFWGTable_get_by_idx"));
    return (const netSnmpIETFWGTable_context *)
        CONTAINER_FIND(cb.container, hdr);
}

void
send_notification(unsigned int clientreg, void *clientarg) {

    /*
     * define the OID for the notification we're going to send
     * NET-SNMP-EXAMPLES-MIB::netSnmpExampleNotification 
     */
    oid             notification_oid[] =
        { 1, 3, 6, 1, 4, 1, 8072, 2, 3, 1 };
    size_t          notification_oid_len = OID_LENGTH(notification_oid);

    /*
     * In the notification, we have to assign our notification OID to
     * the snmpTrapOID.0 object. Here is it's definition. 
     */
    oid             objid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };
    size_t          objid_snmptrap_len = OID_LENGTH(objid_snmptrap);
    netsnmp_index	*index;
    oid		tmp[2];
    netSnmpIETFWGTable_context *x;

    /*
     * here is where we store the variables to be sent in the trap 
     */
    netsnmp_variable_list *notification_vars = NULL;
  
 
    DEBUGMSGTL(("example_notification", "defining the trap\n"));

    // Lets find the sucker
    index = SNMP_MALLOC_TYPEDEF(netsnmp_index);
    tmp[0] = 1;
    tmp[1] = 'a' + number;
    index->oids = tmp;
    index->len = 2;
    x = CONTAINER_FIND(cb.container, index);
    free(index);
    if (x) {
    	DEBUGMSGTL((AGENT,"Found the object! "));
	DEBUGMSGOID((AGENT,x->index.oids, x->index.len));
	snmp_varlist_add_variable(&notification_vars,
				//x->index.oids, x->index.len,
				objid_snmptrap, objid_snmptrap_len,
				ASN_OCTET_STR,
				x->nsIETFWGName,
				x->nsIETFWGName_len * sizeof(oid));
    }
    /*
     * add in the trap definition object 
     */
    snmp_varlist_add_variable(&notification_vars,
                              /*
                               * the snmpTrapOID.0 variable 
                               */
                              objid_snmptrap, objid_snmptrap_len,
                              /*
                               * value type is an OID 
                               */
                              ASN_OBJECT_ID,
                              /*
                               * value contents is our notification OID 
                               */
                              (u_char *) notification_oid,
                              /*
                               * size in bytes = oid length * sizeof(oid) 
                               */
                              notification_oid_len * sizeof(oid));

    /*
     * if we wanted to insert additional objects, we'd do it here 
     */

    /*
     * send the trap out.  This will send it to all registered
     * receivers (see the "SETTING UP TRAP AND/OR INFORM DESTINATIONS"
     * section of the snmpd.conf manual page. 
     */
    DEBUGMSGTL(("example_notification", "sending the trap\n"));
    send_v2trap(notification_vars);

    /*
     * free the created notification variable list 
     */
    DEBUGMSGTL(("example_notification", "cleaning up\n"));
    snmp_free_varbind(notification_vars);

    
}

void
create_(unsigned int clientreg, void *clientarg) {

	netsnmp_index *index;
	netSnmpIETFWGTable_context *x;
	oid	tmp[2];

	DEBUGMSGTL((AGENT, "Create tables."));


	if (number < 26) {

		number ++;
		index = SNMP_MALLOC_TYPEDEF(netsnmp_index);
		tmp[0] = 1;
		tmp[1] = 'a' + number;
		index->oids = tmp;
		index->len = 2;

		x = netSnmpIETFWGTable_create_row(index);
		CONTAINER_INSERT(cb.container, x);
		//free(x);
		free(index);
	}
}

void
delete_(unsigned int clientreg, void *clientarg) {

	netsnmp_index index;
	netSnmpIETFWGTable_context *x;
	netSnmpIETFWGTable_context blah;
	oid	tmp[4];

        tmp[0]=3; tmp[1]='A'; tmp[2] ='B'; tmp[3] ='C';

        index.oids = tmp;
        index.len = 4;
	
	blah.index = index;	
	DEBUGMSGTL((AGENT,"Delete first some table."));
	x = CONTAINER_FIND(cb.container, &blah);
	DEBUGMSGTL((AGENT,"Found object [%X]\n",x));
	if (x) {
		DEBUGMSGTL((AGENT,"Deleteing object\n"));
		CONTAINER_REMOVE(cb.container,x);
		DEBUGMSGTL((AGENT,"Object deleted\n"));
	}
		
}