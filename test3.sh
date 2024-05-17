#!/bin/bash

# Проверка неверного адреса сервера
echo "Тест 3: Вывод ошибки при неверном ip-адресе"
./client -a 127 -p 33333 -v vector.txt -r otvet.txt -l vclient.conf
