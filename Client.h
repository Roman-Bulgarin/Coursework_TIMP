/**
* @file Client.h
* @author Булгарин Р.Р.
* @version 1.0
* @date 11.05.2024
* @copyright ИБСТ ПГУ
* @brief Загаловочный файл для модуля Client
*/
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <arpa/inet.h>

using namespace std;
// @brief Класс клиента с переменными
class Client
{
public:
    int Server(string str1, string str2);
    // @param Порт
    int port;
    // @param Сумма в кодировке int64_t
    int64_t summa;
    // @param Сообщение
    string massage;
    // @param Переменная для векторов
    string vectora;
    // @param Переменная для записи результата
    string result;
    // @param Переменная для аутентификации
    string autification;
    // @param Переменная для записи Логина
    string username;
    // @param Переменная для записи Пароля
    string password;
    string line;
};
// @brief Класс обработки ошибок
class client_error: public invalid_argument
{
public:
    explicit client_error (const string& what_arg):
        invalid_argument(what_arg) {}
    explicit client_error (const char* what_arg):
        invalid_argument(what_arg) {}
};
