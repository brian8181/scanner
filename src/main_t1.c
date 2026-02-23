//
// Created by brian on 2/22/2026.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Test
{
    unsigned char a;
    unsigned char b;
    unsigned char c;
    unsigned int d;
} Test;

int main(int argc, char* argv[])
{
    printf("sizeof = %d\n", sizeof(Test));
    return 0;
}
