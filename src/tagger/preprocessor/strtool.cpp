//
// Created by 王鹏飞 on 16/3/14.
//

#include <iostream>
#include <sstream>
#include <vector>
#include <time.h>
#include <tagger/preprocessor/strtool.h>
using namespace std;

     string strtool::trim(const string &str) {
        string::size_type pos = str.find_first_not_of(" \n\r");
        if (pos == string::npos) {
            return str;
        }
        string::size_type pos2 = str.find_last_not_of(" \n\r");
        if (pos2 != string::npos) {
            return str.substr(pos, pos2 - pos + 1);
        }
        return str.substr(pos);
    }

    int strtool::split(const string &str, vector<string> &ret_, string sep) {
        ret_.clear();
        if (str.empty()) {
            return 0;
        }

        string tmp;
        string::size_type pos_begin = str.find_first_not_of(sep);
        string::size_type comma_pos = 0;

        while (pos_begin != string::npos) {
            comma_pos = str.find(sep, pos_begin);
            if (comma_pos != string::npos) {
                tmp = str.substr(pos_begin, comma_pos - pos_begin);
                pos_begin = comma_pos + sep.length();
            }
            else {
                tmp = str.substr(pos_begin);
                pos_begin = comma_pos;
            }

            if (!tmp.empty()) {
                ret_.push_back(tmp);
                tmp.clear();
            }
        }
        return 0;
    }

    string strtool::replace(const string &str, const string &src, const string &dest) {
        string ret;

        string::size_type pos_begin = 0;
        string::size_type pos = str.find(src);
        while (pos != string::npos) {
            cout << "replacexxx:" << pos_begin << " " << pos << "\n";
            ret.append(str.data() + pos_begin, pos - pos_begin);
            ret += dest;
            pos_begin = pos + 1;
            pos = str.find(src, pos_begin);
        }
        if (pos_begin < str.length()) {
            ret.append(str.begin() + pos_begin, str.end());
        }
        return ret;
    }

    string strtool::To_UTF8(const u32string& from){
        return conv.to_bytes(from);
    }

    string strtool::gen_filename(const string &suffix){
        time_t rawtime;
        time(&rawtime);
        return to_string(long(&rawtime))+suffix;
    }


