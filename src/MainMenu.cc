#include "MainMenu.h"
#include "LoginWindow.h"
#include "FileLocations.h"
#include "C:\msys64\mingw64\include\gtkmm-4.0\gtkmm.h"
#include <iostream>

MainMenu::MainMenu(): m_VBox(Gtk::Orientation::VERTICAL) // main mewnu constructor 
{
  g_object_set(gtk_settings_get_default(),"gtk-application-prefer-dark-theme", TRUE,NULL); //set dark mode

  auto css = Gtk::CssProvider::create();//create new css object
  css->load_from_path(ManinMenuCssFile); //import css

  get_style_context()->add_provider_for_display(Gdk::Display::get_default(), css, GTK_STYLE_PROVIDER_PRIORITY_APPLICATION); //something

  set_size_request(1000,800); //set default size of window  
  set_title("Main Menu"); // title
  set_resizable(true); // make window resizable
  set_child(m_VBox);
  m_VBox.append(m_HBox);

  testbutton.set_label("hello me name a chef this is a button");
  testbutton.signal_clicked().connect( sigc::mem_fun(*this,&MainMenu::loginPrompt) ); //set callback function
  testbutton.get_style_context()->add_class("testButton"); //apply css

  testbutton2.set_label("test2");
  testbutton2.signal_clicked().connect( sigc::mem_fun(*this,&MainMenu::loginPrompt) ); //set callback function
  testbutton2.get_style_context()->add_class("testButton2"); //apply css

  controls_Box.get_style_context()->add_class("controlBox"); //apply css
  controls_Box.append(testbutton);
  controls_Box.append(testbutton2);


  m_VBox.append(controls_Box);


}

MainMenu::~MainMenu(){
}


void MainMenu::loginPrompt(){

}