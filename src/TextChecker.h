#include<string>
class TextChecker 
{
public:


  struct dataCheckerReturn{
    bool isValid; // returns true if string has invalid character 
    std::string err; //to return error 
  };


  dataCheckerReturn validateText(std::string txt); // function to check string 



protected:
  #define numCharsToCheck 2 // number of characters to check
  #define errInvalidChar "Invalid Character: " // error message if there is invalid character 
  #define errNull "Field can't be Empty"  // error message if string is empty
  std::string invalidChars[numCharsToCheck] = {",","\n"}; //invalid characters 
};