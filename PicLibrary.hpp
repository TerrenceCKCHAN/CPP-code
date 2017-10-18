#ifndef PICLIB_H
#define PICLIB_H

#include "Picture.hpp"
#include "Utils.hpp"
#include <map>

class PicLibrary {

  private:
  // TODO: define internal picture storage
  map<string, Picture> internalPicStorage;

  public:
  // default class constructor/deconstructor
  PicLibrary(){};
  ~PicLibrary();


  //getter
  map<string, Picture> getInternalPicStorage();

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

