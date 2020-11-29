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
**  timeops.h
**
**  static char sccsid[] = "@(#)timeops.h 1.10 94/11/07 Copyr 1991 Sun Microsystems, Inc.";
**
**  $XConsortium: timeops.h /main/3 1995/11/03 10:39:02 rswiston $
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

#ifndef _TIMEOPS_H
#define _TIMEOPS_H

#include <EUSCompat.h>

typedef enum {
	minsec		= 60,
	fivemins	= 300,
	hrsec		= 3600,
	daysec		= 86400,
	wksec		= 604800,
	yrsec		= 31536000,
	leapyrsec	= 31622400
} Unit;

/* use time_t typedef for Tick, not a hardcoded long */
typedef time_t  Tick;		/* tick = seconds since epoch */

extern Tick	bot;		/* beginning of time */
extern char	*days[];
extern char	*days2[];
extern char	*days3[];
extern char	*days4[];
extern Tick	eot;		/* end of time */
extern char	*hours[];
extern int	monthdays[];
extern char	*months[];
extern char	*months2[];
extern int	monthsecs[];
extern char	*numbers[];

extern int	days_to_seconds	(int);
extern int	dom		(Tick);
extern int	dow		(Tick);
extern int	fdom		(Tick);
extern Tick	first_dom	(Tick);
extern Tick	first_dow	(Tick);
extern Tick	get_eot		(void);
extern Tick	get_bot		(void);
extern long	gmt_off		(void);
extern int	hour		(Tick);
extern int	hours_to_seconds(int);
extern void	init_time	(void);
extern Tick	jan1		(Tick);
extern Tick	last_dom	(Tick);
extern Tick	last_dow	(Tick);
extern Tick	last_ndays	(Tick t, int);
extern int	lastapptofweek	(u_int);
extern Tick	lastjan1	(Tick);
extern int	ldom		(Tick);
extern Tick	lower_bound	(int, Tick);
extern Tick	lowerbound	(Tick);
extern boolean_t magic_time	(Tick t);
extern Tick	midnight	();
extern int	minutes_to_seconds(int);
extern int	minute		(Tick);
extern int	month		(Tick);
extern Tick	monthdayyear	(int, int, int);
extern int	monthlength	(Tick);
extern Tick	next_ndays	(Tick, int);
extern Tick	next_nhours	(Tick, int);
extern Tick	next2weeks	(Tick);
extern Tick	nextday		(Tick);
extern Tick	nextjan1	(Tick);
extern Tick	nextmonth	(Tick t);
extern Tick	next_nmonth	(Tick t, int n);
extern Tick	nextmonth_exactday(Tick t);
extern Tick	nextweek	(Tick t);
extern Tick	nextyear	(Tick);
extern Tick	nextnyear	(Tick t, int n);
extern Tick	now		(void);
extern int	ntimes_this_week(u_int, int);
extern int	numwks		(Tick);
extern Tick	prev_nmonth	(Tick t, int n);
extern Tick	prevmonth_exactday(Tick);
extern Tick	previousmonth	(Tick t);
extern Tick	prevweek	(Tick t);
extern Tick	prev2weeks	(Tick t);
extern Tick	prevnyear	(Tick t, int n);
extern int	seconds		(int n, Unit unit);
extern double	seconds_dble	(double n, Unit unit);
extern int	seconds_to_days	(int);
extern int	seconds_to_hours(int);
extern int	seconds_to_minutes(int);
extern int	seconds_to_weeks(int);
extern void	set_timezone	(char*);
extern int	timeok		(Tick t);
extern Tick	upperbound	(Tick);
extern int	weeks_to_seconds(int);
extern int	wom		(Tick);
extern boolean_t weekofmonth	(Tick, int*);
extern Tick	xytoclock	(int, int, Tick);
extern int	year		(Tick);
extern int	adjust_dst	(Tick, Tick);
extern boolean_t adjust_hour	(int*);
extern int	leapyr		(int);
extern Tick	prevday		(Tick);

#endif
