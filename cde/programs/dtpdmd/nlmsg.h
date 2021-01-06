/*
 * CDE - Common Desktop Environment
 *
 * Copyright (c) 1993-2012, The Open Group. All rights reserved.
 *
 * These libraries and programs are free software; you can
 * redistribute them and/or modify them under the terms of the GNU
 * Lesser General Public License as published by the Free Software
 * Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * These libraries and programs are distributed in the hope that
 * they will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE. See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with these libraries and programs; if not, write
 * to the Free Software Foundation, Inc., 51 Franklin Street, Fifth
 * Floor, Boston, MA 02110-1301 USA
 */
/* $XConsortium: nlmsg.h /main/1 1996/10/30 19:10:36 cde-hp $ */
/*
 * dtpdmd/nlmsg.h
 */
/*
 * (c) Copyright 1996 Digital Equipment Corporation.
 * (c) Copyright 1996 Hewlett-Packard Company.
 * (c) Copyright 1996 International Business Machines Corp.
 * (c) Copyright 1996 Sun Microsystems, Inc.
 * (c) Copyright 1996 Novell, Inc. 
 * (c) Copyright 1996 FUJITSU LIMITED.
 * (c) Copyright 1996 Hitachi.
 */
#ifndef _PdmdMsgs_h
#define _PdmdMsgs_h

#include <Dt/MsgCatP.h>

#define PDMD_MSG_1 DtPdmdGetMessage(1, 1, DtPdmdMsg_0001)
#define PDMD_MSG_2 DtPdmdGetMessage(1, 2, DtPdmdMsg_0002)
#define PDMD_MSG_3 DtPdmdGetMessage(1, 3, DtPdmdMsg_0003)
#define PDMD_MSG_4 DtPdmdGetMessage(1, 4, DtPdmdMsg_0004)
#define PDMD_MSG_5 DtPdmdGetMessage(1, 5, DtPdmdMsg_0005)
#define PDMD_MSG_6 DtPdmdGetMessage(1, 6, DtPdmdMsg_0006)
#define PDMD_MSG_7 DtPdmdGetMessage(1, 7, DtPdmdMsg_0007)
#define PDMD_MSG_8 DtPdmdGetMessage(1, 8, DtPdmdMsg_0008)
#define PDMD_MSG_9 DtPdmdGetMessage(1, 9, DtPdmdMsg_0009)
#define PDMD_MSG_10 DtPdmdGetMessage(1, 10, DtPdmdMsg_0010)
#define PDMD_MSG_11 DtPdmdGetMessage(1, 11, DtPdmdMsg_0011)
#define PDMD_MSG_12 DtPdmdGetMessage(1, 12, DtPdmdMsg_0012)
#define PDMD_MSG_13 DtPdmdGetMessage(1, 13, DtPdmdMsg_0013)
#define PDMD_MSG_14 DtPdmdGetMessage(1, 14, DtPdmdMsg_0014)
#define PDMD_MSG_15 DtPdmdGetMessage(1, 15, DtPdmdMsg_0015)
#define PDMD_MSG_16 DtPdmdGetMessage(1, 16, DtPdmdMsg_0016)

extern const char DtPdmdMsg_0001[];
extern const char DtPdmdMsg_0002[];
extern const char DtPdmdMsg_0003[];
extern const char DtPdmdMsg_0004[];
extern const char DtPdmdMsg_0005[];
extern const char DtPdmdMsg_0006[];
extern const char DtPdmdMsg_0007[];
extern const char DtPdmdMsg_0008[];
extern const char DtPdmdMsg_0009[];
extern const char DtPdmdMsg_0010[];
extern const char DtPdmdMsg_0011[];
extern const char DtPdmdMsg_0012[];
extern const char DtPdmdMsg_0013[];
extern const char DtPdmdMsg_0014[];
extern const char DtPdmdMsg_0015[];
extern const char DtPdmdMsg_0016[];

/* Message IDs */

const char *DtPdmdGetMessage(int set,
                             int n,
                             const char *s);

#endif /* _PdmdMsgs_h */
