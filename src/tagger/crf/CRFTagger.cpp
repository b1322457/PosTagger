//
// Created by 王鹏飞 on 16/2/29.
//

#include <tagger/crf/CRFTagger.h>
#include <fstream>
#include <tagger/preprocessor/strtool.h>



PreProcessor CRFTagger::preProcessor{};

CRFTagger::CRFTagger(const string &model):modelfile(model){

}
CRFTagger::CRFTagger(const rapidjson::Document &config){
    template_path=config["template_path"].GetString();
    corpus_path = config["corpus_path"].GetString();
}


void CRFTagger::train(const string &dest_model) {
    string modefied_train=preProcessor.modify_file_for_train(corpus_path);
    preProcessor.train_model(template_path,modefied_train,dest_model);
    remove(modefied_train);
}

vector< pair<string,string> > CRFTagger::predict(vector<u32string> const &sentence)const {

    string sentence_file=strtool::gen_filename("sen_file");
    ofstream out(sentence_file);

    for(auto pos=sentence.begin();pos!=sentence.end();pos++){
        string u8_word=strtool::To_UTF8(*pos);
        out<<u8_word<<endl;
    }
    out.close();
    string ret_file=strtool::gen_filename("ret_file");
    preProcessor.test_model(this->modelfile,sentence_file,ret_file);
    vector<pair<string,string>>res = preProcessor.model_file_for_tag_ret(ret_file);
    remove(sentence_file);
    remove(ret_file);
    return res;
}

bool CRFTagger::save(string const &model_path){
    ifstream in(model_path,ios::in);
    if(!in){
        string msg="model"+model_path+"doesn't exist!!";
        throw msg;
    } else{
        this->modelfile=model_path;
        in.close();
        return true;
    }

}


