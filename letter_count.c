#include "decode.h"

int letter_count(char *word_array)
{
    int letter_counter = 0;
    int i = 0;
    /* counting the number of letters in the array */
    while (word_array[i] != '\0'){
        if ((word_array[i] >= 'a' && word_array[i] <= 'z') || (word_array[i] >= 'A' && word_array[i] <= 'Z')){
            letter_counter++;
        }
        i++;
    }
    return(letter_counter);
}