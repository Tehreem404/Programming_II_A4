#include "decode.h"

int encode_shift(int text_freq[], int n)
{
    int i = 0;
    int count;
    double sum, buffer_sum;
    sum = chi_squared(EF, text_freq, i, n);
    /* checking if the next value is less until lowest chi-squared number is found */
    for (i = 0; i < 26; i++){
        buffer_sum = chi_squared(EF, text_freq, i+1, n);
        if (sum > buffer_sum){
            sum = buffer_sum;
        }
    }
    /* looping through all chi-squared possibilities to find which number the shift is at */
    for (i = 0; i < 26; i++){
        count = i;
        buffer_sum = chi_squared(EF, text_freq, i+1, n);
        if (sum == buffer_sum){
            break;
        }
    }
    /* output was off by one */
    count++;
    return(count);
}