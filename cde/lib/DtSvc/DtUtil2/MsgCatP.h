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
/* 
 * (c) Copyright 1995 Digital Equipment Corporation.
 * (c) Copyright 1995 Hewlett-Packard Company.
 * (c) Copyright 1995 International Business Machines Corp.
 * (c) Copyright 1995 Sun Microsystems, Inc.
 * (c) Copyright 1995 Novell, Inc. 
 * (c) Copyright 1995 FUJITSU LIMITED.
 * (c) Copyright 1995 Hitachi.
 *
 * MsgCat.h - Public interfaces for the Cached Message Catalog Service
 *
 * $TOG: MsgCatP.h /main/1 1998/04/22 14:19:24 mgreess $
 *
 */

#ifndef _Dt_MsgCat_h
#define _Dt_MsgCat_h

#include <nl_types.h>

#ifdef __cplusplus
extern "C" {
#endif

#define CATOPEN(name,oflag) catopen(name,oflag)
#define CATCLOSE(catd) _DtCatclose(catd)
#define CATGETS(catd,set,num,dflt) _DtCatgets(catd,set,num,dflt)
extern char *_DtCatgets(nl_catd catd, int set, int num, const char *dflt);
extern int _DtCatclose(nl_catd catd);

#if 0 /* TODO: Decide between !I18N_MSG and NO_MESSAGE_CATALOG */
typedef int nl_catd;
#define CATOPEN(name,oflag) 0
#define CATCLOSE(catd) 0
#define CATGETS(catd,set,num,dflt) dflt
#endif

#ifdef __cplusplus
}
#endif

#endif /* _Dt_MsgCat_h */
