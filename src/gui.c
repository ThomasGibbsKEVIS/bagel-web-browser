#include <gtk/gtk.h>

typedef GtkWidget *GtkWidgetGroup[];

GtkWidget *init_gui() {
  GtkWidgetGroup window;
  gtk_init(&argc, &argv);
  window[0] = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  g_signal_connect(window[0], "delete-event", G_CALLBACK (DeleteEvent), NULL);
  g_signal_connect(window[0], "destroy", G_CALLBACK (WindowClose), NULL);
  gtk_widget_show(window[0]);
  return window;
}
