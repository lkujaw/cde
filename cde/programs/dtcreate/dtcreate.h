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
/* $XConsortium: dtcreate.h /main/5 1996/09/17 11:01:43 rswiston $ */
/***************************************************************************/
/*                                                                         */
/*  dtcreate.h                                                             */
/*                                                                         */
/***************************************************************************/

#ifndef _DTCREATE_H_INCLUDED
#define _DTCREATE_H_INCLUDED

#define __TOOLTALK

#include <Xm/Xm.h>
#include <Dt/MsgCatP.h>
#include <sys/param.h>

/***************************************************************************/
/*                                                                         */
/*  Constant Declarations                                                  */
/*                                                                         */
/***************************************************************************/
#define TRUE                  1
#define FALSE                 0
#define Psz                   (char *)

#define MAXFILENAME           MAXPATHLEN
#define MAXBUFSIZE            256

        /*******************************************************************/
        /* Icon Sizes                                                      */
        /*******************************************************************/
#define CA_LRG_ICON_SIZE      48
#define CA_MED_ICON_SIZE      32
#define CA_SML_ICON_SIZE      24
#define CA_TINY_ICON_SIZE     16

        /*******************************************************************/
        /* FILE SELECTION WIDGET VALUES                                    */
        /*******************************************************************/
#define CA_ACTION_ICONS        1
#define CA_FILETYPE_ICONS      2
#define CA_FILE                3

        /*******************************************************************/
        /* ActionData fsFlags values                                       */
        /*******************************************************************/
#define CA_WT_XWINDOWS        0x0001
#define CA_WT_TERM            0x0002
#define CA_WT_PERMTERM        0x0004
#define CA_WT_SHELLTERM       0x0008

#define CA_DF_ONLYFTFILES     0x0010

        /*******************************************************************/
        /* Filetype flags.                                                 */
        /*******************************************************************/
#define CA_FT_CNTSTRING       0x0001
#define CA_FT_CNTBYTE         0x0002
#define CA_FT_CNTSHORT        0x0004
#define CA_FT_CNTLONG         0x0008

        /*******************************************************************/
        /* Filetype Internal flags                                         */
        /*******************************************************************/
#define CA_FT_APPLY           0x0001
#define CA_FT_EDIT            0x0002

        /*******************************************************************/
        /* Icon filename extensions                                        */
        /*******************************************************************/
#define LARGE_EXT             ".l"
#define MEDIUM_EXT            ".m"
#define SMALL_EXT             ".t"
#define TINY_EXT              ".t"

#define PIXMAP_EXT            ".pm"
#define BITMAP_EXT            ".bm"
#define MAX_EXT_SIZE          5

#define EXT_DELIMITER         '.'

#define ICON_BORDER_WIDTH     1
#define ICON_NUMBER           5

        /*******************************************************************/
        /* Help Ids                                                        */
        /*******************************************************************/
#define HELP_OVERVIEW         1
#define HELP_TASKS            2
#define HELP_REFERENCE        3
#define HELP_USING            4
#define HELP_ABOUT            5
#define HELP_ONITEM           6

#define HELP_ADDFILETYPE      10
#define HELP_FILECHAR         20
#define HELP_ICONSELECTOR     30
#define HELP_OPENFILE         40

/*****************************************************************************/
/*                                                                           */
/*  enums                                                                    */
/*                                                                           */
/*****************************************************************************/
enum icon_size_range {None_Selected, Large_Icon, Medium_Icon, Small_Icon, Tiny_Icon};
enum icon_data_range {CA_LRG, CA_MED, CA_TINY, AF_MED, AF_TINY};

/***************************************************************************/
/*                                                                         */
/*  Structure Declarations                                                 */
/*                                                                         */
/***************************************************************************/
typedef struct _FiletypeData *pFiletypeData;
typedef struct _FiletypeData {
        char           *pszName;
        char           *pszIcon;
        char           *pszMedPmIcon;
        char           *pszMedBmIcon;
        char           *pszTinyPmIcon;
        char           *pszTinyBmIcon;
        char           *pszHelp;
        char           *pszOpenCmd;
        char           *pszPrintCmd;
        char           *pszPattern;
        char           *pszPermissions;
        char           *pszContents;
        int            sStart;
        int            sEnd;
        ushort         fsFlags;
        ushort         fsInternal;
} FiletypeData;

typedef struct _ActionData *pActionData;
typedef struct _ActionData {
        char           *pszName;
        char           *pszIcon;
        char           *pszCmd;
        char           *pszHelp;
        char           *pszPrompt;
        FiletypeData   **papFiletypes;
        short          cFiletypes;
        ushort         fsFlags;
} ActionData;

typedef struct {
    char               *pszSessionFile;
    Boolean            useSession;
    Boolean            showExpert;
    int                iconicState;
    Position           x, y;
    Dimension          width, height;
    char	       workspaces[256];
} SessionData, *SessionDataPtr;

typedef struct {
    Widget                wid;
    char                  *pmMsgID;
    char                  *bmMsgID;
    char                  pmFileName[MAXPATHLEN];
    char                  bmFileName[MAXPATHLEN];
    Boolean               pmDirtyBit;
    Boolean               bmDirtyBit;
    enum icon_size_range  size;
} IconData, *IconDataPtr;

/***************************************************************************/
/*                                                                         */
/*  Macro Declarations                                                     */
/*                                                                         */
/***************************************************************************/
#define GETMESSAGE(set, number, defstr) CATGETS(nlmsg_fd, set, number, defstr)

/***************************************************************************/
/*                                                                         */
/*  Global Variable Declarations                                           */
/*                                                                         */
/***************************************************************************/

/*******************************************************************/
/* Global variables that are not being initialized.                */
/******************************************************************/

extern ActionData   AD;
extern ActionData   *pMyCopyAD;
extern char         *pszFileToEdit;
extern Cursor       watch_cursor;
extern Widget       widEditSource;
extern Boolean      bIconEditorDisplayed;
extern nl_catd      nlmsg_fd;
extern char         *pszExecName;
extern Widget       widSelectedIcon;
extern Boolean      bLowRes;
extern IconData     *IconDataList[ICON_NUMBER];

/**********************************************************/
/* CreateActionAppShell  globals.                         */
/**********************************************************/

extern Widget       CreateActionAppShell;
extern Widget       ExpertOption;
extern Widget       ColorMonoOption;
extern Widget       CA_ActionNameTextField;
extern Widget       CA_MED_IconGadget;
extern Widget       CA_SML_IconGadget;
extern Widget       CA_TINY_IconGadget;
extern Widget       CA_LRG_IconGadget;
extern Widget       CA_DblClkText;
extern Widget       XprtOptionForm;
extern Widget       CA_XprtActionOpenText;
extern Widget       CA_FiletypesList;
extern Widget       CA_WindowTypeArea;
extern Widget       CA_WindowType;
extern Widget       CA_Expand;
#if 0
extern Widget       CA_WindowType_OptionMenuShell;
extern Widget       CA_WindowType_Pane;
#endif
extern Widget       CA_WinTypeX;
extern Widget       CA_WinTypeAutoClose;
extern Widget       CA_WinTypeManualClose;
extern Widget       CA_WinTypeNoOutput;
extern Widget       CA_HelpTextWindow;
extern Widget       CA_HelpText;
extern Widget       CA_AllFiletypesToggle;
extern Widget       CA_FiletypesInListToggle;

/**********************************************************/
/* AddFiletype  globals.                                  */
/**********************************************************/

extern Widget       AddFiletype;
extern Widget       AF_FileTypeNameTextField;
extern Widget       AF_IdCharacteristicsText;
extern Widget       AF_IdCharacteristicsEdit;
extern Widget       AF_FiletypePrintCmdTextField;
extern Widget       AF_OpenCmdText;
extern Widget       AF_FiletypeHelpText;
extern Widget       AF_MED_IconGadget;
extern Widget       AF_TINY_IconGadget;

/**********************************************************/
/* FileCharacteristics  globals                           */
/**********************************************************/

extern Widget       FileCharacteristics;
extern Widget       FC_DirectoryToggle;
extern Widget       FC_FileToggle;
extern Widget       FC_AndLabel2;
extern Widget       FC_ContentsPatternText;
extern Widget       FC_StringToggle;
extern Widget       FC_ByteToggle;
extern Widget       FC_ShortToggle;
extern Widget       FC_LongToggle;
extern Widget       FC_StartByteTextField;
/*
extern Widget       FC_EndByteTextField;
*/
extern Widget       FC_NameOrPathText;
extern Widget       FC_AndLabel1;
extern Widget       FC_PermissionForm;
extern Widget       FC_ReadToggle;
extern Widget       FC_WriteToggle;
extern Widget       FC_ExecuteToggle;

extern Widget       FC_NamePatternLabel;
extern Widget       FC_PermissionLabel;
extern Widget       FC_PermissionToggle;
extern Widget       FC_ContentsLabel;
extern Widget       FC_ContentsBox;
extern Widget       FC_TypeRowColumn;
extern Widget       FC_StartByteLabel;
extern Widget       FC_TypeLabel;
extern Widget       FC_ContentsPatternLabel;
/*
extern Widget       FC_EndByteLabel;
*/
extern Widget       FC_ContentsToggle;
extern Widget       FC_NameOrPathToggle;

/**********************************************************/
/* icon_selection_dialog  globals                         */
/**********************************************************/
extern Widget       ISD_SelectedIconTextField;

/**********************************************************/
/* Other dialog globals                                   */
/**********************************************************/
extern SessionData  sessiondata;

/*******************************************************************/
/* Global variables that are being initialized.                    */
/*******************************************************************/

extern enum icon_size_range filetype_icon_size;
extern int     pidIconEditor;
extern Boolean bShowPixmaps;
extern Widget  IconSelector;
extern Boolean DbInitDone;
extern Widget  OpenFile;
extern Widget  Confirmed;
extern Widget  QuestionDialog;
extern Widget  ErrorDialog;
extern Widget  last_action_pushed;
extern Widget  last_filetype_pushed;

extern const char *ca_icon_default;
extern const char *ca_full_icon_default;
extern const char *ca_lrg_icon_default;
extern const char *ca_med_icon_default;
extern const char *ca_sml_icon_default;
extern const char *ca_tiny_icon_default;

extern const char *af_icon_default;
extern const char *af_full_icon_default;
extern const char *af_lrg_icon_default;
extern const char *af_med_icon_default;
extern const char *af_sml_icon_default;
extern const char *af_tiny_icon_default;

#endif /* _DTCREATE_H_INCLUDED */
