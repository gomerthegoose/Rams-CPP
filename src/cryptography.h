// - Goose -
// 16/11/2022

#include<string>

class Cryptography
{
public:

    Cryptography();
    virtual ~Cryptography();

    std::string EncryptString(std::string input); // decrypt String

    std::string DecryptString(std::string input); // encrypt string

protected:
};