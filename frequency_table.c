#include "decode.h"

int main (int argc, char *argv[])
{
    FILE *fp;
    int flag;
    int counter = 0;
    char *filename;
    char *file_array;

    /* https://www.youtube.com/watch?v=SjyR74lbZOc&feature=emb_logo
    was refrenced to account for flags */
    while ((flag = getopt(argc, argv, "F:")) != -1){
        switch (flag){
            case 'F':
                filename = optarg;
                counter++; 
                break; 
        }
    }
    if (counter == 1){
        fp = fopen(filename, "r");
        if (fopen(filename, "r") == NULL){
            printf("File selected is empty or does not exist\n");
        }
        
        int max_words = file_size(fp);
        char buffer_array[max_words];

        file_array = malloc(sizeof(char) * (max_words));
        while (fgets(buffer_array, max_words, fp) != NULL){
            strcat(file_array, buffer_array);
        }
        file_array[strlen(file_array) + 1] = '\0';

        int *f_count = create_freqt(file_array);
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

        printf("The number of unique letters in the text are %d\n", c_count);
        printf("The total number of characters in this text are %ld\n", strlen(file_array));
        
        for (letter = 'A'; letter <= 'Z'; letter++){
            printf("%c:\t%d\n", letter, f_count[j]);
            j++;
        }

        fclose(fp);
        free(f_count);
        free(file_array);

    } else if (counter == 0 && argc == 1){
        char file_array[MAXLEN];

        printf ("Enter input to create frequency table:\n");
        fgets(file_array, MAXLEN, stdin);
        file_array[strlen(file_array)-1] = '\0';

        int *f_count = create_freqt(file_array);
        int i = 0;
        int c_count = 0;
        
        while (i < 26){
            if (f_count[i] > 0){
                c_count++;
            }
            i++;
        }

        printf("The number of unique letters in the text are %d\n", c_count);
        printf("The total number of characters in this text are %ld\n", strlen(file_array));

        char letter;
        int j = 0;
        
        for (letter = 'A'; letter <= 'Z'; letter++){
            printf("%c:\t%d\n", letter, f_count[j]);
            j++;
        }

        free(f_count);
    } else {
        printf ("Usage 1: ./frequency_table\n");
        printf ("Usage 2: ./frequency_table -F <filename>\n");
    }
    
    return(0);
}