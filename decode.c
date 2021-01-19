#include "decode.h"

double EF[26] = {0.08167, 0.01492, 0.02782, 0.04253, 0.12702, 0.02228,
    0.02015, 0.06094, 0.06966, 0.00153, 0.00772, 0.04025, 0.02406,
    0.06749, 0.07707, 0.01929, 0.00095, 0.05987, 0.06327, 0.09056,
    0.02758, 0.00978, 0.02360, 0.00150, 0.01974, 0.00074};

int main (int argc, char *argv[])
{
    FILE *fp;
    FILE *fp2;
    char *filename;
    char *char_array;
    char char_array2[MAXLEN];
    char *O_filename;
    int flag;
    int case_n = 0;
    int case_s = 0;
    int case_S = 0;
    int case_t = 0;
    int case_x = 0;
    int case_F = 0;
    int case_O = 0;
    /* using optarg to find which flags are being used within stdin */
    while ((flag = getopt(argc, argv, "F:O:nsStx :")) != -1){
        switch (flag){
            case 'F':
                filename = optarg;
                case_F = 1;
                break;
            case 'O':
                O_filename = optarg;
                case_O = 1;
                break;
            case 'n':
                case_n = 1;
                break;
            case 's':
                case_s = 1;
                break;
            case 'S':
                case_S = 1;
                break;
            case 't':
                case_t = 1;
                break;
            case 'x':
                case_x = 1;
                break;
        }
    }
    if (case_n == 0 && case_s == 0 && case_S == 0 && case_t == 0 && case_x == 0 && case_F == 0 && case_O == 0){
        printf("Usage:./decode -sStxn -F <filename.txt> -O <newfile.txt>\n");
        exit(4);
    }
    if (case_F == 1){
        fp = fopen(filename, "r"); 
        if (fopen(filename, "r") == NULL){
            printf("File selected is empty or does not exist\n");
            exit(1);
        }

        int max_words = file_size(fp);
        char buffer_array[max_words];

        char_array = malloc(sizeof(char) * (max_words));
        while (fgets(buffer_array, max_words, fp) != NULL){
            strcat(char_array, buffer_array);
        }
        char_array[strlen(char_array) + 1] = '\0';
    }
    if (case_F == 0){
        char_array = malloc(sizeof(char) * (MAXLEN));
        printf ("Enter input:\n");
        fgets(char_array, MAXLEN, stdin);
        char_array[strlen(char_array) - 1] = '\0';
    }

    strcpy(char_array2, char_array);

    if (case_S == 1){
        int n = letter_count(char_array);
        int *text_freq = create_freqt(char_array);
        int encode_num = encode_shift(text_freq, n);

        encode_num = 26 - to_decode(encode_num);
        printf("\nEncode Shift: %d\n", encode_num);              
    } 
    if (case_s == 1){
        if (case_O == 1){
            fp2 = fopen(O_filename, "w+");
            if (fp2 == NULL){
                printf("File could not be created\n");
                exit(3);
            }
            /* adding the decode shift value to new file */
            int n = letter_count(char_array);
            int *text_freq = create_freqt(char_array);
            int decode_shift = encode_shift(text_freq, n);
            decode_shift = to_decode(decode_shift);
            printf("Decode Shift: %d\n", decode_shift);

            /* adding the decoded message to new file */
            char_array = encode(char_array, decode_shift);
            fprintf(fp2, "%s", char_array);
        } else {
            int n = letter_count(char_array);
            int *text_freq = create_freqt(char_array);
            int decode_shift = encode_shift(text_freq, n);

            decode_shift = to_decode(decode_shift);
            printf("Decode Shift: %d\n", decode_shift);
            if (case_n != 1) {
                char_array = encode(char_array, decode_shift);
                printf("\n%s\n", char_array);
            }
        }
    }
    if (case_t == 1){
        int *f_count = create_freqt(char_array);
        int i = 0;
        int c_count = 0;
        char letter;
        int j = 0;
        
        while (i < 26){
            if (f_count[i] > 0){
                c_count++;
            }
            i++;
        }

        printf("\nThe number of letters in the text are %d\n", c_count);
        printf("The total number of characters in this text are %ld\n", strlen(char_array));
        printf("\nLetter count table:\n");
        for (letter = 'A'; letter <= 'Z'; letter++){
            printf("%c:\t%d\n", letter, f_count[j]);
            j++;
        }
    } 
    if (case_x == 1){
        int i;
        int n = letter_count(char_array2);
        int *text_freq = create_freqt(char_array2);
        double chi_num;
        printf("\nChi-Squared table:\n");
        for (i = 0; i < 26; i++){
            chi_num = chi_squared(EF, text_freq, i, n);
            printf("%d:\t%f\n", i, chi_num);
        }
    }
    fclose(fp2);
    fclose(fp);
    free(char_array);

    return(0);
}