//
// Created by 王鹏飞 on 16/3/8.
//

#include <tagger/crf/CRFTagger.h>
#include <fstream>
#include <boost/program_options.hpp>
using namespace boost::program_options;
int main(int argc,char *argv[]){

    options_description desc{"Options"};
    desc.add_options()
            ("help,h", "show help message")
            ("config,c", value<string>(), "config file")
            ("output,o",value<string>(),"output model name");
    //program options
    variables_map vm;
    store(parse_command_line(argc, argv, desc), vm);
    notify(vm);

    if (vm.count("help")) {
        cout << desc << endl;
        exit(0);
    }
    if (!vm.count("config")) {
        cerr << "Must specify config file path." << endl;
        cout << desc << endl;
        exit(1);
    }
    if (!vm.count("output")) {
        cerr << "Must specify output model path." << endl;
        cout << desc << endl;
        exit(1);
    }

    string const config_file = vm["config"].as<string>();
    string const model_name = vm["output"].as<string>();

    ifstream in(config_file,ios::in);
    istreambuf_iterator<char> beg(in), end;
    string jsondata(beg, end);
    rapidjson::Document document;
    document.Parse(jsondata.c_str());
    Base_Tagger *p=Base_Tagger::create_Tagger(document,"CRF");
    p->train(model_name);
    return 0;
}