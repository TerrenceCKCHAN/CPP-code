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
   * @param type
   *          RGB or Grayscale Picture. Noice that in opencv:
   *          enum { CV_8U=0, CV_8S=1, CV_16U=2, CV_16S=3, CV_32S=4, CV_32F=5, CV_64F=6 };
   *          where CV_8U == CV_8UC1 (8-bit unsigned char with one channel intensity image ( 0..255 )) and CV_8UC3 (8-bit unsigned char with three channels (color) image)
   *          Only work in this exercise 8-bit grayscale or color images.
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
   * @param type the image can be RGB format (CV_LOAD_IMAGE_COLOR >0) or intensity value format (CV_LOAD_IMAGE_GRAYSCALE == 0)
   * @return a Picture representing the image at the specified URL, or null if
   *         loading failed for any reason.
   */
  
  Mat loadimage(string path);
  
  /**
   * Displays any image on a GUI window
   */
  
  void displayimage(Mat img);
  
  /*clones the image provided as argument
   */
  
  Mat copyimage(Mat img);
  
  
};

#endif

