#include "LoginWindow.h"
#include "MainMenu.h"
//#include "Main.h"
#include "C:\msys64\mingw64\include\gtkmm-4.0\gtkmm.h"
#include <iostream>

int main(int argc, char* argv[])
{
  auto app = Gtk::Application::create("org.gtkmm.example");
  auto status = app->make_window_and_run<LoginWindow>(argc, argv); //return app->make_window_and_run<LoginWindow>(argc, argv);

  auto app2 = Gtk::Application::create("org.gtkmm.example");
  app2->make_window_and_run<MainMenu>(argc,argv);

  return status;
}

 