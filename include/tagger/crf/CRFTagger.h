//
// Created by 王鹏飞 on 16/2/29.
//

#ifndef POSTAGGER_CRFTAGGER_H
#define POSTAGGER_CRFTAGGER_H

#include <string>
#include <vector>
#include <tagger/preprocessor/PreProcessor.h>
#include <tagger/Base_Tagger.h>
#include <rapidjson/document.h>
#include <tagger/crf/crfpp.h>
#include <utility>

using namespace std;

    class CRFTagger: public Base_Tagger {
    public:
        CRFTagger(const string &model);
        CRFTagger(const rapidjson::Document &config);
        vector< pair<string,string> > predict(vector<u32string> const &sentence) const ;
        void train(const string &dest_model);
        bool save(string const &model_path) ;

    private:
        CRFPP::Tagger *tagger;
        string template_path;
        string corpus_path;
        static PreProcessor preProcessor;

    };

#endif //POSTAGGER_CRFTAGGER_H
