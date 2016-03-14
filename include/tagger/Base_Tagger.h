//
// Created by 王鹏飞 on 16/3/7.
//

#ifndef POSTAGGER_BASE_TAGGER_H
#define POSTAGGER_BASE_TAGGER_H

#include <iostream>
#include <vector>
#include <rapidjson/document.h>
using namespace std;

class Base_Tagger {
public:
    virtual void train(const string &dest_model)=0;
    virtual vector<pair<string,string>> predict(vector<u32string> const &sentence) const = 0;
    virtual bool save(std::string const &model_path) = 0;
    virtual ~Base_Tagger() {}
    static Base_Tagger * load(std::string const &model_path, std::string const &seger_name);
    static Base_Tagger * create_Tagger(rapidjson::Document const &config, std::string const &Tager_name);
};


#endif //POSTAGGER_BASE_TAGGER_H
