#ifndef ENCRYPT_H
#define ENCRYPT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


typedef struct Block {
    /* block of data */
    unsigned char data[4][4];

} Block;

Block* blocks;

Block key;

unsigned char expanded_key[176];

int num_of_blocks;



void blockify(unsigned char* data, int length);

void rotate(unsigned char *in);

void rotate_block(int b, int r, int n);

void xor_(int b, int r, unsigned char* key);

void expand_key();

void update_key(int round);

void gmix_column(unsigned char *r);

void set_key(unsigned char* key_in);

void encrypt(unsigned char* in, int length);

void getcol(int i, int col, unsigned char* out);

void setcol(int i, int col, unsigned char* in);

void get_ciphertext(unsigned char* out);


#endif