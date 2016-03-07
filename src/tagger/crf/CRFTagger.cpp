//
// Created by 王鹏飞 on 16/2/29.
//

#include <tagger/crf/CRFTagger.h>
#include <fstream>


CRFTagger::CRFTagger(const string &model):modelfile(model){

}


void CRFTagger::train(const string &dest_model) {
    string modefied_train=preProcessor.modify_file_for_train(corpus_path);
    preProcessor.train_model(template_path,modefied_train,dest_model);
}

vector<string> CRFTagger::tag(vector<u32string> const &sentence) {

}

bool CRFTagger::save(string const &model_path) {
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


