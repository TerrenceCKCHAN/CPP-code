#include "PicLibrary.hpp"
#include "Colour.hpp"
#include "Picture.hpp"


map<string, Picture> internalPicStorage;

void print_picturestore() {

}
void loadpicture(string path, string filename) {
    // To insert into the map -- internalPicStorage<String, Picture>, filename is the key
    Picture pic = Picture(path);
    internalPicStorage[filename] = pic;
}
void unloadpicture(string filename) {

}
void savepicture(string filename, string path) {

}
void display(string filename) {

}

// picture transformation routines
void invert(string filename) {
//    Picture pic = internalPictureStorage.find(filename);
//    for (int x = 0; x < width; x++) {
//        for (int y = 0; y < height; y++) {
//            Colour pixelColour = pic.getPixel(x, y);
//            int newRed   = 255 - pixelColour.getRed();
//            int newGreen = 255 - pixelColour.getGreen();
//            int newBlue  = 255 - pixelColour.getBlue();
//            Color newPixelColour = new Colour(newRed, newGreen, newBlue);
//            pic.setPixel(x, y, newPixelColour);
}

void grayscale(string filename) {
//    Picture pic = internalPictureStorage.find(filename);
//    int width = pic.getWidth();
//    int height = pic.getHeight();
//    for (int x = 0; x < width; x++) {
//        for (int y = 0; y < height; y++) {
//            Colour pixelColour = pic.getPixel(x, y);
//            int avg = (pixelColour.getRed() + pixelColour.getGreen() + pixelColour.getBlue()) / 3;
//            Colour newpixelColour = new Colour(avg, avg, avg);
//            pic.setPixel(x, y, newpixelColor);
//        }
//
//    }
}

void rotate(int angle, string filename) {
//    int width = pic.getWidth();
//    int height = pic.getHeight();
//    switch (angle) {
//        case "90":
//            Picture newPic = Utils.createPicture(height, width);
//            for (int x = 0; x < width; x++) {
//                for (int y = 0; y < height; y++) {
//                    Color pixelcolor = pic.getPixel(x, y);
//                    newPic.setPixel(height - y - 1, x, pixelcolor);
//                }
//            }
//            pic = newPic;
//            break;
//        case "180":
//            Picture newPic1 = Utils.createPicture(width, height);
//            for (int x = 0; x < width; x++) {
//                for (int y = 0; y < height; y++) {
//                    Color pixelcolor = pic.getPixel(x, y);
//                    newPic1.setPixel(width - x - 1, height - y - 1, pixelcolor);
//                }
//            }
//            pic = newPic1;
//            break;
//        case "270":
//            Picture newPic2 = Utils.createPicture(height, width);
//            for (int x = 0; x < width; x++) {
//                for (int y = 0; y < height; y++) {
//                    Color pixelcolor = pic.getPixel(x, y);
//                    newPic2.setPixel(y , width - x - 1, pixelcolor);
//                }
//            }
//            pic = newPic2;
//            break;
//}

}
void flipVH(char plane, string filename) {
//    int width = pic.getWidth();
//    int height = pic.getHeight();
//    Picture newPic = Utils.createPicture(width, height);
//    for (int x = 0; x < width; x++) {
//        for (int y = 0; y < height; y++) {
//            Color pixelcolor = pic.getPixel(x, y);
//            switch (orientation) {
//                case "H":
//                    newPic.setPixel(width - x - 1, y, pixelcolor);
//                    break;
//                case "V":
//                    newPic.setPixel(x, height - y - 1, pixelcolor);
//                    break;
//
//            }
//        }
//    } pic = newPic;
}
void blur(string filename) {
//    int width  = pic.getWidth();
//    int height = pic.getHeight();
//    Picture newPic = Utils.createPicture(width, height);
//
//    for (int x = 0; x < width; x++) {
//        for (int y = 0; y < height; y++) {
//            if (x == 0 || x == width - 1 || y == 0 || y == height - 1) {
//                newPic.setPixel(x, y, pic.getPixel(x, y));
//            } else {
//                int red = 0;
//                int green = 0;
//                int blue = 0;
//                for (int i = x - 1; i < x + 2; i++) {
//                    for (int j = y - 1; j < y + 2; j++) {
//                        Color currentPix = pic.getPixel(i, j);
//                        blue = blue + currentPix.getBlue();
//                        green = green + currentPix.getGreen();
//                        red = red + currentPix.getRed();
//                    }
//                }
//                Color newColor = new Color(red / 9, green / 9, blue / 9);
//                newPic.setPixel(x, y, newColor);
//            }
//        }
//    } pic = newPic;
}
