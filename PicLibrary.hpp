#ifndef PICLIB_H
#define PICLIB_H

#include "Picture.hpp"
#include "Utils.hpp"

class PicLibrary {

  private:
  // TODO: define internal picture storage 

  public:
  // default class constructor/deconstructor
  PicLibrary(){};
  ~PicLibrary();

  // command-line interpreter routines
  void print_picturestore();
  void loadpicture(string path, string filename);
  void unloadpicture(string filename);
  void savepicture(string filename, string path);
  void exit();
  void display(string filename);
  
  // picture transformation routines
  void invert(string key);
  void grayscale(string key);
  void rotate(int angle, string key);
  void flipVH(char plane, string key);
  void blur(string key);
};

#endif

