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
/* $XConsortium: list.h /main/4 1995/11/09 12:45:45 rswiston $ */
/*
 *  (c) Copyright 1993, 1994 Hewlett-Packard Company
 *  (c) Copyright 1993, 1994 International Business Machines Corp.
 *  (c) Copyright 1993, 1994 Novell, Inc.
 *  (c) Copyright 1993, 1994 Sun Microsystems, Inc.
 */

#ifndef _LIST_H
#define _LIST_H

#include "data.h"
#include "rerule.h"

typedef struct lnode {
	struct lnode	*llink;
	struct lnode	*rlink;
	caddr_t		data;
	time_t		lasttick;
	int		duration;
	RepeatEvent	*re;
} List_node;

typedef struct {
	List_node	*root;
	caddr_t	private;	/* for internal tool state */
} Hc_list;

typedef int(*Destroy_proc)(caddr_t);

#define	hc_lookup_next(p_node)		(p_node)->rlink
#define	hc_lookup_previous(p_node)	(p_node)->llink

extern Rb_Status	hc_check_list(Hc_list*);
extern Hc_list*		hc_create(_DtCmsGetKeyProc, _DtCmsCompareProc);
extern List_node	*hc_delete(Hc_list*, caddr_t key);
extern List_node	*hc_delete_node(Hc_list*, List_node*);
extern void		hc_destroy(Hc_list*, Destroy_proc);
extern void		hc_enumerate_down(Hc_list*, _DtCmsEnumerateProc);
extern Rb_Status	hc_enumerate_up(Hc_list*, _DtCmsEnumerateProc);
extern Rb_Status	hc_insert(Hc_list*, caddr_t data, caddr_t key,
					RepeatEvent *re, List_node **node_r);
extern caddr_t		hc_lookup(Hc_list*, caddr_t key);
extern caddr_t		hc_lookup_largest(Hc_list*);
extern caddr_t		hc_lookup_next_larger(Hc_list*, caddr_t key);
extern caddr_t		hc_lookup_next_smaller(Hc_list*, caddr_t key);
extern caddr_t		hc_lookup_smallest(Hc_list*);
extern int		hc_size(Hc_list*);
extern List_node	*hc_lookup_node(Hc_list*, caddr_t key);
extern Hc_list*		hc_create(_DtCmsGetKeyProc, _DtCmsCompareProc);
extern Rb_Status	hc_insert_node(Hc_list *, List_node *, caddr_t key);

#endif
