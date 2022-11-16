#include "ParseFile.h"
#include "cryptography.h"
#include <string>
#include <fstream>
#include <iostream>




ParseFile::UserInfo ParseFile::userDetails (std::string fileLocation){
    std::ifstream userFile(fileLocation);
    std::string rawUserDetails;

    ParseFile::UserInfo test;

    if (userFile.is_open())
    {
        while (getline (userFile,rawUserDetails) )
        {
          std::cout << rawUserDetails << '\n';
        }
        userFile.close();
    }
    return test;
}