#include "decode.h"

char *encode(char *string, int key)
{
    char crypt;
    int i;
    /* encodes the array to the chosen shift */
    for (i = 0; string[i] != '\0'; i++){
        crypt = string[i];
        /* checking if letters are upper case */
        if (crypt >= 'A' && crypt <= 'Z'){
            crypt -= 'A';
            crypt += key;
            crypt %= 26;
            crypt += 'A';
            string[i] = crypt;
        /* Checking if letters are lower case */
        } else if (crypt >= 'a' && crypt <= 'z'){
            crypt -= 'a';
            crypt += key;
            crypt %= 26;
            crypt += 'a';
            string[i] = crypt;
        }
    }
    return(string);
}