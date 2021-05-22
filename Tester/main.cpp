#include <UnitTest++/UnitTest++.h>
#include "/home/student/kursovaya.rabota/main2/PassGen.h"
#include "/home/student/kursovaya.rabota/main2/PassGen.cpp"
#include "/home/student/kursovaya.rabota/main2/Exception.h"
int argc_6 = 7;
int argc_2 = 2;
char *argv_1[] = { "./main2","-l 30", "-n 12", "-0", "-a", "-m", "-s"};
char *argv_2[] = {"./main2", "-l 7"};
char *argv_3[] = {"./main2", "-l 50"};
char *argv_4[] = {"./main2", "-n 0"};
char *argv_5[] = {"./main2", "-n 50"};
char *argv_6[] = {"./main2", "-e"};
char *argv_7[] = {"./main2", "-a", "-s", "m", "-0", "-l 30", "-n 12"};
char *argv_8[] = {"./main2", ""};
SUITE(TESTIROVANIE)
{
    TEST(Vernie_argument) {
        Opts pass(argc_6, argv_1);
        CHECK(true);
    }
    TEST(dlina_parol_menshe_8) {
        CHECK_THROW(Opts pass(argc_2, argv_2), gen_error);
    }

    TEST(dlina_parol_bolshe_40) {
        CHECK_THROW(Opts pass(argc_2, argv_3), gen_error);
    }
    TEST(kolvo_parol_menshe_1) {
        CHECK_THROW(Opts pass(argc_2, argv_4), gen_error);
    }
    TEST(kolvo_parol_bolshe_20) {
        CHECK_THROW(Opts pass(argc_2, argv_5), gen_error);
    }
    TEST(invalid_paramtr) {
        CHECK_THROW(Opts pass(argc_2, argv_6), gen_error);
    }
    TEST(peremeshka_argumentov) {
        Opts pass(argc_6, argv_7);
        CHECK(true);
    }
    TEST(pustota) {
        Opts pass(argc_2, argv_8);
        CHECK(true);
    }
    
}
struct Arg_fix {
    Opts * a;
    Arg_fix()
    {
        a = new Opts(argc_2, argv_8);
    }~Arg_fix()
    {
        delete a;
    }
};
SUITE(peremeshka_txt)
{
    TEST_FIXTURE(Arg_fix, ravn_dlina_strk) {
        a->peremeshka_txt(10, "Ff123(!KKK");
        CHECK(true);
    }
    TEST_FIXTURE(Arg_fix, dlina_bolshe_strk) {
        a->peremeshka_txt(11, "Ff123(!KKK");
        CHECK(true);
    }
    TEST_FIXTURE(Arg_fix, dlina_menshe_strk) {
        a->peremeshka_txt(9, "Ff123(!KKK");
        CHECK(true);
    }
    TEST_FIXTURE(Arg_fix, russkie_bukv) {
        a->peremeshka_txt(10, "Гг123(!ЦЦЦ");
        CHECK(true);
    }
    TEST_FIXTURE(Arg_fix, nulevaya_dlina) {
        CHECK_THROW(a->peremeshka_txt(0, "Ff123(!KKK"), gen_error);
    }
    TEST_FIXTURE(Arg_fix, pustaya_strk) {
        CHECK_THROW(a->peremeshka_txt(10, ""), gen_error);
    }

}
int main(int argc, char **argv)
{
    return UnitTest::RunAllTests();
}
