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


ParseFile::UserInfo ParseFile::userDetails (std::string fileLocation , int id){
  ParseFile::UserInfo output;

  io::CSVReader<4> in(fileLocation);
  in.read_header(io::ignore_extra_column, "id", "username", "password", "accessLevel");
  while(in.read_row(output.id, output.username, output.password, output.accessLevel)){

    
    
    output.id = std::stoi(cryptography1.DecryptString(std::to_string(output.id)));
    output.username = cryptography1.DecryptString(output.username);
    output.password = cryptography1.DecryptString(output.password);
    output.accessLevel = std::stoi(cryptography1.DecryptString(std::to_string(output.accessLevel)));

    std::cout << output.id << std::endl;
    std::cout << output.username << std::endl;
    std::cout << output.password << std::endl;
    std::cout << output.accessLevel << std::endl;

  }
  return output;
}