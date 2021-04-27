#pragma once
#include <iostream>
#include <cassert>
#include <random>
#include <string>
#include <vector>
#include <cstdlib> // для функций strtol, exit
#include <unistd.h> // для функции getopt
#include "Exception.h"
using namespace std;
class Opts
{
private:
// константы с пределами значений
    static constexpr int minLen = 8;
    static constexpr int maxLen = 32;
    static constexpr int minNum = 1;
    static constexpr int maxNum = 20;
    const string set_Alpha="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const string set_Mini="abcdefghijklmnopqrstuvwxyz";
    const string set_Nums = "0123456789";
    const string set_Sign = ".,<>?!/|\\@#$%^&*()[]";
    // атрибуты
    int passLen = minLen; // длина пароля
    int passNum = minNum; // количество паролей
    bool useNums = false; // использовавание цифр
    bool useAlpha = false; // использование заглавных букв
    bool useMini = false; // использование строчных букв
    bool useSign = false; // использование спец. знаков
    void usage(const char* progName); //вывод подсказки и останов
public:
    Opts(int argc, char* argv[]); // конструктор
    string text_shuffling(int len, const string &letters);
    vector<string> passgen();// "геттеры" с результатами разбора параметров
    int getLen() const
    {
        return passLen;   //длина пароля
    }
    int getNum() const
    {
        return passNum;   //кол-во паролей
    }
    bool isNums() const
    {
        return useNums;   // исп. цифр
    }
    bool isAlpha() const
    {
        return useAlpha;   // исп. заглавных букв
    }
    bool isMini()
    {
        return useMini;   // исп. строчных букв
    }
    bool isSign() const
    {
        return useSign;    // исп.  спец. знаков
    }
};
