#include "PicLibrary.hpp"
#include "Colour.hpp"
#include "Picture.hpp"
#include <thread>








map<string, Picture> PicLibrary::getInternalPicStorage() {
    return this->internalPicStorage;
};

void print_picturestore() {

}
void PicLibrary::loadpicture(string path, string filename) {

    // To insert into the map -- internalPicStorage<String, Picture>, filename is the key
    Picture pic = Picture(path);
    this->internalPicStorage[filename] = pic;
}
void PicLibrary::unloadpicture(string filename) {
    this->internalPicStorage.erase(filename);
}
void PicLibrary::savepicture(string filename, string path) {
    Picture pic = this->internalPicStorage[filename];
    Utils utils = Utils();
    utils.saveimage(pic.getimage(), path);


}
void PicLibrary::display(string filename) {
    Picture pic = this->internalPicStorage[filename];
    Utils utils = Utils();
    utils.displayimage(pic.getimage());
}

// picture transformation routines
void PicLibrary::invert(string filename) {
    Picture pic = this->internalPicStorage[filename];
    for (int x = 0; x < pic.getwidth(); x++) {
        for (int y = 0; y < pic.getheight(); y++) {
            Colour pixelColour = pic.getpixel(x, y);
            int newRed = 255 - pixelColour.getred();
            int newGreen = 255 - pixelColour.getgreen();
            int newBlue = 255 - pixelColour.getblue();
            Colour newPixelColour = Colour(newRed, newGreen, newBlue);
            pic.setpixel(x, y, newPixelColour);
        }
    }
}

void PicLibrary::grayscale(string filename) {
    Picture pic = this->internalPicStorage[filename];
    int width = pic.getwidth();
    int height = pic.getheight();
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            Colour pixelColour = pic.getpixel(x, y);
            int avg = (pixelColour.getred() + pixelColour.getgreen() + pixelColour.getblue()) / 3;
            Colour newpixelColour = Colour(avg, avg, avg);
            pic.setpixel(x, y, newpixelColour);
        }

    }
}

void PicLibrary::rotate(string angle, string filename) {
    Picture pic = this->internalPicStorage[filename];
    int width = pic.getwidth();
    int height = pic.getheight();
    if (angle == "90") {
        Picture newPic = Picture(height, width);
        for (int x = 0; x < width; x++) {
            for (int y = 0; y < height; y++) {
                Colour pixelcolour = pic.getpixel(x, y);
                newPic.setpixel(height - y - 1, x, pixelcolour);
            }
        }
        this->internalPicStorage[filename] = newPic;
    } else if (angle == "180") {
        Picture newPic = Picture(width, height);
        for (int x = 0; x < width; x++) {
            for (int y = 0; y < height; y++) {
                Colour pixelcolour = pic.getpixel(x, y);
                newPic.setpixel(width - x - 1, height - y - 1, pixelcolour);
            }
        }
        this->internalPicStorage[filename] = newPic;
    } else if (angle == "270") {
        Picture newPic = Picture(height, width);
        for (int x = 0; x < width; x++) {
            for (int y = 0; y < height; y++) {
                Colour pixelcolour = pic.getpixel(x, y);
                newPic.setpixel(y, width - x - 1, pixelcolour);
            }
        }
        this->internalPicStorage[filename] = newPic;
    }
}


void PicLibrary::flipVH(string plane, string filename) {
    Picture pic = this->internalPicStorage[filename];
    int width = pic.getwidth();
    int height = pic.getheight();
    Picture newPic = Picture(width, height);
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            Colour pixelcolour = pic.getpixel(x, y);
            if (plane == "H") {
                newPic.setpixel(width - x - 1, y, pixelcolour);
            } else if (plane == "V") {
                newPic.setpixel(x, height - y - 1, pixelcolour);
            }
        }
    }
    this->internalPicStorage[filename] = newPic;
}

void rowThread(Picture pic, Picture* newPic, int width, int height, int y) {
    for (int x = 0; x < width; ++x) {
        if (x == 0 || x == width - 1 || y == 0 || y == height - 1) {
            newPic->setpixel(x, y, pic.getpixel(x, y));
        } else {
            int red = 0;
            int green = 0;
            int blue = 0;
            for (int i = x - 1; i < x + 2; i++) {
                for (int j = y - 1; j < y + 2; j++) {
                    Colour currentPix = pic.getpixel(i, j);
                    blue = blue + currentPix.getblue();
                    green = green + currentPix.getgreen();
                    red = red + currentPix.getred();
                }
            }
            Colour newColour = Colour(red / 9, green / 9, blue / 9);
            newPic->setpixel(x, y, newColour);
        }
    }
}

void colThread(Picture pic, Picture* newPic, int width, int height, int x) {
    for (int y = 0; y < height; ++y) {
        if (x == 0 || x == width - 1 || y == 0 || y == height - 1) {
            newPic->setpixel(x, y, pic.getpixel(x, y));
        } else {
            int red = 0;
            int green = 0;
            int blue = 0;
            for (int i = x - 1; i < x + 2; i++) {
                for (int j = y - 1; j < y + 2; j++) {
                    Colour currentPix = pic.getpixel(i, j);
                    blue = blue + currentPix.getblue();
                    green = green + currentPix.getgreen();
                    red = red + currentPix.getred();
                }
            }
            Colour newColour = Colour(red / 9, green / 9, blue / 9);
            newPic->setpixel(x, y, newColour);
        }
    }
}

void fourSectorsThread(Picture pic, Picture* newPic, int width, int height, int x, int y) {
    for (int y = 0; y < height / 2; ++y) {
        if (x == 0 || x == width - 1 || y == 0 || y == height - 1) {
            newPic->setpixel(x, y, pic.getpixel(x, y));
        } else {
            int red = 0;
            int green = 0;
            int blue = 0;
            for (int i = x - 1; i < x + 2; i++) {
                for (int j = y - 1; j < y + 2; j++) {
                    Colour currentPix = pic.getpixel(i, j);
                    blue = blue + currentPix.getblue();
                    green = green + currentPix.getgreen();
                    red = red + currentPix.getred();
                }
            }
            Colour newColour = Colour(red / 9, green / 9, blue / 9);
            newPic->setpixel(x, y, newColour);
        }
    }
}



Picture rowBlur(Picture originalPic, Picture newPic, int width, int height) {
    std::thread workers[height];
    for (int y = 0; y < height; ++y) {
        workers[y] = std::thread(rowThread, originalPic, &newPic, width, height, y);
    }
    for (int y = 0; y < height; ++y) {
        workers[y].join();
    }
    return newPic;
}

Picture colBlur(Picture originalPic, Picture newPic, int width, int height) {
    std::thread workers[width];
    for (int x = 0; x < width; ++x) {
        workers[x] = std::thread(colThread, originalPic, &newPic, width, height, x);
    }
    for (int x = 0; x < width; ++x) {
        workers[x].join();
    }
    return newPic;
}

void sectorThread(Picture pic, Picture* newPic, int width, int height, int a, int b, int sector) {
    for (int x = a; x < a + width/sector; ++x) {
        for (int y = b; y < b + height/sector; ++y) {
            if (x == 0 || x == width - 1 || y == 0 || y == height - 1) {
                newPic->setpixel(x, y, pic.getpixel(x, y));
            } else {
                int red = 0;
                int green = 0;
                int blue = 0;
                for (int i = x - 1; i < x + 2; i++) {
                    for (int j = y - 1; j < y + 2; j++) {
                        Colour currentPix = pic.getpixel(i, j);
                        blue = blue + currentPix.getblue();
                        green = green + currentPix.getgreen();
                        red = red + currentPix.getred();
                    }
                }
                Colour newColour = Colour(red / 9, green / 9, blue / 9);
                newPic->setpixel(x, y, newColour);
            }
        }
    }
}

Picture sectorsBlur(Picture originalPic, Picture newPic, int width, int height, int sector) {
/*    for (int x = 0; x < 4; ++x) {
        workers[x] = std::thread(fourSectorsThread, originalPic, &newPic, width, height, x);
    }
    for (int x = 0; x < 4; ++x) {
        workers[x].join();
    }*/
    std::thread workers[sector*sector];
    int counter = 0;
    for (int x = 0; x < width; x += width/sector) {
        for (int y = 0; y < height; y += height/sector) {
            workers[counter] = std::thread(sectorThread, originalPic, &newPic, width, height, x, y, sector);
            counter++;
        }

    }
    for (int i = 0; i < counter; ++i) {
        workers[i].join();
    }
    return newPic;
}




void pixelThread(Picture pic, Picture* newPic, int width, int height, int x, int y) {
    if (x == 0 || x == width - 1 || y == 0 || y == height - 1) {
        newPic->setpixel(x, y, pic.getpixel(x, y));
    } else {
        int red = 0;
        int green = 0;
        int blue = 0;
        for (int i = x - 1; i < x + 2; i++) {
            for (int j = y - 1; j < y + 2; j++) {
                Colour currentPix = pic.getpixel(i, j);
                blue = blue + currentPix.getblue();
                green = green + currentPix.getgreen();
                red = red + currentPix.getred();
            }
        }
        Colour newColour = Colour(red / 9, green / 9, blue / 9);
        newPic->setpixel(x, y, newColour);
    }
}


Picture pixelBlur(Picture pic, Picture newPic, int width, int height) {
    std::thread workers[1000];
    int threadCounter = 0;
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            workers[threadCounter] = std::thread(pixelThread, pic, &newPic, width, height, x, y);
            threadCounter++;
            if (threadCounter == 1000) {
                for (int i = 0; i < 1000; ++i) {
                    workers[i].join();
                }
                threadCounter = 0;
            }

        }

    }
    for (int i = 0; i < threadCounter; ++i) {
        workers[i].join();
    }
    return newPic;
}






void PicLibrary::blur(string filename) {
    Picture pic = this->internalPicStorage[filename];
    int width  = pic.getwidth();
    int height = pic.getheight();
    Picture newPic = Picture(width, height);
    using namespace std::chrono;
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
//    for (int x = 0; x < width; x++) {
//        for (int y = 0; y < height; y++) {
//            if (x == 0 || x == width - 1 || y == 0 || y == height - 1) {
//                newPic.setpixel(x, y, pic.getpixel(x, y));
//            } else {
//                int red = 0;
//                int green = 0;
//                int blue = 0;
//                for (int i = x - 1; i < x + 2; i++) {
//                    for (int j = y - 1; j < y + 2; j++) {
//                        Colour currentPix = pic.getpixel(i, j);
//                        blue = blue + currentPix.getblue();
//                        green = green + currentPix.getgreen();
//                        red = red + currentPix.getred();
//                    }
//                }
//                Colour newColour = Colour(red / 9, green / 9, blue / 9);
//                newPic.setpixel(x, y, newColour);
//            }
//        }
//    }
    newPic = colBlur(pic, newPic, width, height);

//    newPic = sectorsBlur(pic, newPic, width, height, 4);
//    newPic = rowBlur(pic, newPic, width, height);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    int duration = duration_cast<milliseconds>(t2 - t1).count();

    std::cout << "It took me " << duration << " milliseconds.";
    this->internalPicStorage[filename] = newPic;
}

