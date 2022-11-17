#include "MainMenu.h"
#include "LoginWindow.h"
#include "C:\msys64\mingw64\include\gtkmm-4.0\gtkmm.h"

MainMenu::MainMenu(): m_VBox(Gtk::Orientation::VERTICAL) // main mewnu constructor 
{
  g_object_set(gtk_settings_get_default(),"gtk-application-prefer-dark-theme", TRUE,NULL); //set dark mode

  set_size_request(200, 100); //set default size of window  
  set_title("Main Menu"); // title
  set_resizable(true); // make window resizable
  set_child(m_VBox);
  m_VBox.append(m_HBox);

  testbutton.set_label("test");
  testbutton.signal_clicked().connect( sigc::mem_fun(*this,&MainMenu::loginPrompt) ); //set callback function
  m_VBox.append(testbutton);
}

MainMenu::~MainMenu(){
}


void MainMenu::loginPrompt(){
    Gtk::
}