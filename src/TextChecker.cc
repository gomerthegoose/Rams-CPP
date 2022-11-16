#include "TextChecker.h"
#include <string>

 TextChecker::dataCheckerReturn TextChecker::validateText(std::string txt){ //checks that a string is valid based off rules
    TextChecker::dataCheckerReturn valid; // create new variable to be returned 
    valid.isValid = true; // set valid to be true by default 

    if(txt == ""){ // check if string is empty
        valid.isValid = false; // returns invalid if string is empty 
        valid.err = errNull;
    }else{
        for (int i = 0; i < numCharsToCheck; i++ ){
            if (txt.find(invalidChars[i]) != std::string::npos){ // chech if string contains invalid character 
                valid.isValid = false; // return invalid if character found
                valid.err = errInvalidChar + invalidChars[i]; // set error message
                break;
            }
        }
    }   
    return valid;
}