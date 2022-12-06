#include "C:\msys64\mingw64\include\gtkmm-4.0\gtkmm.h"

class MainMenu : public Gtk::Window
{
public:
  MainMenu();
  virtual ~MainMenu();
  void CreateWindow();

protected:
  //Signal handlers:
  void loginPrompt();
  Gtk::Frame GetMainMenuControls();
  

  //Child widgets:
  Gtk::Window MainMenuWindow;
  Gtk::Box m_HBox;
  Gtk::Box m_VBox;
  Gtk::Button StaffButton;
  Gtk::Button StockButton;
  Gtk::Button ThursdayBookingButton;
  Gtk::Button SundayBookingButton;
  Gtk::Button exitButton;
  Gtk::Grid m_grid;
  Gtk::Frame controls_Frame;
};
