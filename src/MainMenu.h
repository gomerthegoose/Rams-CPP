#include "C:\msys64\mingw64\include\gtkmm-4.0\gtkmm.h"

class MainMenu : public Gtk::Window
{
public:
  MainMenu();
  virtual ~MainMenu();

protected:
  //Signal handlers:
  void loginPrompt();

  //Child widgets:
  Gtk::Window LoginMenuWindow;
  Gtk::Box m_HBox;
  Gtk::Box m_VBox;
  Gtk::Button testbutton;
};