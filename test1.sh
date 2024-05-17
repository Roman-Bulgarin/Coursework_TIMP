#!/bin/bash

# Проверка корректного ввода данных
echo "Тест 1: Корректный ввод данных"
./client -a 127.0.0.1 -p 33333 -v vector.txt -r otvet.txt -l vclient.conf
