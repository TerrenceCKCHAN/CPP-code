#ifndef UTILS_H
#define UTILS_H

#include <opencv2/opencv.hpp>
#include <string>
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
using namespace cv;

class Utils{
    
 public:
   Utils();
  
  /**
   * Create a new instance of a Picture object of the specified width and
   * height, using the RGB colour model.
   * 
   * @param width
   *          width of new Picture
   * @param height
   *          height of new Picture
   * 
   * @return a new instance of a Picture object of the specified size.
   */
  Mat createimage(int width, int height);
  
  /**
   * Saves the given image format (jpg) in the given destination.
   * 
   * @param picture
   *          the picture to save to disk
   * @param destination
   *          where to save the Picture
   * @return true if the file was saved successfully
   */
  int saveimage(Mat img, string filename);
  /**
   * Create a Picture object from the the image at the specified location (or local file).
   * 
   * @param location
   *          a String representing the location of the image to be loaded. This
   *          can either be a URL, or a filesystem location.
   * @return a Picture representing the image at the specified URL, or null if
   *         loading failed for any reason.
   */
  
  Mat loadimage(string path);
  
  /**
   * Displays the image provided as argument on a GUI window
   */
  
  void displayimage(Mat img);
  
  /*clones the image provided as argument
   */
  
  Mat copyimage(Mat img);
  
  
};

#endif

