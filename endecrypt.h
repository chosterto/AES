#ifndef ENDECRYPT_H
#define ENDECRYPT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>


typedef struct Block {
    /* block of data */
    unsigned char data[4][4];

} Block;

Block* blocks;

Block key;

unsigned char expanded_key[176];

int num_of_blocks;



void blockify(unsigned char* data, int length, bool is_encrypting);

void rotate(unsigned char *in);

void rotate_block(int b, int r, int n);

void rotate_block_inv(int b, int r, int n);

void xor_(int b, int r, unsigned char* key);

void expand_key();

void update_key(int round);

unsigned char gmul(unsigned char a, unsigned char b);

void gmix_column(unsigned char *r);

void gmix_column_inv(unsigned char *r);

void set_key(unsigned char* key_in);

void decrypt(unsigned char* in, int length);

void encrypt(unsigned char* in, int length);

void getcol(int i, int col, unsigned char* out);

void setcol(int i, int col, unsigned char* in);

void get_ciphertext(unsigned char* out);


#endif