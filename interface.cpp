/**
* @file interface.cpp
* @author Булгарин Р.Р.
* @version 1.0
* @date 11.05.2024
* @copyright ИБСТ ПГУ
* @brief Интерфейс программы
*/

// Наш клиент, который отвечает за взаимодействие с сервером и обработку ошибок
#include "Client.h"
// Библиотека для изменения цвета в консоли (выбрано для более удобного взаимодействия пользователя с интерфейсом)
#include "termcolor.h"

using namespace std;

// @brief Основная функция интерфейса
int main (int argc, char *argv[])
{
	// Соединение
    Client Soedinenie;
	// Справка при запуске программы без параметров
    if(argc == 1) {
        cout << termcolor::bold << termcolor::cyan << "Добро пожаловать, перед вами программа-клиент от Романа Булгарина." << termcolor::reset << endl;
        cout << termcolor::bold << termcolor::cyan <<"Перед применением рекомендуем тщательно ознакомиться." << termcolor::reset << endl;
        cout << termcolor::bold << termcolor::cyan << "Список опций:" << termcolor::reset << endl;
        cout << termcolor::bold << termcolor::yellow << "-help или -h — справка по использованию программы" << termcolor::reset << endl;
       	cout << termcolor::bold << termcolor::yellow << "-a — адрес сервера -> обязательный"  << termcolor::reset << endl;
        cout << termcolor::bold << termcolor::yellow << "-p — порт сервера -> обязательный" << termcolor::reset << endl;
        cout << termcolor::bold << termcolor::yellow << "-v — имя файла с исходными данными -> обязательный"<< termcolor::reset  << endl;
        cout << termcolor::bold << termcolor::yellow << "-r — имя файла в который необходимо сохранить результат -> обязательный" << termcolor::reset << endl;
        cout << termcolor::bold << termcolor::yellow << "-l — имя файла для авторизации -> обязательный" << termcolor::reset << endl;
        return 0;
    }

    string str1;
    string str2;

    int opt;
    // @brief Кейсы с параметрами, которые доступны для ввода
    
    while ((opt=getopt (argc,argv,"ha:p:v:r:l:"))!=-1) {

        switch(opt) {
        
		// @brief Кейс со справкой об использовании программы
        case 'h':
        	cout << termcolor::bold << termcolor::cyan << "Добро пожаловать, перед вами программа-клиент от Романа Булгарина." << termcolor::reset << endl;
        cout << termcolor::bold << termcolor::cyan <<"Перед применением рекомендуем тщательно ознакомиться." << termcolor::reset << endl;
        cout << termcolor::bold << termcolor::cyan << "Список опций:" << termcolor::reset << endl;
        cout << termcolor::bold << termcolor::yellow << "-help или -h — справка по использованию программы" << termcolor::reset << endl;
       	cout << termcolor::bold << termcolor::yellow << "-a — адрес сервера -> обязательный"  << termcolor::reset << endl;
        cout << termcolor::bold << termcolor::yellow << "-p — порт сервера -> обязательный" << termcolor::reset << endl;
        cout << termcolor::bold << termcolor::yellow << "-v — имя файла с исходными данными -> обязательный"<< termcolor::reset  << endl;
        cout << termcolor::bold << termcolor::yellow << "-r — имя файла в который необходимо сохранить результат -> обязательный" << termcolor::reset << endl;
        cout << termcolor::bold << termcolor::yellow << "-l — имя файла для авторизации -> обязательный" << termcolor::reset << endl;
            return 0;
        
        // @brief Кейс для установки адреса сервера
        case 'a':
            str1 = string(optarg);
            break;
            
		// @brief Кейс для установки порта сервера
        case 'p':
                str2 = string(optarg);
            break;
            
        // @brief Кейс для входного текстового файла    
        case 'v':
            Soedinenie.vectora = string(optarg);
            break;
            
		// @brief Кейс для выходного текстового файла
        case 'r':
            Soedinenie.result = string(optarg);
            break;
            
		// @brief Кейс для файла с логином и паролем
        case 'l':
            Soedinenie.autification = string(optarg);
            break;
            
		// @brief Кейс для неизвестных параметров -> выдаёт ошибку
        case '?':
            cout << termcolor::bold << termcolor::yellow<< "Неверный параметр -> ознакомьтесь со справкой (-h или -help)" << termcolor::reset << endl;
            return 0;
        };
    };

    Soedinenie.Server(str1, str2);
    return 0;
};
