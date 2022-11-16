#include <string>
#include "cryptography.h"
#include <iostream>

std::string Cryptography::DecryptString(std::string input){
    std::string Output ="";
    for (int i = 0; i < input.length(); i++){
        if (&input[i] != ","){
            Output += (input[i] - 3);
        }    
    }
    return Output;
}

std::string Cryptography::EncryptString(std::string input){
    std::string Output ="";
    for (int i = 0; i < input.length(); i++){
        if (&input[i] != ","){
            Output += (input[i] + 3);
        } 
    }
    return Output;
}