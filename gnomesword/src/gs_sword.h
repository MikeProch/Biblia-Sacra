/***************************************************************************
                                     gs_sword.h
                             -------------------
    begin                : Mon May 8 2000
    copyright            : (C) 2000 by Terry Biggs
    email                : tbiggs@infinet.com
 ***************************************************************************/

 /*
    *  This program is free software; you can redistribute it and/or modify
    *  it under the terms of the GNU General Public License as published by
    *  the Free Software Foundation; either version 2 of the License, or
    *  (at your option) any later version.
    *
    *  This program is distributed in the hope that it will be useful,
    *  but WITHOUT ANY WARRANTY; without even the implied warranty of
    *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    *  GNU Library General Public License for more details.
    *
    *  You should have received a copy of the GNU Library General Public License
    *  along with this program; if not, write to the Free Software
    *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
  */
#ifndef __GS_SWORD_H__
#define __GS_SWORD_H__  

#ifdef __cplusplus
extern "C" {
#endif
 
#include <gnome.h>

void initSWORD(GtkWidget *mainform);
void updateinterlinearpage(void);
void shutdownSWORD(void);
void FillDictKeysSWORD(void);
void changeVerseSWORD(gchar * ref);
//void searchSWORD(GtkWidget * searchFrm);
void resultsListSWORD(GtkWidget * searchFrm, 
		gint row, 
		gint column);
void strongsSWORD(gint window, gboolean choice);
void footnotesSWORD(gint window, gboolean choice);
/*
void nbchangecurModSWORD(gchar *modName, 
						gint page_num, 
						gboolean showchange); 
*/	
void changecurModSWORD(gchar *modName, gboolean showchange);
void navcurcomModSWORD(gint direction);
void changecomp1ModSWORD(gchar * modName);
void changecomp2ModSWORD(gchar * modName);
void changecomp3ModSWORD(gchar * modName);
void setversestyleSWORD(gboolean choice);
void chapterSWORD(void);
void verseSWORD(void);
void btnlookupSWORD(void);
void freeformlookupSWORD(GdkEventKey * event);
void changcurcomModSWORD(gchar * modName, 
		gboolean showchange);
void editnoteSWORD(gboolean editbuttonactive);
void savenoteSWORD(gboolean noteisModified);
void deletenoteSWORD(void);
void changcurdictModSWORD(gchar * modName, 
		gchar* keyText);
void dictSearchTextChangedSWORD(gchar * mytext);
void dictchangekeySWORD(gint direction);
void showmoduleinfoSWORD(char *modName);
void showinfoSWORD(GtkWidget * text, GtkLabel * label, GtkLabel * version_label);
void setglobalopsSWORD(gchar *option, gchar *yesno);
void changepercomModSWORD(gchar * modName);
void redisplayTextSWORD(void);
gchar* getmodnameSWORD(gint num);
void navcurcommModSWORD(gint backfoward);
void setuplisteditSWORD(GtkWidget *text);
void changeLEverseSWORD(gchar *verse);
void destroyListEditorSWORD(void);
GList* setupSDSWORD(GtkWidget *text);
void loadSDmodSWORD(GtkWidget *clist,gchar *modName);
gchar* getdictmodSWORD(void);
gchar* gettextmodSWORD(void);
gchar* getcommodSWORD(void);
gchar* getcommodDescriptionSWORD(void);
void gotokeySWORD(gchar *newkey);
void shutdownSDSWORD(void);
void SDdictSearchTextChangedSWORD(char* newkey);
GtkWidget *createSearchDlgSWORD(void);
void startsearchSWORD(GtkWidget *searchFrm);
GList* setupCommSWORD(GtkWidget *text);
void shutdownVCSWORD(void) ;
void loadVCmodSWORD(gchar *modName);
void gotoverseVCSWORD(gchar *newkey);
void navVCModSWORD(gint direction);
gchar* getVCmodDescriptionSWORD(void);
gchar* getSDmodDescriptionSWORD(void);
GList *getBibleBooks(void);
void morphsSWORD(gint window, gboolean choice) ;
void gotoBookmarkSWORD(gchar *modName, gchar *key);
gchar* getmodkeySWORD(gint num);
gfloat getSwordVerionSWORD(void);
void swapmodsSWORD(gchar *intmod);
void loadSDkeysSWORD(GtkWidget *clist);
void loadpreferencemodsSWORD(void);
void gs_firstrunSWORD(void);
void applyfontcolorandsizeSWORD(void);
void updateshortcutbarSWORD(void);

#ifdef __cplusplus
}
#endif
#endif	/* __GS_SWORD_H__ */
