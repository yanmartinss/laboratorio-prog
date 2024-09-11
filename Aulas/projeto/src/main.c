#include <stdio.h>
#include <stdlib.h>
#include "image.h"
#include "compress.h"

int main() {
    double threshold = 100.0;

    // Lê a imagem PGM
    Image* img = readPGM("data/input.pgm");
    if (img) {
        // Abre arquivo de bitstream
        FILE* bitstream = fopen("data/bitstream.txt", "w");
        if (!bitstream) {
            printf("Erro ao abrir o arquivo de bitstream!\n");
            freeImage(img);
            return 1;
        }

        // Compressão
        compressBlock(img->pixels, 0, 0, img->width, threshold, bitstream);
        fclose(bitstream);
        freeImage(img);

        printf("Compressão concluída e salva em bitstream.txt\n");

        // Reconstrução
        reconstructImage("data/bitstream.txt", "data/output.pgm", img->width, img->height);
    }
    return 0;
}
