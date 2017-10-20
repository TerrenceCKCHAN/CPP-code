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
#include <thread>
#include <queue>

using namespace std;

std::vector<std::string> splitLine(std::string line) {
    std::vector <std::string> tokens;
    std::stringstream ss(line);
    std::string token;
    while (std::getline(ss, token, ' ')) {
        tokens.push_back(token);
    }
    return tokens;
}
string getFileExt(const string &s) {

    size_t i = s.rfind('.', s.length());
    if (i != string::npos) {
        return (s.substr(i + 1, s.length() - i));
    }

    return ("");
}

//A new worker created when there is a new picture loaded.
//It is then killed when the picture unloads.
void worker(queue<vector<string>>* tasks, PicLibrary *picLib) {
    while (true) {
        if (tasks->size() > 0) {
            vector <string> tokens = tasks->front();
            if (tokens[0] == "save") {
                string file_name = tokens[1];
                string file_path = tokens[2];
                picLib->savepicture(file_name, file_path);
            }
            if (tokens[0] == "display") {
                string file_name = tokens[1];
                picLib->display(file_name);
            }
            if (tokens[0] == "invert") {
                string file_name = tokens[1];
                picLib->invert(file_name);
            }
            if (tokens[0] == "grayscale") {
                string file_name = tokens[1];
                picLib->grayscale(file_name);
            }
            if (tokens[0] == "rotate") {
                string angle = tokens[1];
                string file_name = tokens[2];
                picLib->rotate(angle, file_name);
            }
            if (tokens[0] == "flip") {
                string plane = tokens[1];
                string file_name = tokens[2];
                picLib->flipVH(plane, file_name);
            }
            if (tokens[0] == "blur") {
                string file_name = tokens[1];
                picLib->blur(file_name);
            }
            tasks->pop();
        }
    }
}

//thread safe implementation code
int main(int argc, char **argv) {
    PicLibrary *picLib = new PicLibrary();
    //create a threadManager that manages all worker threads for each picture loaded
    //create a queueManager for all the tasks to be done by the worker thread for that particular picture
    map<string, thread> threadManager;
    map<string, queue<vector<string>>*> queueManager;
    //load all pictures in the arguments with the file_name being the string after the last "/"
    //e.g. typing the command "./picture_lib images/ducks1.jpg"
    //would load the picture with path images/ducks1.jpg with name ducks1.jpg
    if (argc != 0) {
        for (int i = 1; i < argc; i++) {
            string token = argv[i];
            int position = token.find_last_of("/");
            string file_name = token.substr(position + 1);
            picLib->loadpicture(token, file_name);
            queue<vector<string>>* myQueue = new std::queue<std::vector<std::string>>();
            queueManager[file_name] = myQueue;
            threadManager[file_name] = std::thread(worker, myQueue, picLib);
        }
    }
    //Starts processing commands
    std::string line;
    while (std::getline(cin, line)) {
        if (line == "") {
            continue;
        }
        std::vector <std::string> tokens = splitLine(line);
        if (tokens[0] == "liststore") {
            picLib->lockMutex();
            vector <string> keys;
            for (auto elem : picLib->getInternalPicStorage()) {
                std::cout << elem.first << std::endl;
            }
            picLib->unlockMutex();
        }
        if (tokens[0] == "load") {
            string file_path = tokens[1];
            string file_name = tokens[2];

            if ((getFileExt(file_path) != "jpg") || picLib->getInternalPicStorage().count(file_name)) {
                cout << "Cannot load argument" << endl;
            } else {
                picLib->loadpicture(file_path, file_name);
                queue<vector<string>>* myQueue = new std::queue<std::vector<std::string>>();
                queueManager[file_name] = myQueue;
                threadManager[file_name] = std::thread(worker, myQueue, picLib);
            }
        }
        if (tokens[0] == "unload") {
            string file_name = tokens[1];
            if (!picLib->getInternalPicStorage().count(file_name)) {
                //Output error message when the filename does not exist in the picture library's internal picture store
                cout << "Filename does not exist" << endl;
            } else {
                while (queueManager[file_name]->size() > 0) {};
                queueManager.erase(file_name);
                threadManager.erase(file_name);
                picLib->unloadpicture(file_name);
            }
        }
        if (tokens[0] == "save") {
            string file_name = tokens[1];
            string file_path = tokens[2];

            if (!picLib->getInternalPicStorage().count(file_name)) {
                cout << "Filename does not exist" << endl;
            } else {
                queueManager[file_name]->push(tokens);
            }
        }
        if (tokens[0] == "display") {
            string file_name = tokens[1];
            if (!picLib->getInternalPicStorage().count(file_name)) {
                cout << "Filename does not exist" << endl;
            } else {
                queueManager[file_name]->push(tokens);
            }

        }
        if (tokens[0] == "invert") {
            string file_name = tokens[1];

            if (!picLib->getInternalPicStorage().count(file_name)) {
                cout << "Filename does not exist" << endl;
            } else {
                queueManager[file_name]->push(tokens);
            }
        }
        if (tokens[0] == "grayscale") {
            string file_name = tokens[1];
            if (!picLib->getInternalPicStorage().count(file_name)) {
                cout << "Filename does not exist" << endl;
            } else {
                queueManager[file_name]->push(tokens);
            }
        }
        if (tokens[0] == "rotate") {
            string angle = tokens[1];
            string file_name = tokens[2];
            if (!picLib->getInternalPicStorage().count(file_name)) {
                cout << "Filename does not exist" << endl;
            } else {
                queueManager[file_name]->push(tokens);
            }
        }
        if (tokens[0] == "flip") {
            string plane = tokens[1];
            string file_name = tokens[2];
            if (!picLib->getInternalPicStorage().count(file_name)) {
                cout << "Filename does not exist" << endl;
            } else {
                queueManager[file_name]->push(tokens);
            }
        }
        if (tokens[0] == "blur") {
            string file_name = tokens[1];
            if (!picLib->getInternalPicStorage().count(file_name)) {
                cout << "Filename does not exist" << endl;
            } else {
                queueManager[file_name]->push(tokens);
            }
        }
        if (line == "exit") {
            break;
            //wait for any outstanding worker threads to complete
            //free all resources used by the program
            //terminate with a successful exit code of 0
        }
    }
    for (auto &item : threadManager) {
        while (queueManager[item.first]->size() > 0) {};
        item.second.detach();
    }
    return 0;
}



////sequential code
//int main(int argc, char **argv) {
//    PicLibrary *picLib = new PicLibrary();
//    //load all pictures in the arguments with the file_name being the string after the last "/"
//    //e.g. typing the command "./picture_lib images/ducks1.jpg"
//    //would load the picture with path images/ducks1.jpg with name ducks1.jpg
//    if (argc != 0) {
//        for (int i = 1; i < argc; i++) {
//            string token = argv[i];
//            int position = token.find_last_of("/");
//            string file_name = token.substr(position + 1);
//            picLib->loadpicture(token, file_name);
//        }
//        std::string line;
//        while (std::getline(cin, line)) {
//            if (line == "") {
//                continue;
//            }
//            std::vector <std::string> tokens = splitLine(line);
//            if (tokens[0] == "liststore") {
//                vector <string> keys;
//                for (auto elem : picLib->getInternalPicStorage()) {
//                    std::cout << elem.first << std::endl;
//                }
//            }
//            if (tokens[0] == "load") {
//                string file_path = tokens[1];
//                string file_name = tokens[2];
//                if ((getFileExt(file_path) != "jpg") || picLib->getInternalPicStorage().count(file_name)) {
//                    cout << "Cannot load arguments" << endl;
//                } else {
//                    picLib->loadpicture(file_path, file_name);
//                }
//            }
//            if (tokens[0] == "unload") {
//                string file_name = tokens[1];
//
//                if (!picLib->getInternalPicStorage().count(file_name)) {
//                    //Output error message when the filename does not exist in the picture library's internal picture storage
//                    cout << "Filename does not exist" << endl;
//                } else {
//                    picLib->unloadpicture(file_name);
//                }
//            }
//            if (tokens[0] == "save") {
//                string file_name = tokens[1];
//                string file_path = tokens[2];
//
//                if (!picLib->getInternalPicStorage().count(file_name)) {
//
//                    cout << "Filename does not exist" << endl;
//                } else {
//                    picLib->savepicture(file_name, file_path);
//                }
//            }
//            if (tokens[0] == "display") {
//                string file_name = tokens[1];
//                if (!picLib->getInternalPicStorage().count(file_name)) {
//                    cout << "Filename does not exist" << endl;
//                }
//                picLib->display(file_name);
//
//            }
//            if (tokens[0] == "invert") {
//                string file_name = tokens[1];
//
//                if (!picLib->getInternalPicStorage().count(file_name)) {
//                    cout << "Filename does not exist" << endl;
//                } else {
//                    picLib->invert(file_name);
//                }
//            }
//            if (tokens[0] == "grayscale") {
//                string file_name = tokens[1];
//                if (!picLib->getInternalPicStorage().count(file_name)) {
//                    cout << "Filename does not exist" << endl;
//                } else {
//                    picLib->grayscale(file_name);
//                }
//            }
//            if (tokens[0] == "rotate") {
//                string angle = tokens[1];
//                string file_name = tokens[2];
//
//                if (!picLib->getInternalPicStorage().count(file_name)) {
//                    cout << "Filename does not exist" << endl;
//                } else {
//                    picLib->rotate(angle, file_name);
//                }
//            }
//            if (tokens[0] == "flip") {
//                string plane = tokens[1];
//                string file_name = tokens[2];
//
//                if (!picLib->getInternalPicStorage().count(file_name)) {
//                    cout << "Filename does not exist" << endl;
//                } else {
//                    picLib->flipVH(plane, file_name);
//                }
//            }
//            if (tokens[0] == "blur") {
//                string file_name = tokens[1];
//
//                if (!picLib->getInternalPicStorage().count(file_name)) {
//                    cout << "Filename does not exist" << endl;
//                } else {
//                    picLib->blur(file_name);
//                }
//            }
//            if (line == "exit") {
//                break;
//            }
//        }
//        return 0;
//    }
//}








