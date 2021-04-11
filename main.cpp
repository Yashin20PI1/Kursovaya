
#include "PassGen.h"
int main(int argc, char **argv)
{
    Opts op(argc, argv); // реализуем разбор ПКС
// получаем результат разбора ПКС
    std::cout<<op.getLen()<<std::endl;
    std::cout<<op.getNum()<<std::endl;
    std::cout<<std::boolalpha;
    std::cout<<op.isNums()<<std::endl;
    std::cout<<op.isAlpha()<<std::endl;
    std::cout<<op.isMini()<<std::endl;
    std::cout<<op.isSign()<<std::endl;
// в близжайшем времени здесь будет генератор
    return 0;
}
