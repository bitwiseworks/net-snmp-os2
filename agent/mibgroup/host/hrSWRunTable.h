/*
 * Note: this file originally auto-generated by mib2c using
 *  : mib2c.container.conf,v 1.8 2006/07/26 15:58:26 dts12 Exp $
 */
/* Portions of this file are subject to the following copyright(s).  See
 * the Net-SNMP's COPYING file for more details and other copyrights
 * that may apply:
 */
/*
 * Portions of this file are copyrighted by:
 * Copyright (C) 2007 Apple, Inc. All rights reserved.
 * Use is subject to license terms specified in the COPYING file
 * distributed with the Net-SNMP package.
 */
#ifndef HRSWRUNTABLE_H
#define HRSWRUNTABLE_H

config_require(host/data_access/swrun);
config_require(host/hrSWRunPerfTable);

/*
 * function declarations 
 */
void            init_hrSWRunTable(void);
void            shutdown_hrSWRunTable(void);
void            initialize_table_hrSWRunTable(void);
Netsnmp_Node_Handler hrSWRunTable_handler;

/*
 * column number definitions for table hrSWRunTable 
 */
#define COLUMN_HRSWRUNINDEX		1
#define COLUMN_HRSWRUNNAME		2
#define COLUMN_HRSWRUNID		3
#define COLUMN_HRSWRUNPATH		4
#define COLUMN_HRSWRUNPARAMETERS		5
#define COLUMN_HRSWRUNTYPE		6
#define COLUMN_HRSWRUNSTATUS		7
#endif                          /* HRSWRUNTABLE_H */
