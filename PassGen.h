/**
 * @file PassGen.h
 * @author Яшин А.А.
 * @version 1.0
 * @date 2.06.21
 * @copyright ИБСТ ПГУ
 * @brief заголовочный файл для модуля PassGen
 */
#pragma once
#include <iostream>
#include <cassert>
#include <random>
#include <string>
#include <vector>
#include <cstdlib> ///< для функций strtol, exit
#include <unistd.h> ///< для функции getopt
#include "Exception.h"
using namespace std;
///@brief класс Opts
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
    const string set_Sign = "!$%&'()*+,-./\"";
    // атрибуты
    int passLen = minLen; ///< длина пароля
    int passNum = minNum; ///< количество паролей
    bool useNums = false; ///< использовавание цифр
    bool useAlpha = false; ///< использование заглавных букв
    bool useMini = false; ///< использование строчных букв
    bool useSign = false; ///< использование спец. знаков
    void usage(const char* progName); ///<вывод подсказки и останов
public:
    Opts(int argc, char* argv[]); ///< конструктор
    string peremeshka_txt(int len, const string &alphavit);
    vector<string> passgen(); ///< "геттеры" с результатами разбора параметров
    int getLen() const
    {
        return passLen;///@brief длина пароля
    }
    int getNum() const
    {
        return passNum;///@brief кол-во паролей
    }
    bool isNums() const
    {
        return useNums;///@brief исп. цифр
    }
    bool isAlpha() const
    {
        return useAlpha;///@brief исп. заглавных букв
    }
    bool isMini() const
    {
        return useMini;///@brief исп. строчных букв
    }
    bool isSign() const
    {
        return useSign;///@brief исп.  спец. знаков
    }
};
