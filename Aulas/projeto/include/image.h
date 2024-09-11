#ifndef IMAGE_H
#define IMAGE_H

typedef struct {
    int width;
    int height;
    int maxGrayValue;
    int** pixels;
} Image;

Image* readPGM(const char* filename);
void savePGM(const Image* img, const char* filename);
void freeImage(Image* img);

#endif
