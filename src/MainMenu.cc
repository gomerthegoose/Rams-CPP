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


<<<<<<< HEAD
  Gtk::Grid* grid = Gtk::manage(new Gtk::Grid());

  StaffButton.set_label("Staff");
  StaffButton.signal_clicked().connect( sigc::mem_fun(*this,&MainMenu::loginPrompt) ); //set callback function
  grid->attach(StaffButton, 1,1,2,1);

  StockButton.set_label("Stock");
  StockButton.signal_clicked().connect( sigc::mem_fun(*this,&MainMenu::loginPrompt) ); //set callback function
  grid->attach(StockButton,1,3,2,1);

  ThursdayBookingButton.set_label("Thursday Bookings");
  ThursdayBookingButton.signal_clicked().connect( sigc::mem_fun(*this,&MainMenu::loginPrompt) ); //set callback function
  grid->attach(ThursdayBookingButton,1,5,2,1);

  SundayBookingButton.set_label("Sunday Bookings");
  SundayBookingButton.signal_clicked().connect( sigc::mem_fun(*this,&MainMenu::loginPrompt) ); //set callback function
  grid->attach(SundayBookingButton,1,7,2,1);

  exitButton.set_label("Exit");
  exitButton.signal_clicked().connect( sigc::mem_fun(*this,&MainMenu::loginPrompt) ); //set callback function
  grid->attach(exitButton,1,8,2,1);


  
  
  
  
  controls_Frame.set_child(*grid);
  m_VBox.append(controls_Frame);
=======
  testbutton2.set_label("test2");
  testbutton2.signal_clicked().connect( sigc::mem_fun(*this,&MainMenu::loginPrompt) ); //set callback function
  testbutton2.get_style_context()->add_class("testButton2"); //apply css

  controls_Box.get_style_context()->add_class("controlBox"); //apply css
  controls_Box.append(testbutton);
  controls_Box.append(testbutton2);


  m_VBox.append(controls_Box);
>>>>>>> 8039a2770487db7545460db4a32ae64818065fa4


}




MainMenu::~MainMenu(){
}


void MainMenu::loginPrompt(){
  std::cout << "Top Tear Garbage" << std::endl;
  controls_Frame.hide();
}
