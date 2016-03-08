//
// Created by 王鹏飞 on 16/3/8.
//

#include <tagger/crf/CRFTagger.h>
#include <tagger/Base_Tagger.h>
int main(int argc,char *argv[]){
    const char* config_file=argv[1];
    Base_Tagger *p=Base_Tagger::create_Tagger();
}