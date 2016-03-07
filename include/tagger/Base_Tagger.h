//
// Created by 王鹏飞 on 16/3/7.
//

#ifndef POSTAGGER_BASE_TAGGER_H
#define POSTAGGER_BASE_TAGGER_H

#include <iostream>
#include <vector>
using namespace std;
class Base_Tagger {
public:
    virtual void train(const string &dest_model)=0;
    virtual std::vector<std::u32string> predict(std::u32string const &sentence) const = 0;
    virtual bool save(std::string const &model_path) const = 0;
    virtual ~Base_Tagger() {}
    static Base_Tagger * load(std::string const &model_path, std::string const &seger_name);
};


#endif //POSTAGGER_BASE_TAGGER_H
