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
