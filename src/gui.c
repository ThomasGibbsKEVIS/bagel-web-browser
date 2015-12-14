#include <gtk/gtk.h>

GtkWidget *init_gui() {
  GtkWidget *window;
  gtk_init(&argc, &argv);
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  g_signal_connect(window, "delete-event", G_CALLBACK (DeleteEvent), NULL);
  g_signal_connect(window, "destroy", G_CALLBACK (WindowClose), NULL);
  gtk_widget_show(window);
  return window;
}
