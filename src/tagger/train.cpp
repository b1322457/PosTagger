//
// Created by 王鹏飞 on 16/3/8.
//

#include <tagger/crf/CRFTagger.h>
#include <tagger/Base_Tagger.h>
#include <fstream>
int main(int argc,char *argv[]){
    const char* config_file=argv[1];
    ifstream in(config_file,ios::in);
    istreambuf_iterator<char> beg(in), end;
    string jsondata(beg, end);
    rapidjson::Document document;
    document.Parse(jsondata);
    Base_Tagger *p=Base_Tagger::create_Tagger(document,"CRF");
    p->train("model1");
    return 0;
}