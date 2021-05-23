/**
 * @file main.cpp
 * @author Яшин А.А.
 * @version 1.0
 * @date 15.05.21
 * @copyright ИБСТ ПГУ
 * @brief главный модуль Генератора паролей
 */
#include "PassGen.h"
int main(int argc, char* argv[])
{
    try {
        Opts letsgo(argc, argv);
        for (auto &pass : letsgo.passgen())
            cout << pass << endl;
    } catch (const gen_error & e) {
        cerr << e.what() << endl;
    }
    return 0;
}
