//
// Created by 王鹏飞 on 16/3/1.
//

#include <tagger/preprocessor/PreProcessor.h>
#include <time.h>
#include <fstream>
#include <tagger/preprocessor/strtool.h>
#include <tagger/crf/crfpp.h>
#include <sstream>

string PreProcessor::modify_file_for_train(const string &rawfile) {
    ifstream in(rawfile,ios::in);
    time_t rawtime;
    time(&rawtime);
    string modefied_train=to_string(long(&rawtime))+"_train";
    ofstream out(modefied_train);
    if(in.is_open()){
        while(!in.eof()){
            string line;
            getline(in,line);
            line=strtool::trim(line);
            vector<string>ret_;
            strtool::split(line,ret_," ");
            vector<string>w_h;
            for(string &word:ret_){
                strtool::split(word,w_h,"_");
                out<<w_h[0]<<"\t";
                out<<w_h[1]<<"\n";
            }
            out<<"\n";

        }
        in.close();
        out.close();
        return modefied_train;
    } else{
        exit(1);
    }
}

int PreProcessor::train_model(const string &_template, const string &stand_file, const string &modelname) {
    vector<string>args;
    args.push_back("crf_learn");
    args.push_back("-f");
    args.push_back("3");
    args.push_back("-c");
    args.push_back("4.0");
    args.push_back(_template);
    args.push_back(stand_file);
    args.push_back(modelname);
    char *argv[8];
    for(int i=0;i<args.size();i++)
    {
        argv[i]=const_cast<char*>(args[i].c_str());
    }
    return crfpp_learn(args.size(),argv);
}

int PreProcessor::test_model(const string &model, const string &stand_file, const string &dest_file){
    vector<string>args;
    args.push_back("crf_test");
    args.push_back("-m");
    args.push_back(model);
    args.push_back(stand_file);
    args.push_back("-o");
    args.push_back(dest_file);
    char *argv[8];
    for(int i=0;i<args.size();i++){
        argv[i]= const_cast<char*>(args[i].c_str());
    }
    return crfpp_test(args.size(),argv);
}

vector<string>PreProcessor::model_file_for_tag_ret(const string &tmp){
    ifstream in(tmp,ios::in);
    vector<string>svec;
    ostringstream ss;
    if(in.is_open()){
        while(!in.eof()){
            string line;
            getline(in,line);
            if(line.empty()){
                svec.push_back("\n");
            }
            else{
                vector<string>w_h;
                strtool::split(line,w_h,"\t");
                ss<<w_h[0]<<"_"<<w_h[1];
                svec.push_back(ss.str());
            }
        }
        in.close();
    } else{
        exit(1);
    }
}

