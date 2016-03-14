//
// Created by 王鹏飞 on 16/3/14.
//
#include <tagger/crf/CRFTagger.h>
int main(){
    Base_Tagger *tagger = Base_Tagger::load("model1","CRF");
    vector<u32string>sentence{U"扬帆",U"远东",U"做",U"与",U"中国",U"合作",U"的",U"先行"};
    auto res=tagger->predict(sentence);

    for(auto i:res){
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<sentence.size()<<endl;
}
