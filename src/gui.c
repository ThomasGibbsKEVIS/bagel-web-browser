#include <gtk/gtk.h>

/* Bagel - A simple web browser written in C
Copyright (C) 2015  0xF3d04a

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Affero General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>. */

typedef GtkWidget *GtkWidgetGroup[];

GtkWidget *init_gui() {
  GtkWidgetGroup window;
  gtk_init(&argc, &argv);
  window[0] = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW (window[0]), "Bagel");
  g_signal_connect(window[0], "delete-event", G_CALLBACK (DeleteEvent), NULL);
  g_signal_connect(window[0], "destroy", G_CALLBACK (WindowClose), NULL);
  window[2] = gtk_handle_box_new();
  // TODO: Learn how to make packboxes
  window[1] = gtk_toolbar_new();
  gtk_toolbar_set_orientation (GTK_TOOLBAR (window[1]), GTK_ORIENTATION_HORIZONTAL);
  gtk_toolbar_set_style (GTK_TOOLBAR (window[1]), GTK_TOOLBAR_BOTH);
  gtk_container_set_border_width (GTK_CONTAINER (window[1]), 5);
  gtk_toolbar_set_space_size (GTK_TOOLBAR (window[1]), 5);
  gtk_container_add (GTK_CONTAINER (window[2]), window[1]);
  window[1] = gtk_toolbar_insert_item(GTK_TOOLBAR (window[1]), "Bagel", "Control the browser", "Control the browser", NULL, GTK_SIGNAL_FUNC (DeleteEvent), NULL, 1);
  gtk_widget_show(window[1]);
  gtk_widget_show(window[2]);
  gtk_widget_show(window[0]);
  return window;
}

static gboolean DeleteEvent(GtkWidget *victim, GdkEvent *event, gpointer data) {
  return FALSE;
}

static void WindowClose(GtkWidget *victim, gpointer data) {
  gtk_main_quit();
}
