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

int main(int argc, char ** argv)
{
    //to store all arguments first
    if (argc != 0) {
        for (int i = 1; i < argc; i++) {
            std::cout << "loading..." << argv[i] << std::endl;
            PicLibrary::loadpicture(/*add path and string name*/);
            PicLibrary::display(argv[i]);
    }
    bool loop = true;
    while(loop) {
        std::string line;
        std::getline(cin, line);
//        std::cout << line << std::endl;
        std::vector<std::string> tokens = splitLine(line);
        std::cout << tokens[0] << std::endl;




//        std::string token;
//        std::vector<std::string> tokens;
//        std::stringstream ss(cin);
//        while (std::getline(cin, token, ' ')) {
//            tokens.push_back(token);
//        }
//        std::cout << tokens[0] << std::endl;
//
//        std::cout << tokens << std::endl;

        if (line == "END") {
            loop = false;
        }




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


