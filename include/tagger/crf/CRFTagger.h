//
// Created by 王鹏飞 on 16/2/29.
//

#ifndef POSTAGGER_CRFTAGGER_H
#define POSTAGGER_CRFTAGGER_H

#include <string>
#include <vector>
#include <tagger/preprocessor/PreProcessor.h>
#include <tagger/Base_Tagger.h>

using namespace std;
    class CRFTagger: public Base_Tagger {
    public:
        CRFTagger(const string &model);
        virtual ~CRFTagger();
        vector<string> tag(vector<string> const &sentence);
        void train(const string &dest_model);
        bool save(string const &model_path);

    private:
        string modelfile;
        string template_path;
        string corpus_path;
        static PreProcessor preProcessor;
    };

#endif //POSTAGGER_CRFTAGGER_H