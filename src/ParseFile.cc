#include "ParseFile.h"
#include "cryptography.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cstring>
//#include <vector>
//#include <iomanip>

Cryptography cryptography1;


ParseFile::UserInfo ParseFile::userDetails (std::string fileLocation){
    std::ifstream userFile(fileLocation);
    std::string rawUserDetails;
    std::string temp;
    int i = 0;

    std::vector<std::string> rawUserDetailsParsed;

    ParseFile::UserInfo output ;



    if (userFile.is_open())
    {
        while (getline (userFile,rawUserDetails) )
        {
          rawUserDetails = cryptography1.DecryptString(rawUserDetails); // decrypt raw data

          char *token = std::strtok(rawUserDetails, ",");
          while (token) {
          std::cout << std::quoted(token) << ' ';
          token = std::strtok(nullptr, delimiters);
        }
        userFile.close();
    }
    else{
      std::cout << "Failed To Open File" << std::endl;
    }
    return output;
}