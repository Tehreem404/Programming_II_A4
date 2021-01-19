#include "decode.h"

int *create_freqt (char *word_array)
{
    int i = 0;
    int x = 0;
    int *count = malloc(sizeof(int) * (ALPHAB));
    /* making a frequency table by using the counts of each letter */
    while (word_array[i] != '\0'){
        /* counting for lower case */
        if (word_array[i] >= 'a' && word_array[i] <= 'z'){
            x = word_array[i] - 'a';
            count[x]++;
        }
        /* counting for upper case */
        if (word_array[i] >= 'A' && word_array[i] <= 'Z'){
            x = word_array[i] - 'A';
            count[x]++;
        }
        i++;
    }
    return (count);    
}