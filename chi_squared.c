#include "decode.h"

double chi_squared(double EF[], int text_freq[], int shift, int n)
{
    char c = 'a';
    char s[] = "a";
    int i;
    double chi_sq;
    double sum = 0;
    /* Chi-squared formula */
    for (i = 0; i < 26; i++) {
        c = 'a' + i;
        s[0] = c;
        chi_sq = n * EF[offset(c)] - text_freq[offset(*encode(s, shift))];
        chi_sq = chi_sq * chi_sq;
        chi_sq = chi_sq / (n * n * EF[offset(c)]);
        sum += chi_sq;
    }
    return(sum);
}