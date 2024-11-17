#include <iostream>
#include <vector>
#include <string>


class encoder
{
private:
    std::vector<char> user_text;
    std::vector<char> user_key;
    std::vector<char> secret_key{ 'g', '9', 'V', 'q', '%', '1', ')', 'l' };



public:

    void coder(std::vector<char>& user_text, std::vector<char>& user_key)
    {
        this->user_text = user_text;
        this->user_key = user_key;

        for (size_t i = 0; i < user_text.size(); i++)
        {
            int j = 0;
            if (j == user_key.size()) { j == 0; };
            user_text[i] = user_text[i] ^ user_key[j];
            j++;

        }
    }

    void sys_coder(std::vector<char>& user_text, std::vector<char>& secret_key)
    {
        this->user_text = user_text;
        this->secret_key = secret_key;

        for (size_t i = 0; i < user_text.size(); i++)
        {
            int j = 0;
            if (j == 7) { j == 0; };
            user_text[i] = user_text[i] ^ secret_key[j];
            j++;

        }
    }

    void e_coder()
    {
        this->user_text = user_text;
        this->user_key = user_key;
        this->secret_key = secret_key;

        coder(user_text, user_key);
        sys_coder(user_text, secret_key);
        coder(user_text, user_key);
    }

    void set_text()
    {
        std::string input_user_text;
        std::cout << "Введите текст" << std::endl;
        std::getline(std::cin, input_user_text);
        user_text.assign(input_user_text.begin(), input_user_text.end());

    }

    void set_key()
    {
        std::string input_user_key;
        std::cout << "Введите текст" << std::endl;
        std::getline(std::cin, input_user_key);
        user_key.assign(input_user_key.begin(), input_user_key.end());
    }

    void print()
    {
        for (size_t i = 0; i < user_text.size(); i++)
        {
            std::cout << user_text[i] << ' ';
        }
    }

};



int main()
{
    setlocale(LC_ALL, "RU");

    encoder user;
    char request[12];

    std::string input_user_key;

    std::cout << "Шифрование / Дешифрование " << std::endl;
    std::cin >> request;
    if (request == "Шифрование")
    {
        user.set_text();
        user.set_key();
        user.e_coder();
        user.print();

    }
    else if (request == "Дешифрование")
    {
        //вызывать фунцию дешифрования
    }
    /*else
    {
      std::cout << "Нету такого варианта" << std::endl;
    }*/


    return 0;
}