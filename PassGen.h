#include <iostream>
#include <cstdlib> // для функций strtol, exit
#include <unistd.h> // для функции getopt
// реализация интерфейса в виде класса
class Opts {
private:
// константы с пределами значений
static constexpr int minLen = 8;
static constexpr int maxLen = 32;
static constexpr int minNum = 1;
static constexpr int maxNum = 20;
// атрибуты
int passLen = minLen; // длина пароля
int passNum = minNum; // количество паролей
bool useNums = false; // использовавание цифр
bool useAlpha = false; // использование прописных букв
bool useMini = false; // использование строчных букв
bool useSign = false; // использование знаков
void usage(const char* progName); //вывод подсказки и остановки
public:
Opts(int argc, char **argv); // конструктор
// "геттеры" с результатами разбора параметров
int getLen() {return passLen;} //длина пароля
int getNum() {return passNum;} //кол-во паролей
bool isNums() {return useNums;} // исп. цифр
bool isAlpha() {return useAlpha;} // исп. прописных букв
bool isMini() {return useMini;} // исп. строчных букв
bool isSign() {return useSign;} // исп. спец. знаков
};