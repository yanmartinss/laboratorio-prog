#ifndef UTILS_H
#define UTILS_H

double calculateVariance(int** pixels, int x, int y, int blockSize);
int isHomogeneous(int** pixels, int x, int y, int blockSize, double threshold);
void writeToBitstream(FILE* bitstream, int x, int y, int blockSize, int pixelValue);

#endif
