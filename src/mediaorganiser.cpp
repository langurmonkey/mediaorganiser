#include <iostream>
#include <iomanip>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string/predicate.hpp>

using namespace boost;
using namespace boost::filesystem;

bool check_dir(path &p, std::string str){
    
    if(!exists(p)){
        if(!create_directory(p)){
            std::cout << str << " does not exist" << std::endl;
            return false;
        }
    }

    if(!is_directory(p)){
        std::cout << str << " is not a directory" << std::endl;
        return false;
    }

    return true;
}

int organise_media(std::string &i, std::string &o, bool &cpy){
    path ip(i);
    path op(o);


    /*
     *   First we perform some basic checks - paths exist and are folders
     */
    if(!check_dir(ip, "input path") || !check_dir(op, "output path")){
        return 1;
    }

    std::vector<std::string> prefixes{"VID_", "VID-", "IMG_", "IMG-", "PHOTO_", "PANO_"};
    std::vector<std::string> regexps{"(\d{4})-(\d{2})-(\d{02}).*"};


    directory_iterator end_itr; // default construction yields past-the-end

    // Iterate over files in directory
    for (directory_iterator itr(ip); itr != end_itr; ++itr){
        if(is_regular_file(itr->status())){
            bool found = false;

            std::string filename = itr->path().filename().generic_string();
            std::cout << filename << ":" << std::cout.left << std::setw(40);

            for(std::string prefix : prefixes){
                if(starts_with(filename, prefix)){
                    path yearmonth = filename.substr(prefix.length(), 6);

                    found = true;

                    path datefolder = op;
                    datefolder += yearmonth;

                    if(create_directory(datefolder) || exists(datefolder)){
                        path newfile = datefolder;
                        newfile /= itr->path().filename();

                        if(!exists(newfile)){
                            if(cpy)
                                copy(itr->path(), newfile);
                            else
                                rename(itr->path(), newfile);

                            std::cout << itr->path().generic_string() << (cpy ? " copied to " : " renamed to ") << newfile.generic_string() << std::endl;
                        }else{
                            std::cout << newfile.generic_string() << " already exists" << std::endl;
                        }   
                    }else{
                        std::cout << "Error creating directory " << datefolder << std::endl;
                    }


                    break;
                }
            }

            if(!found){
                std::cout << "Skipping" << std::endl;
            }

        }
        // Not recursive
    }
    return 0;
}
