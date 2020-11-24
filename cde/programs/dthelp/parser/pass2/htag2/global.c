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

#include "basic.h"
#include "trie.h"
#include "common.h"

#include "global.h"


/*
 * Names for all the input, output and intermediate files we'll need.
*/
char *inFileName;
char *outFileName;
char *errFileName;
char *idxFileName;
char *snbFileName;
char *sortedIdxFileName;
char *tossFileName;
char *vstructFileName;
char *tempFileName;
char *compFileName;
char *compZFileName;

FILE *inFile;
FILE *outFile;

