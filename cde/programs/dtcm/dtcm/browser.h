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
/*******************************************************************************
**
**  browser.h
**
**  static char sccsid[] = "@(#)browser.h 1.15 94/11/07 Copyr 1991 Sun Microsystems, Inc."; 
**
**  $XConsortium: browser.h /main/3 1995/11/03 10:18:46 rswiston $
**
**  RESTRICTED CONFIDENTIAL INFORMATION:
**
**  The information in this document is subject to special
**  restrictions in a confidential disclosure agreement between
**  HP, IBM, Sun, USL, SCO and Univel.  Do not distribute this
**  document outside HP, IBM, Sun, USL, SCO, or Univel without
**  Sun's specific written approval.  This document and all copies
**  and derivative works thereof must be returned or destroyed at
**  Sun's request.
**
**  Copyright 1993 Sun Microsystems, Inc.  All rights reserved.
**
*******************************************************************************/

/*									*
 * (c) Copyright 1993, 1994 Hewlett-Packard Company			*
 * (c) Copyright 1993, 1994 International Business Machines Corp.	*
 * (c) Copyright 1993, 1994 Sun Microsystems, Inc.			*
 * (c) Copyright 1993, 1994 Novell, Inc. 				*
 */

#ifndef _BROWSER_H
#define _BROWSER_H

#include "timeops.h"
#include "calendar.h"

typedef struct {
	Widget          frame;
	Widget		outer_pane;
	Widget		inner_pane;
	Widget		upper_form;
	Widget		lower_form;
	Widget		action;
	Widget		cancel;
	Widget		canvas;
	Widget		edit_list;
	Widget		helpbutton;
	Widget		list_label;
	Widget		browse_list;
	Widget		browse_list_sw;
	Widget		bgoto;
	Widget		gotomenu;
	Widget		schedule;
	Widget		mail;
	Widget		message_text;
        caddr_t         current_selection;      
	Widget		box;
        Widget      	datetext;
        Widget      	datefield;
        Tick            date;
        int     	col_sel;
        int     	row_sel;
        Tick     	begin_week_tick;
        int     	canvas_w;
        int     	canvas_h;
        int     	chart_width;
        int     	chart_height;
        int     	boxh;
        int     	boxw;
        int     	chart_x;
        int     	chart_y;
        Tick    	begin_day_tick;
        Tick    	end_day_tick;
        Tick    	begin_hr_tick;
        Tick    	end_hr_tick;
	new_XContext    *xcontext;
	char	 	*multi_array;
	int		segs_in_array;
        Pixmap 		busy_icon;
	Boolean		add_to_array;
} Browser;

#define BOX_SEG 4 
#define MINS_IN_SEG (60/BOX_SEG)

#define MB_GOTO 0
#define MB_PREVWEEK 1
#define MB_THISWEEK 2
#define MB_NEXTWEEK 3
#define MB_PREVMONTH 4
#define MB_NEXTMONTH 5

extern void		br_display(Calendar *);
extern Boolean		browser_exists(void);
extern void		browser_reset_list(Calendar*);
extern Boolean		browser_showing(void);
extern void		make_browser(Calendar *c);
extern void		mb_draw_chartgrid(Browser *b, Calendar *c);
extern void		mb_draw_appts(Browser *b, int start, int end, Calendar *c);
extern void		mb_update_segs(Browser *, Tick, Tick, int *, int *);
extern void		mb_update_busyicon(void);
extern void		mb_init_blist(void);
extern void		mb_init_canvas(Calendar *c);
extern void		mb_deregister_names(char *, Calendar *);
extern void		mb_refresh_canvas(Browser *b, Calendar *c);
extern void		sched_proc(void);
extern void		set_default_reminders(void);
extern void		set_default_scope_plus(void);
extern void		set_default_what(void);
extern void		mb_refigure_chart(Calendar *);

#endif
