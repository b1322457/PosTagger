//
// Created by 王鹏飞 on 16/1/19.
//

#include <iostream>
#include <locale>
#include <codecvt>
using namespace std;

    namespace strtool {
        extern string trim(const string &str);

        extern int split(const string &str, vector<string> &ret_, string sep = ",");

        extern string replace(const string &str, const string &src, const string &dest);

        static wstring_convert<codecvt_utf8<char32_t>,char32_t> conv;

        extern string To_UTF8(const u32string& from);

        extern string gen_filename(const string &suffix);

    }

