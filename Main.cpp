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
            std::cout << "loading..." << argv[i] << std::endl;
//            PicLibrary::loadpicture(/*add path and string name*/);
//            PicLibrary::display(argv[i]);
        }
    }
    bool loop = true;
    while(loop) {
        std::string line;
        std::getline(cin, line);
        std::vector<std::string> tokens = splitLine(line);


        if (tokens[0] == "liststore") {
            vector<string> keys;
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
                picLib->loadpicture("." + file_path, file_name);
            }
        }

        if (tokens[0] == "unload") {
            string file_name = tokens[1];
            map<string, string> aMap = {{"yo", "a"}, {"buddy", "a"}, {"get", "d"}, {"wrecked", "e"}};

            if (aMap.find(file_name) == aMap.end()) {
                cout << "Error" << endl;
            } else {
                cout << "This is okay" << endl;
            }
        }

        if (tokens[0] == "save") {
            string file_name = tokens[1];
            string file_path = tokens[2];
            map<string, string> aMap = {{"yo", "a"}, {"buddy", "a"}, {"get", "d"}, {"wrecked", "e"}};

            if (aMap.find(file_name) == aMap.end()) {
                //Output error message when the filename does not exist in the picture library's internal picture store
                cout << "Error" << endl;
            } else {
                cout << "This is okay" << endl;
            }
        }

        if (tokens[0] == "display") {
            string file_name = tokens[1];
            map<string, string> aMap = {{"yo", "a"}, {"buddy", "a"}, {"get", "d"}, {"wrecked", "e"}};

            if (aMap.find(file_name) == aMap.end()) {
                //Output error message when the filename does not exist in the picture library's internal picture store
                cout << "Error" << endl;
            } else {
                cout << "This is okay" << endl;
            }
        }
        if (tokens[0] == "invert") {
            string file_name = tokens[1];
            map<string, string> aMap = {{"yo", "a"}, {"buddy", "a"}, {"get", "d"}, {"wrecked", "e"}};

            if (aMap.find(file_name) == aMap.end()) {
                //Output error message when the filename does not exist in the picture library's internal picture store
                cout << "Error" << endl;
            } else {
                cout << "This is okay" << endl;
            }
        }
        if (tokens[0] == "grayscale") {
            string file_name = tokens[1];
            map<string, string> aMap = {{"yo", "a"}, {"buddy", "a"}, {"get", "d"}, {"wrecked", "e"}};

            if (aMap.find(file_name) == aMap.end()) {
                //Output error message when the filename does not exist in the picture library's internal picture store
                cout << "Error" << endl;
            } else {
                cout << "This is okay" << endl;
            }
        }
        if (tokens[0] == "rotate") {
            // to add ways to parse tokens[1] to get degrees [90|180|270]
            string file_name = tokens[2];
            map<string, string> aMap = {{"yo", "a"}, {"buddy", "a"}, {"get", "d"}, {"wrecked", "e"}};

            if (aMap.find(file_name) == aMap.end()) {
                //Output error message when the filename does not exist in the picture library's internal picture store
                cout << "Error" << endl;
            } else {
                cout << "This is okay" << endl;
            }
        }
        if (tokens[0] == "flip") {
            // add [H|V] tokens[1]
            string file_name = tokens[2];
            map<string, string> aMap = {{"yo", "a"}, {"buddy", "a"}, {"get", "d"}, {"wrecked", "e"}};

            if (aMap.find(file_name) == aMap.end()) {
                //Output error message when the filename does not exist in the picture library's internal picture store
                cout << "Error" << endl;
            } else {
                cout << "This is okay" << endl;
            }
        }

        if (tokens[0] == "blur") {
            string file_name = tokens[1];
            map<string, string> aMap = {{"yo", "a"}, {"buddy", "a"}, {"get", "d"}, {"wrecked", "e"}};

            if (aMap.find(file_name) == aMap.end()) {
                //Output error message when the filename does not exist in the picture library's internal picture store
                cout << "Error" << endl;
            } else {
                cout << "This is okay" << endl;
            }
        }



        if (line == "exit") {
            loop = false;
            //wait for any outstanding worker threads to complete
            //free all resources used by the program
            //terminate with a successful exit code of 0
        }













//To print sth for testing
//        cout <<  << endl;



//        for (int i = 0; i < tokens.size(); i++) {
//            std::cout << tokens[i] << std::endl;
//        }
//        std::cout << tokens[0] << std::endl;




//        std::string token;
//        std::vector<std::string> tokens;
//        std::stringstream ss(cin);
//        while (std::getline(cin, token, ' ')) {
//            tokens.push_back(token);
//        }
//        std::cout << tokens[0] << std::endl;
//
//        std::cout << tokens << std::endl;






//        cout << "This is the prompt" << endl;
//        cin >> cmd;

//        using namespace std;
//        string sentence = "And I feel fine...";
//        istringstream iss(sentence);
//        copy(istream_iterator<string>(iss),
//             istream_iterator<string>(),
//             ostream_iterator<string>(cout, "\n"));
//
//        cout << cmd << endl;
//        if (cmd == "liststore") {
//            cout << cmd << endl;
//        } else if (cmd == "load") {
//            cout << cmd << endl;
//        } else if (cmd == "liststore") {
//            cout << cmd << endl;
//        } else if (cmd == "liststore") {
//            cout << cmd << endl;
//        } else if (cmd == "liststore") {
//            cout << cmd << endl;
//        } else if (cmd == "liststore") {
//            cout << cmd << endl;
//        } else if (cmd == "liststore") {
//            cout << cmd << endl;
//        }
    }


  cout << "------------------------------------------------------" << endl; 
  cout << "TODO: Implement the C++ Picture Processing Interpreter" << endl;
  cout << "------------------------------------------------------" << endl;

  // write main IO loop that runs the command-line interpreter interactive shell


  return 0;

}


