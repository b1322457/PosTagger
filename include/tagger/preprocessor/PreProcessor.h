//
// Created by 王鹏飞 on 16/3/1.
//

#ifndef POSTAGGER_PREPROCESSOR_H
#define POSTAGGER_PREPROCESSOR_H

#include <string>
#include <vector>


using namespace std;
class PreProcessor {
public:
    string modify_file_for_train(const string &rawfile);

    //return modefied file for crf train;
    int train_model(const string &_template, const string &stand_file, const string &modelname);

    int test_model(const string &model, const string &stand_file, const string &dest_file);

    vector<pair<string,string>> model_file_for_tag_ret(const string &tmp);
};

#endif //POSTAGGER_PREPROCESSOR_H
