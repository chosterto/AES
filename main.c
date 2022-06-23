#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "encrypt.h"

int main() {
    unsigned char in[90000];
    unsigned char* out;
    // 128-bit key size
    unsigned char k[16];
    char ch;
    int len;
    int temp;
    FILE *fptr;

    printf("Enter key: ");
    scanf("%s", k);

    if (strlen(k) != 16) {
        printf("Key must be 16 characters in length!");
        exit(1);
    }

    fptr = fopen("input.txt", "rb");
    if (fptr == NULL) {
        exit(1);
    }

    len = 0;
    while ((ch = fgetc(fptr)) != EOF) {
        in[len] = ch;
        len++;
    }

    set_key(k);

    encrypt(in, len);

    out = (unsigned char*)malloc((num_of_blocks * 16) * sizeof(unsigned char));

    get_ciphertext(out);

    fptr = fopen("output.txt", "wb");

    for (int i = 0; i < num_of_blocks * 16; i++) {
        fprintf(fptr, "%02x", out[i]);
    }

    printf("Text Encrypted! Check output file...");

    fclose(fptr);

    return 0;
}
