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
 * MsgCat.c - public interfaces for the Cached Message Catalog Service
 *
 * $TOG: MsgCat.c /main/4 1999/07/02 14:02:03 mgreess $
 *
 */

#include <stdio.h>
#include <string.h>

#if defined(NO_XLIB)
#define _DtSvcProcessLock()
#define _DtSvcProcessUnlock()
#else
#include <X11/Intrinsic.h>
#include <DtSvcLock.h>
#endif /* NO_XLIB */

#include <Dt/MsgCatP.h>

#if defined(hpV4) && !defined(NO_XLIB)
typedef struct _dt_msg_cache
{
    char ***cached_msgs;
    int     nmsgs_per_set;
    int     nsets;

    nl_catd catd;
    struct _dt_msg_cache *next;
} _DtMsgCache;

static _DtMsgCache	*catalog_message_caches = NULL;

static _DtMsgCache *get_msg_cache(nl_catd catd)
{
    const int initial_nmsgs_per_set = 300;
    const int initial_nsets         = 50;

    _DtMsgCache *c;

    for (c=catalog_message_caches; NULL!=c; c=c->next)
      if (catd == c->catd) return c;

    c = (_DtMsgCache*) XtMalloc(sizeof(_DtMsgCache));
    c->cached_msgs = NULL;
    c->nmsgs_per_set = initial_nmsgs_per_set;
    c->nsets = initial_nsets;
    c->catd = catd;
    c->next = catalog_message_caches;
    catalog_message_caches = c;
    return c;
}

/*
 * Wrapper around catgets -- this makes sure the message string is saved
 * in a safe location; so repeated calls to catgets() do not overwrite
 * the catgets() internal buffer.  This has been a problem on HP systems.
 */
char *_DtCatgetsCached(nl_catd catd, int set, int num, const char *dflt)
{
    char	*message = NULL;
    _DtMsgCache	*c;
    char	**setptr;
    int		i, multiplier;
    int		size;

    /* convert to a zero based index */
    int		setIdx = set - 1;
    int		numIdx = num - 1;

    c = get_msg_cache(catd);
    if (NULL == c) 
    {
        message = catgets(catd, set, num, dflt);
	return message;
    }

    if (NULL == c->cached_msgs)
    {
        size = sizeof(char**) * c->nsets;
        c->cached_msgs = (char***) XtMalloc(size);
        memset((char*) c->cached_msgs, 0, size);
    }
    else if (setIdx >= c->nsets)
    {
        for (multiplier=2; setIdx > multiplier*c->nsets; multiplier++) {}
        size = sizeof(char**) * c->nsets;
        c->cached_msgs =
	  (char***) XtRealloc((char*) c->cached_msgs, multiplier*size);
        memset((char*) (c->cached_msgs + size), 0, multiplier*size);
        c->nsets *= multiplier;
    }

    if (NULL == c->cached_msgs[setIdx])
    {
        size = sizeof(char*) * c->nmsgs_per_set;
        c->cached_msgs[setIdx] = (char**) XtMalloc(size);
        memset((char*) c->cached_msgs[setIdx], 0, size);
    }
    else if (numIdx >= c->nmsgs_per_set)
    {
        for (multiplier=2; numIdx > multiplier*c->nsets; multiplier++) {}
        size = sizeof(char*) * c->nmsgs_per_set;
  
        for (i=0; i<c->nmsgs_per_set; i++)
        {
	    if (NULL != c->cached_msgs[i])
	    {
                c->cached_msgs[i] =
		  (char**) XtRealloc((char*)c->cached_msgs[i], multiplier*size);
                memset((char*) (c->cached_msgs[i] + size), 0, multiplier*size);
	    }
        }
        c->nmsgs_per_set *= multiplier;
    }

    setptr = c->cached_msgs[setIdx];
    if (NULL == setptr[numIdx])
      setptr[numIdx] = strdup(catgets(catd, set, num, dflt));
  
    message = setptr[numIdx];

    return message;
}
#endif /* hpV4 */

int _DtCatclose(nl_catd catd)
{
    return (catd == (nl_catd) -1) ? 0 : catclose(catd);
}

char *_DtCatgets(nl_catd catd, int set, int num, const char *dflt)
{
    char *msg = NULL;

    if (catd == (nl_catd) -1 || set < 0 || num < 0) {
      /* Some catgets() implementations will fault if catd is invalid. */
      msg = (char *) dflt;
    } else {
      /* Per POSIX, we cannot assume catgets() is thread-safe. */
      _DtSvcProcessLock();
#if defined(hpV4) && !defined(NO_XLIB)
      msg = _DtCatgetsCached(catd, set, num, dflt);
#else
      msg = catgets(catd, set, num, dflt);
#endif /* hpV4 */
      _DtSvcProcessUnlock();
    }

   return msg;
}
