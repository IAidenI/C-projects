#include"fonction.h"

int main(int argc, char* argv[])
{
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " password" << std::endl;
        return 1;
    }

    bool check;
    std::string hash1 = "11554930";
    std::string hash2 = "aPFFCVAT";

    std::string* password_saisie;
    password_saisie = new std::string[20];

    std::string* password;
    password = new std::string[50];

    *password_saisie = argv[1];

    xor_string(password, hash1, hash2);

    if (*password_saisie == *password)
    {
        std::cout << "Bien joué, le mot de passe est : " << *password << std::endl;
    }
    else
    {
        std::cout << "Mauvais mot de passe" << std::endl;
    }

    return 0;
}
