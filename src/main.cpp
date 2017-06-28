#include <boost/program_options/options_description.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/tokenizer.hpp>
#include <boost/token_functions.hpp>

using namespace boost;
using namespace boost::program_options;

#include <iostream>
#include <sstream>
#include <string>

#include "mediaorganiser.hpp"

bool process_command_line(  int argc, 
                            char *argv[], 
                            std::string &i_folder, 
                            std::string &o_folder,
                            bool &copy){
    
    try{
        // Declare allowed options
        options_description general("General options");
        general.add_options()
            ("help,h", "print help")
            ("input,i", value<std::string>(&i_folder)->required(), "input folder")
            ("output,o", value<std::string>(&o_folder), "output folder")
            ("copy,c", "if specified, files are copied instead of moved")
            ;

        variables_map vm;
        store(parse_command_line(argc, argv, general), vm);

        if(vm.count("help")){
            std::cout << general;
            return false;
        }

        copy = vm.count("copy");

        notify(vm);
    }
    catch(std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return !i_folder.empty();
}


int main(int argc, char *argv[]){

    std::string i_folder;
    std::string o_folder;
    bool copy;

    bool result = process_command_line(argc, argv, i_folder, o_folder, copy);
    if(!result){
        return 1;
    }

    // If output is not given, use input folder
    if(o_folder.empty()){
        o_folder = i_folder;
    }

    std::cout << "input:\t" <<  i_folder << std::endl;
    std::cout << "output:\t" <<  o_folder << std::endl;

    return organise_media(i_folder, o_folder, copy);

}
