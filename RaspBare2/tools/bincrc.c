// bincrc.c - append CRC32 (little-endian) to the end of a binary file

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


uint32_t crc32(const void *data, size_t len) {
    uint32_t crc = ~0;
    const uint8_t *buf = data;
    while (len--) {
        crc ^= *buf++;
        for (int i = 0; i < 8; i++)
            crc = (crc >> 1) ^ (crc & 1 ? 0xedb88320 : 0);
    }
    return ~crc;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s input.bin output-crc.bin\n", argv[0]);
        return 1;
    }

    FILE *fin = fopen(argv[1], "rb");
    if (!fin) {
        perror("fopen input");
        return 1;
    }

    fseek(fin, 0, SEEK_END);
    long size = ftell(fin);
    rewind(fin);

    uint8_t *buf = malloc(size);
    if (!buf) {
        perror("malloc");
        return 1;
    }

    fread(buf, 1, size, fin);
    fclose(fin);

    uint32_t crc = crc32(buf, size);

    FILE *fout = fopen(argv[2], "wb");
    if (!fout) {
        perror("fopen output");
        return 1;
    }

    fwrite(buf, 1, size, fout);
    fwrite(&crc, 1, 4, fout);
    fclose(fout);

    return 0;
}
