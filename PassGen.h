/**
 * @file PassGen.h
 * @author Яшин А.А.
 * @version 1.0
 * @date 15.05.21
 * @copyright ИБСТ ПГУ
 * @brief заголовочный файл для модуля PassGen
 */
#pragma once
#include <iostream>
#include <cassert>
#include <random>
#include <string>
#include <vector>
#include <cstdlib>
#include <unistd.h>
#include "Exception.h"
using namespace std;
///@brief класс Opts, который генерирует пароль по определенным параметрам.
class Opts
{
private:
// константы с пределами значений
    static constexpr int minLen = 8;///< минимальная длина пароля
    static constexpr int maxLen = 32;///< максимальная длина пароля
    static constexpr int minNum = 1;///<минимальное количество паролей
    static constexpr int maxNum = 20;///<максимальное количество паролей
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
    /**
    * @brief Метод usage.
    * @details Выводит справку при неверно указанных параметрах.
    */
    void usage(); 
public:
    /**
     * @brief Конструктор класса Opts
     * @param в конструктор передаются и разбираются все аргументы из командной строки.
     * @throw gen_error, если произошла ошибка.
     */
    Opts(int argc, char* argv[]);
    /**
     * @brief Метод peremeshka_txt
     * @details Перемешивает строку сиволов, из которых будет сгенерирован пароль.
     * @param len длина новой сгенерированной строки.
     * @param alphavit строка символов, из которых произойдет генерация пароля.
     * @throw gen_error, если произошла ошибка.
     * @return Возвращает сгенерированный пароль из определенных символов указанной длины.
     */
    string peremeshka_txt(int len, const string &alphavit);
    /**
     * @brief Метод passgen.
     * @details Генерирует вектор с паролями из определенных символов и определенной длины,
     * которые были указаны пользователем при запуске.
     * @return Возвращает вектор с паролями из определенных символов и определенной длины,
     которые были указаны пользователем при запуске.
     */
    vector<string> passgen();
    ///@brief Метод, возвращающий длину пароля.
    int getLen() const
    {
        return passLen;
    }
    ///@brief Метод, возвращающий количество паролей.
    int getNum() const
    {
        return passNum;
    }
    ///@brief Использование цифр.
    bool isNums() const
    {
        return useNums;
    }
    ///@brief Использование заглавных букв.
    bool isAlpha() const
    {
        return useAlpha;
    }
    ///@brief Использование строчных букв.
    bool isMini() const
    {
        return useMini;
    }
    ///@brief Использование специальных знаков.
    bool isSign() const
    {
        return useSign;
    }
};
