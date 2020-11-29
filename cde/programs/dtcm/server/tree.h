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
/* $XConsortium: tree.h /main/4 1995/11/09 12:53:31 rswiston $ */
/*
 *  (c) Copyright 1993, 1994 Hewlett-Packard Company
 *  (c) Copyright 1993, 1994 International Business Machines Corp.
 *  (c) Copyright 1993, 1994 Novell, Inc.
 *  (c) Copyright 1993, 1994 Sun Microsystems, Inc.
 */

#ifndef _TREE_H
#define _TREE_H

#include "data.h"

/*
**  2-3-4 tree, a.k.a. red-black tree
*/

typedef enum {red=0, black=1} Color;

typedef struct node {
	struct node *llink;
	struct node *rlink;
	Color	color;
	caddr_t	data;
} Tree_node;

typedef struct {
	Tree_node *root;
	caddr_t private;	/* for internal tool state */
} Rb_tree;

extern Rb_tree* rb_create(_DtCmsGetKeyProc, _DtCmsCompareProc);

extern void rb_destroy(Rb_tree*, _DtCmsEnumerateProc); 

extern int rb_size(Rb_tree*t);

extern Rb_Status rb_insert(Rb_tree*, caddr_t data, caddr_t key); 

extern Rb_Status rb_insert_node(Rb_tree*, Tree_node*, caddr_t key);

extern Tree_node * rb_delete(Rb_tree*, caddr_t key);

extern caddr_t rb_lookup(Rb_tree*, caddr_t key);

extern caddr_t rb_lookup_next_larger(Rb_tree*, caddr_t key);

extern caddr_t rb_lookup_next_smaller(Rb_tree*, caddr_t key);

extern caddr_t rb_lookup_smallest(Rb_tree*);

extern caddr_t rb_lookup_largest(Rb_tree*);

extern Rb_Status rb_enumerate_up(Rb_tree*, _DtCmsEnumerateProc);

extern void rb_enumerate_down(Rb_tree*, _DtCmsEnumerateProc);

extern Rb_Status rb_check_tree(Rb_tree *);

#endif
