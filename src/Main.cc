#include "LoginWindow.h"
#include "MainMenu.h"
//#include "Main.h"
#include "C:\msys64\mingw64\include\gtkmm-4.0\gtkmm.h"

int main(int argc, char* argv[])
{
  

  auto app = Gtk::Application::create("org.gtkmm.example");
  //Shows the window and returns when it is closed.
  return app->make_window_and_run<LoginWindow>(argc, argv);
}

 