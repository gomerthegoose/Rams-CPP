#include "ParseFile.h"
#include "cryptography.h"
#include "csv.h"
#include <string>
#include <fstream>
#include <iostream>
#include <string>
//#include <cstring>
//#include <ifstream>

Cryptography cryptography1;

ParseFile::UserInfo ParseFile::userDetails (std::string fileLocation, std::string username ,std::string password){
  ParseFile::UserInfo output;

  io::CSVReader<5> in(fileLocation);
  in.read_header(io::ignore_extra_column,"id","staffID", "username", "password", "accessLevel");
  while(in.read_row(output.id,output.staffID, output.username, output.password, output.accessLevel)){

    output.loginSuccess = false; //login fail by default

    if (cryptography1.DecryptString(output.username) == username && cryptography1.DecryptString(output.password) == password){ // decrypt username and password and match to enterd information
      output.loginSuccess = true; // login succesful if details match
      std::cout << "Login Success!" << std::endl; //log login success
      output.id = std::stoi(cryptography1.DecryptString(std::to_string(output.id))); //decrypt id 
      output.staffID = std::stoi(cryptography1.DecryptString(std::to_string(output.staffID)));
      output.accessLevel = std::stoi(cryptography1.DecryptString(std::to_string(output.accessLevel))); // re add error for school
      return output;
    }
  }
  return output;
}