/**
 * @file PassGen.cpp
 * @author Яшин А.А.
 * @version 1.0
 * @date 2.06.21
 * @copyright ИБСТ ПГУ
 * @brief модуль PassGen
 */
#include "PassGen.h"
/**
 * @brief Конструктор класса Opts
 * @param в конструктор передаются и разбираются все аргументы из командной строки.
 * @throw gen_error, если произошла ошибка.
 */
Opts::Opts(int argc, char* argv[])
{
    int opt;
    while ((opt = getopt(argc, argv, "l:n:0ams")) != -1) {
        switch (opt) {
        case 'l': { // длина пароля
            passLen = strtol(optarg,nullptr,10);
            if (passLen < minLen || passLen > maxLen) {
                optind = 1;
                throw gen_error(string("passLen must be from 8 to 32\n"));
            }
            break;
        }
        case 'n': { // кол-во паролей
            passNum = strtol(optarg,nullptr,10);
            if (passNum < minNum || passNum > maxNum) {
                // если ошибка - сообщить и завершить
                optind = 1;
                throw gen_error(string("passNum must be from 1 to 20\n"));
            }
            break;
        }
        case '0': // исп. цифры
            useNums = true;
            break;
        case 'a': // исп. заглавные буквы
            useAlpha = true;
            break;
        case 'm': // исп. строчные буквы
            useMini = true;
            break;
        case 's': // исп. знаки
            useSign = true;
            break;
        case '?':
            // неверный параметр
            throw gen_error(std::string("invalid argument\n"));
          
        }
    }

    if(opt == -1) optind = 1;
    // если не установлено ничего из алфавита - установить все
    if (!useNums && !useAlpha && !useMini && !useSign) {
        useAlpha = useMini = useNums = useSign = true;
    }
}
/**
 * @brief Метод peremeshka_txt
 * @details Перемешивает строку сиволов, из которых будет создана новая строка.
 * @param len длина новой сгенерированной строки.
 * @param alphavit строка символов, из которых произойдет генерация новой строки.
 * @throw gen_error, если произошла ошибка.
 * @return Возвращает перемешанную строку из определенных символов указанной длины.
 */
string Opts::peremeshka_txt(int len, const string &alphavit)

{
    if(alphavit.empty()) 
        throw gen_error(std::string("пустая строка символов для пароля\n"));
    if(len == 0) 
        throw gen_error(std::string("нулевая длина строки\n"));
    assert(alphavit.length() != 0);
    random_device rd;
    mt19937_64 gen(rd());
    uniform_int_distribution<unsigned long> dist(0, alphavit.length() - 1);
    string passwd;
    for (int i = 0; i < len; ++i) {
        passwd += alphavit[dist(gen)];
    }
    return passwd;
}
/**
 * @brief Метод passgen.
 * @details Генерирует вектор с паролями из определенных символов.
 * @return Возвращает вектор с паролями из определенных символов.
 */
vector<string> Opts::passgen()
{
    string alphavit;
    if (isAlpha()) alphavit += set_Alpha;
    if (isMini()) alphavit += set_Mini;
    if (isNums()) alphavit += set_Nums;
    if (isSign()) alphavit += set_Sign;
    vector<string> pass_list;
    for (int i = 0; i < getNum(); ++i) {
        pass_list.push_back(peremeshka_txt(getLen(), alphavit));
    }
    return pass_list;
}
/**
 * @brief Метод usage.
 * @details Выводит справку и досрочно завершает программу.
 */
void Opts::usage(const char* progName)
{
    cout<<"Usage: "<<progName<<" [-l pass_len] [-n pass_num] [-0] [-a] [-m] [-s]\n";
    exit(1);
}
