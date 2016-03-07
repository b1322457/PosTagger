//
// Created by 王鹏飞 on 16/3/7.
//

#include <tagger/Base_Tagger.h>
#include <tagger/crf/CRFTagger.h>

Base_Tagger *Base_Tagger::load(std::string const &model_path, std::string const &tagger_name) {
    Base_Tagger *Tagger;
    if (tagger_name == "CRF") {
        Tagger =  new CRFTagger(model_path);
    }
    else {
        std::string msg{"unknown tagger name: "};
        msg += tagger_name;
        throw msg;
    }
    return Tagger;
}
