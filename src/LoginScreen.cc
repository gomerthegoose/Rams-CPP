
#include "LoginWindow.h"
#include "TextChecker.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <String>

#define UserFile "\\UserDetails\\LoginDetails.txt"
using namespace std;

TextChecker textCheck;
//ErrorMsg errorMsg;

struct UserInfo
{
  int id;
  std::string username;
  std::string password;
};

LoginWindow::LoginWindow(): m_VBox(Gtk::Orientation::VERTICAL)
{
  g_object_set(gtk_settings_get_default(),"gtk-application-prefer-dark-theme", TRUE,NULL); //set dark mode

  set_size_request(200, 100); //set default size of window  
  set_title("Login"); // title
  set_resizable(false); // make window non resizable
  set_child(m_VBox);
  m_VBox.append(m_HBox);

  auto css = Gtk::CssProvider::create();//create new css object
  css->load_from_path("./Style.css"); //import css

  get_style_context()->add_provider_for_display(Gdk::Display::get_default(), css, GTK_STYLE_PROVIDER_PRIORITY_APPLICATION); //something
    
  // - Username Entry txtBox -
  UsernameEnrty_txt.set_max_length(50);
  UsernameEnrty_txt.set_placeholder_text("Username"); //text shown when txtbox is empty
  UsernameEnrty_txt.select_region(0, UsernameEnrty_txt.get_text_length());
  UsernameEnrty_txt.get_style_context()->add_class("userDetailsTxt"); //apply css
  m_VBox.append(UsernameEnrty_txt);

  // - Password Entry txtBox -
  PasswordEntry_txt.property_placeholder_text() = "Password"; //placeholder text for password entry
  PasswordEntry_txt.get_style_context()->add_class("userDetailsTxt"); //apply css
  m_VBox.append(PasswordEntry_txt);

  // - login Btn -
  Login_btn.set_label("Login"); //text on button
  Login_btn.signal_clicked().connect( sigc::mem_fun(*this,&LoginWindow::HandleLogin) ); //set callback function
  Login_btn.set_expand();
  Login_btn.get_style_context()->add_class("loginBtn"); //apply css
  set_default_widget(Login_btn);
  m_VBox.append(Login_btn);

  // - Login Error Message -
  loginError_msg.reset(new Gtk::MessageDialog(*this, "loginError"));
  loginError_msg->set_modal(true);
  loginError_msg->set_hide_on_close(true);
  loginError_msg->set_icon_name("Error");
  loginError_msg->signal_response().connect(sigc::hide(sigc::mem_fun(*loginError_msg, &Gtk::Widget::hide)));

}

LoginWindow::~LoginWindow()
{
}

void LoginWindow::HandleLogin()
{
  UserInfo userInfo; //store current users information
  string loginError = ""; // store error message

 if( textCheck.validateText(UsernameEnrty_txt.get_text()).isValid){ // validate user entry
   userInfo.username = UsernameEnrty_txt.get_text();
 }else{
   loginError = textCheck.validateText(UsernameEnrty_txt.get_text()).err;
 }

 if( textCheck.validateText(PasswordEntry_txt.get_text()).isValid){ // validate user entry
   userInfo.password = PasswordEntry_txt.get_text();
 }else{
   loginError = textCheck.validateText(PasswordEntry_txt.get_text()).err;
 }

  if (loginError != ""){ // display error message if error variable is not empty  
    loginError_msg->set_message(loginError);
    loginError_msg->show();
  }
}