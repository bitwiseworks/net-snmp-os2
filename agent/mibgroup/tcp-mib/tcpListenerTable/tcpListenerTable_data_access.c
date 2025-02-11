/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 1.17 $ of : mfd-data-access.m2c,v $ 
 *
 * $Id$
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
#include "tcpListenerTable.h"


#include "tcpListenerTable_data_access.h"

/** @ingroup interface 
 * @addtogroup data_access data_access: Routines to access data
 *
 * These routines are used to locate the data used to satisfy
 * requests.
 * 
 * @{
 */
/**********************************************************************
 **********************************************************************
 ***
 *** Table tcpListenerTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * TCP-MIB::tcpListenerTable is subid 20 of tcp.
 * Its status is Current.
 * OID: .1.3.6.1.2.1.6.20, length: 8
 */

/**
 * initialization for tcpListenerTable data access
 *
 * This function is called during startup to allow you to
 * allocate any resources you need for the data table.
 *
 * @param tcpListenerTable_reg
 *        Pointer to tcpListenerTable_registration
 *
 * @retval MFD_SUCCESS : success.
 * @retval MFD_ERROR   : unrecoverable error.
 */
int
tcpListenerTable_init_data(tcpListenerTable_registration *
                           tcpListenerTable_reg)
{
    DEBUGMSGTL(("verbose:tcpListenerTable:tcpListenerTable_init_data",
                "called\n"));

    /*
     * TODO:303:o: Initialize tcpListenerTable data.
     */

    return MFD_SUCCESS;
}                               /* tcpListenerTable_init_data */

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
tcpListenerTable_container_init(netsnmp_container **container_ptr_ptr,
                                netsnmp_cache * cache)
{
    DEBUGMSGTL(("verbose:tcpListenerTable:tcpListenerTable_container_init",
                "called\n"));

    if (NULL == container_ptr_ptr) {
        snmp_log(LOG_ERR,
                 "bad container param to tcpListenerTable_container_init\n");
        return;
    }

    /*
     * For advanced users, you can use a custom container. If you
     * do not create one, one will be created for you.
     */
    *container_ptr_ptr = NULL;

    if (NULL == cache) {
        snmp_log(LOG_ERR,
                 "bad cache param to tcpListenerTable_container_init\n");
        return;
    }

    /*
     * TODO:345:A: Set up tcpListenerTable cache properties.
     *
     * Also for advanced users, you can set parameters for the
     * cache. Do not change the magic pointer, as it is used
     * by the MFD helper. To completely disable caching, set
     * cache->enabled to 0.
     */
    cache->timeout = TCPLISTENERTABLE_CACHE_TIMEOUT;    /* seconds */
    cache->flags |= NETSNMP_CACHE_DONT_INVALIDATE_ON_SET;
}                               /* tcpListenerTable_container_init */

/**
 * container shutdown
 *
 * @param container_ptr A pointer to the container.
 *
 *  This function is called at shutdown to allow you to customize certain
 *  aspects of the access method. For the most part, it is for advanced
 *  users. The default code should suffice for most cases.
 *
 *  This function is called before tcpListenerTable_container_free().
 *
 * @remark
 *  This would also be a good place to do any cleanup needed
 *  for you data source. For example, closing a connection to another
 *  process that supplied the data, closing a database, etc.
 */
void
tcpListenerTable_container_shutdown(netsnmp_container *container_ptr)
{
    DEBUGMSGTL(("verbose:tcpListenerTable:tcpListenerTable_container_shutdown", "called\n"));

    if (NULL == container_ptr) {
        snmp_log(LOG_ERR,
                 "bad params to tcpListenerTable_container_shutdown\n");
        return;
    }

}                               /* tcpListenerTable_container_shutdown */

/**
 * add new entry
 */
static void
_add_connection(netsnmp_tcpconn_entry *entry, netsnmp_container *container)
{
    tcpListenerTable_rowreq_ctx *rowreq_ctx;

    DEBUGMSGTL(("tcpListenerTable:access", "creating new entry\n"));

    /*
     * allocate an row context and set the index(es), then add it to
     * the container
     */
    rowreq_ctx = tcpListenerTable_allocate_rowreq_ctx(entry, NULL);
    if (!rowreq_ctx) {
        snmp_log(LOG_ERR,
                 "memory allocation failed while loading tcpListenerTable cache.\n");
        netsnmp_access_tcpconn_entry_free(entry);
        return;
    }
    if (tcpListenerTable_indexes_set(rowreq_ctx, entry->loc_addr_len,
            (char *)entry->loc_addr, entry->loc_addr_len, entry->loc_port) !=
            MFD_SUCCESS) {
        snmp_log(LOG_ERR,
                 "error setting index while loading tcpListenerTable cache.\n");
        tcpListenerTable_release_rowreq_ctx(rowreq_ctx);
        return;
    }
    if (CONTAINER_INSERT(container, rowreq_ctx) < 0) {
        snmp_log(LOG_ERR, "tcpListenerTable insert failed.\n");
        tcpListenerTable_release_rowreq_ctx(rowreq_ctx);
    }
}

/**
 * load initial data
 *
 * TODO:350:M: Implement tcpListenerTable data load
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
 *  If, however, the accessing the data involves more work (e.g. parsing
 *  some other existing data, or peforming calculations to derive the data),
 *  then you can limit yourself to setting the indexes and saving any
 *  information you will need later. Then use the saved information in
 *  tcpListenerTable_row_prep() for populating data.
 *
 * @note
 *  If you need consistency between rows (like you want statistics
 *  for each row to be from the same time frame), you should set all
 *  data here.
 *
 */
int
tcpListenerTable_container_load(netsnmp_container *container)
{
    netsnmp_container *raw_data =
        netsnmp_access_tcpconn_container_load(NULL,
                                              NETSNMP_ACCESS_TCPCONN_LOAD_ONLYLISTEN);

    DEBUGMSGTL(("verbose:tcpListenerTable:tcpListenerTable_container_load",
                "called\n"));

    if (NULL == raw_data)
        return MFD_RESOURCE_UNAVAILABLE;        /* msg already logged */

    /*
     * got all the connections. pull out the active ones.
     */
    CONTAINER_FOR_EACH(raw_data, (netsnmp_container_obj_func *)
                       _add_connection, container);

    /*
     * free the container. we've either claimed each entry, or released it,
     * so the dal function doesn't need to clear the container.
     */
    netsnmp_access_tcpconn_container_free(raw_data,
                                          NETSNMP_ACCESS_TCPCONN_FREE_DONT_CLEAR);

    DEBUGMSGT(("verbose:tcpListenerTable:tcpListenerTable_cache_load",
               "%d records\n", (int)CONTAINER_SIZE(container)));

    return MFD_SUCCESS;
}                               /* tcpListenerTable_container_load */

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
tcpListenerTable_container_free(netsnmp_container *container)
{
    DEBUGMSGTL(("verbose:tcpListenerTable:tcpListenerTable_container_free",
                "called\n"));

    /*
     * TODO:380:M: Free tcpListenerTable container data.
     */
}                               /* tcpListenerTable_container_free */

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
tcpListenerTable_row_prep(tcpListenerTable_rowreq_ctx * rowreq_ctx)
{
    DEBUGMSGTL(("verbose:tcpListenerTable:tcpListenerTable_row_prep",
                "called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

    /*
     * TODO:390:o: Prepare row for request.
     * If populating row data was delayed, this is the place to
     * fill in the row for this request.
     */

    return MFD_SUCCESS;
}                               /* tcpListenerTable_row_prep */

/** @} */
