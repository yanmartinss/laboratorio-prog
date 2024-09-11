#ifndef COMPRESS_H
#define COMPRESS_H

void compressBlock(int** pixels, int x, int y, int blockSize, double threshold, FILE* bitstream);
void reconstructImage(const char* bitstreamFilename, const char* outputPGM, int width, int height);

#endif
