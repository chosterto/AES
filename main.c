#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "endecrypt.h"

int main() {
    unsigned char in[90000];
    unsigned char* out;
    // 128-bit key size
    unsigned char k[16];
    int num_of_padding;
    char ch;
    int len;
    char mode;
    const char* format;
    FILE *fptr;

    printf("Encrypt (e) or Decrypt (d)? ");
    scanf("%c", &mode);
    if (mode != 'e' && mode != 'd') {
        printf("Invalid input.");
        exit(1);
    }

    printf("Enter key: ");
    scanf("%s", k);

    if (strlen(k) != 16) {
        printf("Key must be 16 characters in length!");
        exit(1);
    }

    fptr = fopen("input.txt", "rb");
    if (fptr == NULL) exit(1);

    len = 0;
    if (mode == 'e') {
        while ((ch = fgetc(fptr)) != EOF) {
            in[len] = ch;
            len++;
        }
    } else {
        while (fscanf(fptr, "%02x", &in[len]) == 1)
            len++;
    }

    set_key(k);

    if (mode == 'e') {
        encrypt(in, len);
        format = "%02x";
    } else {
        decrypt(in, len);
        format = "%c";
    }

    out = (unsigned char*)malloc((num_of_blocks * 16) * sizeof(unsigned char));
    get_ciphertext(out);
    num_of_padding = (mode == 'd') ? out[len - 1] : 0;

    fptr = fopen("output.txt", "wb");

    // Remove padding in final text
    for (int i = 0; i < num_of_blocks * 16 - num_of_padding; i++) {
        fprintf(fptr, format, out[i]);
    }

    printf("Done! Check output file...");

    free(out);
    fclose(fptr);

    return 0;
}
