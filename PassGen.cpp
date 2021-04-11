#include "PassGen.h"
Opts::Opts(int argc, char **argv)
{
    int opt;
    while ((opt = getopt(argc, argv, "l:n:0amsh")) != -1) {
        switch (opt) {
        case 'l': // длина пароля
            passLen = strtol(optarg,nullptr,10);
            if (passLen < minLen || passLen > maxLen) {
                // если ошибка - сообщить и завершить
                std::cerr<<"passLen must be from 8 to 32\n";
                usage(argv[0]);
            }
            break;
        case 'n': // кол-во паролей
            passNum = strtol(optarg,nullptr,10);
            if (passNum < minNum || passNum > maxNum) {
                // если ошибка - сообщить и завершить

                std::cerr<<"passNum must be from 1 to 20\n";
                usage(argv[0]);
            }
            break;
        case '0': // исп. цифры
            useNums = true;
            break;
        case 'a': // исп. прописные буквы
            useAlpha = true;
            break;
        case 'm': // исп. строчные буквы
            useMini = true;
            break;
        case 's': // исп. спец. знаки
            useSign = true;
            break;
        case 'h': // -h help
        case '?': // неверный параметр
        case ':': // нет значения у параметра
            usage(argv[0]); // сообщить и завершить
        }
    }
    // если не установлено ничего из алфавита - установить все
    if (!useNums && !useAlpha && !useSign && !useMini) {
        useAlpha = useNums = useSign = useMini = true;
    }
}
// краткая справки и досрочное завершение программы
void Opts::usage(const char* progName)
{
    std::cout<<"Usage: "<<progName<<" [-l pass_len] [-n pass_num] [-0] [-a] [-m] [-s]\n";
    exit(1);
}
