#include "PassGen.h"
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

        }
    }
    if(opt == -1) optind = 1;
    // если не установлено ничего из алфавита - установить все
    if (!useNums && !useAlpha && !useMini && !useSign) {
        useAlpha = useMini = useNums = useSign = true;
    }
}
string Opts::text_shuffling(int len, const string &letters)
{
    random_device rd;
    mt19937_64 gen(rd());
    uniform_int_distribution<unsigned long> dist(0, letters.length() - 1);
    string passwd;
    for (int i = 0; i < len; ++i) {
        passwd += letters[dist(gen)];
    }
    return passwd;
}
vector<string> Opts::passgen()
{
    string letters;
    if (this->isAlpha()) letters += set_Alpha;
    if (this->isMini()) letters += set_Mini;
    if (this->isNums()) letters += set_Nums;
    if (this->isSign()) letters += set_Sign;
    vector<string> pass_list;
    for (int i = 0; i < this->getNum(); ++i) {
        pass_list.push_back(text_shuffling(this->getLen(), letters));
    }
    return pass_list;
}
