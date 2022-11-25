// - Goose -
// 16/11/2022

#include<string>

class ParseFile
{   
public:
  struct UserInfo
  {
    int id;
    int staffID;
    std::string username;
    std::string password;
    int accessLevel;
    bool loginSuccess;
  };

  UserInfo userDetails(std::string fileLocation, std::string username ,std::string password);

protected:
  

};