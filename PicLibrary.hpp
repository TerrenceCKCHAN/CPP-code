#ifndef PICLIB_H
#define PICLIB_H

#include "Picture.hpp"
#include "Utils.hpp"
#include <map>
#include <mutex>

using namespace std;

class PicLibrary {


private:
    map <string, Picture> internalPicStorage;
    std::mutex mtx;

public:
    // default class constructor/deconstructor
    PicLibrary() {};

    ~PicLibrary();


    //getter
    map <string, Picture> getInternalPicStorage();

    // mutex lock and unlock
    void lockMutex();

    void unlockMutex();

    // command-line interpreter routines
    void print_picturestore();

    void loadpicture(string path, string filename);

    void unloadpicture(string filename);

    void savepicture(string filename, string path);

    void display(string filename);

    // picture transformation routines
    void invert(string filename);

    void grayscale(string filename);

    void rotate(string angle, string filename);

    void flipVH(string plane, string filename);

    void blur(string filename);
};

#endif

