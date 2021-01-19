#include "decode.h"

int to_decode(int shift)
{
    /* finding the number needed to decode the encoded message */
    int decode = 26 - shift;
    return(decode);
}