#include "decode.h"

int offset(char ascii_value)
{
    int i;
    int counter = 0;

    if (ascii_value >= 'a' && ascii_value <= 'z'){
        for (i = 'a'; i <= 'z'; i++){
            if (ascii_value == i){
                break;
            } else {
                counter++;
            }
        }
    }
    if (ascii_value >= 'A' && ascii_value <= 'Z'){
        for (i = 'A'; i <= 'Z'; i++){
            if (ascii_value == i){
                break;
            } else {
                counter++;
            }
        }
    } 
    return(counter);
}