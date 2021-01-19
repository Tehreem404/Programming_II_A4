#include "decode.h"

int file_size(FILE *fp)
{   
    /*calculating file size in bytes*/
    int sz = 0;
    fseek(fp, 0L, SEEK_END);
    sz = ftell(fp);
    rewind(fp);
    return(sz);
}