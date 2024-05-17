#include <UnitTest++/UnitTest++.h>
#include "md5.h"
#include "Client.h"
#include "termcolor.h"

using namespace std;

struct Test {
    Client * p;
    Test()
    {
        p = new Client();
    }
    ~Test()
    {
        delete p;
    }
};

SUITE(Server)
{
// Удачный сценарий
    TEST_FIXTURE(Test, Ok) {
        p->vectora = "/home/stud/Coursework_TIMP/UnitTest/vector.txt";
        p->result = "/home/stud/Coursework_TIMP/UnitTest/otvet.txt";
        p->autification = "/home/stud/Coursework_TIMP/UnitTest/vclient.conf";
        p->Server("127.0.0.1", "33333");
        CHECK(true);
    }
// Не верный ip-адрес
    TEST_FIXTURE(Test, Ip1) {
        p->vectora = "/home/stud/Coursework_TIMP/UnitTest/vector.txt";
        p->result = "/home/stud/Coursework_TIMP/UnitTest/otvet.txt";
        p->autification = "/home/stud/Coursework_TIMP/UnitTest/vclient.conf";
        CHECK_THROW(p->Server("127", "33333"), client_error);
    }
// Пустой адрес    
    TEST_FIXTURE(Test, Ip2) {
        p->vectora = "/home/stud/Coursework_TIMP/UnitTest/vector.txt";
        p->result = "/home/stud/Coursework_TIMP/UnitTest/otvet.txt";
        p->autification = "/home/stud/Coursework_TIMP/UnitTest/vclient.conf";
        CHECK_THROW(p->Server(" ", "33333"), client_error);
    }
// Не верный порт
    TEST_FIXTURE(Test, Port1) {
        p->vectora = "/home/stud/Coursework_TIMP/UnitTest/vector.txt";
        p->result = "/home/stud/Coursework_TIMP/UnitTest/otvet.txt";
        p->autification = "/home/stud/Coursework_TIMP/UnitTest/vclient.conf";
        CHECK_THROW(p->Server("127.0.0.1", "7777"), client_error);
    }
// Пустой порт
	TEST_FIXTURE(Test, Port2) {
        p->vectora = "/home/stud/Coursework_TIMP/UnitTest/vector.txt";
        p->result = "/home/stud/Coursework_TIMP/UnitTest/otvet.txt";
        p->autification = "/home/stud/Coursework_TIMP/UnitTest/vclient.conf";
        CHECK_THROW(p->Server("127.0.0.1", " "), client_error);
    }
// Пустой файл авторизации
    TEST_FIXTURE(Test, Aut1) {
        p->vectora = "/home/stud/Coursework_TIMP/UnitTest/vector.txt";
        p->result = "/home/stud/Coursework_TIMP/UnitTest/otvet.txt";
        p->autification = "/home/stud/Coursework_TIMP/UnitTest/empty.txt";
        CHECK_THROW(p->Server("127.0.0.1", "33333"), client_error);
    }
// Неверный логин
    TEST_FIXTURE(Test, Login) {
        p->vectora = "/home/stud/Coursework_TIMP/UnitTest/vector.txt";
        p->result = "/home/stud/Coursework_TIMP/UnitTest/otvet.txt";
        p->autification = "/home/stud/Coursework_TIMP/UnitTest/Erroruser.conf";
        CHECK_THROW(p->Server("127.0.0.1", "33333"), client_error);
    }
// Неверный пароль
    TEST_FIXTURE(Test, Parol) {
        p->vectora = "/home/stud/Coursework_TIMP/UnitTest/vector.txt";
        p->result = "/home/stud/Coursework_TIMP/UnitTest/otvet.txt";
        p->autification = "/home/stud/Coursework_TIMP/UnitTest/Errorpswd.conf";
        CHECK_THROW(p->Server("127.0.0.1", "33333"), client_error);
    }
// Не правильный путь к векторам
    TEST_FIXTURE(Test, Vector1) {
        p->vectora = "/home/stud/vector.txt";
        p->result = "/home/stud/Coursework_TIMP/UnitTest/otvet.txt";
        p->autification = "/home/stud/Coursework_TIMP/UnitTest/vclient.conf";
        CHECK_THROW(p->Server("127.0.0.1", "33333"), client_error);
    }
// Пустые вектора
    TEST_FIXTURE(Test, Vector2){
        p->vectora = "/home/stud/Coursework_TIMP/UnitTest/empty.txt";
        p->result = "/home/stud/Coursework_TIMP/UnitTest/otvet.txt";
        p->autification = "/home/stud/Coursework_TIMP/UnitTest/vclient.conf";
        CHECK_THROW(p->Server("127.0.0.1", "33333"), client_error);
    }
// Не правильный путь к файлу с результатами    
    TEST_FIXTURE(Test, Rez) {
        p->vectora = "/home/stud/Coursework_TIMP/UnitTest/vector.txt";
        p->result = "/home/otvet.txt";
        p->autification = "/home/stud/Coursework_TIMP/UnitTest/vclient.conf";
        CHECK_THROW(p->Server("127.0.0.1", "33333"), client_error);
    }
// Не правильный путь к файлу с авторизацией
    TEST_FIXTURE(Test, InvalidVectorFile) {
    	p->vectora = "/home/stud/Coursework_TIMP/UnitTest/vector.txt";
    	p->result = "/home/stud/Coursework_TIMP/UnitTest/otvet.txt";
    	p->autification = "/home/stud/Desktop/vclient.conf";
    	CHECK_THROW(p->Server("127.0.0.1", "33333"), client_error);
	}   
}

int main(){
    return UnitTest::RunAllTests();
}
