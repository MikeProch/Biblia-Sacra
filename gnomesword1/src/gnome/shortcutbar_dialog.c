/*
 * GnomeSword Bible Study Tool
 * shortcutbar_dialog.c - dialog for detached shortcut bar
 *
 * Copyright (C) 2000,2001,2002 GnomeSword Developer Team
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Library General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gnome.h>
#include <gtkhtml/gtkhtml.h>
#include <gal/e-paned/e-hpaned.h>

/* frontend */
#include "shortcutbar_main.h"
#include "shortcutbar_dialog.h"

/* main */ 
#include "gs_gnomesword.h"
#include "support.h"
#include "settings.h"

/******************************************************************************
 * Name
 *   gui_attach_detach_shortcutbar
 *
 * Synopsis
 *   #include "shortcutbar_dialog.h"
 *   
 *   void gui_attach_detach_shortcutbar(void)
 *
 * Description
 *   dock/undock shortcut bar
 *   
 *
 * Return value
 *   
 */

void gui_attach_detach_shortcutbar(void)
{
	gint biblepanesize;

	if (settings.docked) {
		settings.docked = FALSE;
		biblepanesize = settings.gs_width / 2;
		settings.dockSB = gui_create_shortcutbar_dialog();
		gtk_widget_reparent(settings.shortcut_bar, settings.vboxDock);
		settings.showshortcutbar = TRUE;
		gtk_widget_show(settings.shortcut_bar);
		e_paned_set_position(E_PANED(settings.epaned), 0);
		e_paned_set_position(E_PANED
				     (lookup_widget
				      (settings.app, "hpaned1")),
				     biblepanesize);
		gtk_widget_show(settings.dockSB);
	} else {
		settings.docked = TRUE;
		biblepanesize =
		    (settings.gs_width - settings.shortcutbar_width) / 2;
		e_paned_set_position(E_PANED(settings.epaned),
				     settings.shortcutbar_width);
		e_paned_set_position(E_PANED
				     (lookup_widget
				      (settings.app, "hpaned1")),
				     biblepanesize);
		gtk_widget_reparent(settings.shortcut_bar,
				    settings.epaned);
		gtk_widget_destroy(settings.dockSB);
	}
}

/******************************************************************************
 * Name
 *   on_dlgDock_destroy
 *
 * Synopsis
 *   #include "shortcutbar_dialog.h"
 *   
 *   void on_dlgDock_destroy(GtkObject *object, gpointer user_data)
 *
 * Description
 *   send the shortcut bar back to the main window before we 
 *   destroy the dialog
 *   
 *
 * Return value
 *   void
 */

static void on_dlgDock_destroy(GtkObject *object, gpointer user_data)
{
	/* we need the if to prevent a loop */
	if(!settings.docked)
		gui_attach_detach_shortcutbar();
}

/******************************************************************************
 * Name
 *   gui_create_shortcutbar_dialog
 *
 * Synopsis
 *   #include "shortcutbar_dialog.h"
 *   
 *   GtkWidget* gui_create_shortcutbar_dialog (void)
 *
 * Description
 *   create dialog to hold the shortcut bar when detached
 *   
 *
 * Return value
 *   GtkWidget*
 */

GtkWidget* gui_create_shortcutbar_dialog(void)
{
	GtkWidget *dlgDock; 

	dlgDock = gtk_window_new(GTK_WINDOW_DIALOG);
	gtk_object_set_data(GTK_OBJECT(dlgDock), "dlgDock", dlgDock);
	gtk_window_set_title(GTK_WINDOW(dlgDock), _("GnomeSWORD"));
	gtk_window_set_policy(GTK_WINDOW(dlgDock), TRUE, TRUE, FALSE);
	gtk_widget_set_usize(dlgDock, settings.shortcutbar_width,
			settings.gs_hight);

	settings.vboxDock = gtk_vbox_new(FALSE, 0);
	gtk_widget_ref(settings.vboxDock);
	gtk_object_set_data_full(GTK_OBJECT (dlgDock), "settings.vboxDock",
		  settings.vboxDock, (GtkDestroyNotify)gtk_widget_unref);
	gtk_widget_show(settings.vboxDock);
	gtk_container_add(GTK_CONTAINER(dlgDock), settings.vboxDock);

	gtk_signal_connect(GTK_OBJECT(dlgDock), "destroy",
			GTK_SIGNAL_FUNC(on_dlgDock_destroy), NULL);

	return dlgDock;
}

