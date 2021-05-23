/**
 * @file Exception.h
 * @author Яшин А.А.
 * @version 1.0
 * @date 15.05.21
 * @copyright ИБСТ ПГУ
 * @brief модуль исключений Exception
 */
#pragma once
#include<stdexcept>
using namespace std;
/// @brief Класс для обработки ошибок, которые могут возникнуть при взаимодействии с программой
/// @details Класс наследует существующий класс обработки исключений с именем "invalid_argument" из библиотеки "stdexcept".
class gen_error: public invalid_argument
{
public:
    /** @brief  Конструктор с параметрами
         * @param what_arg - строка, хранящая описание ошибки. Данный параметр перегружается конструктором класса "invalid_argument"
         * */
    explicit gen_error (const string& what_arg):invalid_argument(what_arg) {}
};
