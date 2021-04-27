#pragma once
using namespace std;
class gen_error: public invalid_argument
{
public:
    explicit gen_error (const string& what_arg):invalid_argument(what_arg) {}
};
