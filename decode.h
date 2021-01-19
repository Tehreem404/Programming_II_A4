#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

#include "eng_freq.h"

double chi_squared(double EF[], int text_freq[], int shift, int n);
int *create_freqt (char *word_array);
int encode_shift(int text_freq[], int n);
char *encode(char *string, int key);
int file_size(FILE *fp);
int main (int argc, char *argv[]);
int letter_count(char *word_array);
int offset(char ascii_value);
int to_decode(int shift);