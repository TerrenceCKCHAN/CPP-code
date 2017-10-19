#include <iostream>

#include "Colour.hpp"
#include "Utils.hpp"
#include "Picture.hpp"
#include "PicLibrary.hpp"

#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

// TODO: Implement the picture library command-line interpreter

std::vector<std::string> splitLine(std::string line) {
    std::vector<std::string> tokens;
    std::stringstream ss(line);
    std::string token;
    while (std::getline(ss, token, ' ')) {
        tokens.push_back(token);
    }
    return tokens;
}
//To be transferred to piclib class
string getFileExt(const string& s) {

    size_t i = s.rfind('.', s.length());
    if (i != string::npos) {
        return(s.substr(i+1, s.length() - i));
    }

    return("");
}



int main(int argc, char ** argv)
{
    PicLibrary* picLib = new PicLibrary();


    //to store all arguments first
    if (argc != 0) {
        for (int i = 1; i < argc; i++) {
            string token = argv[i];
            int position = token.find_last_of("/");

            string file_name = token.substr(position + 1);
            picLib->loadpicture(token, file_name);

//            int found = "images/imgage.jpg".find_last_of("/");
//            std::string = "asdfjlk".substr(found + 1);
//            PicLibrary::loadpicture(/*add path and string name*/);
//            PicLibrary::display(argv[i]);
        }
    }
    bool loop = true;
    while(loop) {
        std::string line;
        std::getline(cin, line);
        std::vector <std::string> tokens = splitLine(line);


        if (tokens[0] == "liststore") {
            vector <string> keys;
            for (auto elem : picLib->getInternalPicStorage()) {
                std::cout << elem.first << std::endl;
            }
        }

        if (tokens[0] == "load") {
            string file_path = tokens[1];
            string file_name = tokens[2];

            if ((getFileExt(file_path) != "jpg") || picLib->getInternalPicStorage().count(file_name)) {
                cout << "Error" << endl;
            } else {
                picLib->loadpicture(file_path, file_name);
            }
        }

        if (tokens[0] == "unload") {
            string file_name = tokens[1];

            if (!picLib->getInternalPicStorage().count(file_name)) {
                cout << "Error" << endl;
            } else {
                cout << "This is okay" << endl;
                picLib->unloadpicture(file_name);
            }
        }

        if (tokens[0] == "save") {
            string file_name = tokens[1];
            string file_path = tokens[2];

            if (!picLib->getInternalPicStorage().count(file_name)) {
                //Output error message when the filename does not exist in the picture library's internal picture store
                cout << "Error" << endl;
            } else {
                picLib->savepicture(file_name, file_path);
            }
        }

        if (tokens[0] == "display") {
            string file_name = tokens[1];
            if (!picLib->getInternalPicStorage().count(file_name)) {
                //Output error message when the filename does not exist in the picture library's internal picture store
                cout << "Error" << endl;
            } else {
                picLib->display(file_name);
//                if (GetKeyState('A') & 0x8000) {
//                    return EXIT_SUCCESS;
//                }
            }
        }

        if (tokens[0] == "invert") {
            string file_name = tokens[1];

            if (!picLib->getInternalPicStorage().count(file_name)) {
                //Output error message when the filename does not exist in the picture library's internal picture store
                cout << "Error" << endl;
            } else {
                picLib->invert(file_name);
            }
        }
        if (tokens[0] == "grayscale") {
            string file_name = tokens[1];


            if (!picLib->getInternalPicStorage().count(file_name)) {
                //Output error message when the filename does not exist in the picture library's internal picture store
                cout << "Error" << endl;
            } else {
                picLib->grayscale(file_name);
            }
        }
        if (tokens[0] == "rotate") {
            string angle = tokens[1];
            string file_name = tokens[2];

            if (!picLib->getInternalPicStorage().count(file_name)) {
                //Output error message when the filename does not exist in the picture library's internal picture store
                cout << "Error" << endl;
            } else {
                picLib->rotate(angle, file_name);
            }
        }
        if (tokens[0] == "flip") {
            string plane = tokens[1];
            string file_name = tokens[2];

            if (!picLib->getInternalPicStorage().count(file_name)) {
                //Output error message when the filename does not exist in the picture library's internal picture store
                cout << "Error" << endl;
            } else {
                picLib->flipVH(plane, file_name);
            }
        }

        if (tokens[0] == "blur") {
            string file_name = tokens[1];

            if (!picLib->getInternalPicStorage().count(file_name)) {
                //Output error message when the filename does not exist in the picture library's internal picture store
                cout << "Error" << endl;
            } else {
                picLib->blur(file_name);
            }
        }


        if (line == "exit") {
            loop = false;
            //wait for any outstanding worker threads to complete
            //free all resources used by the program
            //terminate with a successful exit code of 0
        }
    }


  cout << "------------------------------------------------------" << endl; 
  cout << "TODO: Implement the C++ Picture Processing Interpreter" << endl;
  cout << "------------------------------------------------------" << endl;

  // write main IO loop that runs the command-line interpreter interactive shell


  return 0;

}


