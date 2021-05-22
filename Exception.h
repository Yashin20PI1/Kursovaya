/**
 * @file Exception.h
 * @author Яшин А.А.
 * @version 1.0
 * @date 2.06.21
 * @copyright ИБСТ ПГУ
 * @brief модуль исключений Exception
 */
#pragma once
using namespace std;
class gen_error: public invalid_argument
{
public:
    explicit gen_error (const string& what_arg):invalid_argument(what_arg) {}
};
