#include "MainMenu.h"
#include "LoginWindow.h"
#include "FileLocations.h"
#include "C:\msys64\mingw64\include\gtkmm-4.0\gtkmm.h"
#include <iostream>

MainMenu::MainMenu(): m_VBox(Gtk::Orientation::VERTICAL) // main mewnu constructor 
{
  g_object_set(gtk_settings_get_default(),"gtk-application-prefer-dark-theme", TRUE,NULL); //set dark mode

  auto css = Gtk::CssProvider::create();//create new css object
  css->load_from_path(lgnCssFile); //import css

  set_size_request(1000,800); //set default size of window  
  set_title("Main Menu"); // title
  set_resizable(true); // make window resizable
  set_child(m_VBox);
  m_VBox.append(m_HBox);

  testbutton.set_label("test");
  testbutton.signal_clicked().connect( sigc::mem_fun(*this,&MainMenu::loginPrompt) ); //set callback function
  testbutton.get_style_context()->add_class("testButton"); //apply css
  m_grid.attach(testbutton, 0,0,1,1);
  m_VBox.append(testbutton);


}

MainMenu::~MainMenu(){
}


void MainMenu::loginPrompt(){

}