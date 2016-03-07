//
// Created by 王鹏飞 on 16/3/1.
//

#ifndef POSTAGGER_PREPROCESSOR_H
#define POSTAGGER_PREPROCESSOR_H

#include <string>
using namespace std;
class PreProcessor {
public:
    string modify_file_for_train(const string& rawfile);//return modefied file for crf train;
    void train_model(const string &_template, const string &stand_file, const string &modelname);


#endif //POSTAGGER_PREPROCESSOR_H
