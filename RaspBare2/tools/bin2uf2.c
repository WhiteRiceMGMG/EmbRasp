// bin2uf2.c - convert binary file to UF2 format

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>


#define UF2_MAGIC_START0 0x0A324655
#define UF2_MAGIC_START1 0x9E5D5157
#define UF2_MAGIC_END    0x0AB16F30
#define UF2_FLAG_FAMILYID_PRESENT (1 << 1)
#define RP2040_FAMILY_ID 0xE48BFF56

typedef struct {
    uint32_t magicStart0;
    uint32_t magicStart1;
    uint32_t flags;
    uint32_t targetAddr;
    uint32_t payloadSize;
    uint32_t blockNo;
    uint32_t numBlocks;
    uint32_t fileSize;
    uint32_t reserved[3];
    uint32_t familyID;
    uint8_t  data[256];
    uint32_t magicEnd;
} UF2_Block;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s input-crc.bin output.uf2\n", argv[0]);
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

    int numBlocks = (size + 255) / 256;
    FILE *fout = fopen(argv[2], "wb");
    if (!fout) {
        perror("fopen output");
        return 1;
    }

    for (int i = 0; i < numBlocks; i++) {
        UF2_Block block = {0};
        block.magicStart0 = UF2_MAGIC_START0;
        block.magicStart1 = UF2_MAGIC_START1;
        block.flags = UF2_FLAG_FAMILYID_PRESENT;
        block.targetAddr = 0x10000000 + i * 256;
        block.payloadSize = 256;
        block.blockNo = i;
        block.numBlocks = numBlocks;
        block.familyID = RP2040_FAMILY_ID;
        block.magicEnd = UF2_MAGIC_END;

        int remain = size - i * 256;
        if (remain < 256) {
            memset(block.data, 0, 256);
        }
        memcpy(block.data, buf + i * 256, remain > 256 ? 256 : remain);

        fwrite(&block, 1, sizeof(UF2_Block), fout);
    }

    fclose(fout);
    free(buf);

    return 0;
}
