#include "gui.c"

int main(int argc, char** argv) {
  GtkWidgetGroup window;
  window[0] = init_gui();
  return 0;
}
