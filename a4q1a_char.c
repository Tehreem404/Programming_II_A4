#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Commands.h"
#include "Sorted_List.h"

int main(int argc, char *argv[]) {
  Sorted_node *sorted_l = create_list();
  char command[30];
  char line[100];

  /* opening file */
  FILE *fp;
  fp = fopen(argv[1], "r");
  /* file error check */
  if ((fp = fopen(argv[1], "r")) == NULL) {
    printf("File chosen was not found\n");
    printf("Usage: ./a4q1a_int <filename>\n");
    exit(1);
  }
  /* retrieving information from file line by line  */
  while (fgets(line, 100, fp) != NULL) {
    /* storing first command from line */
    sscanf(line, "%s", command);
    /* Using command and strcmp to find which command it is */
    if (strcmp(command, "p") == 0) {
      int i = 1;
      int linelen = strlen(line);
      value_type value;
      for (i = 1; i < linelen && line[i] != ' '; i++) {
        /* do nothing */
      }
      line[linelen - 1] = '\0';
      key_type key = strlen(&line[i]);
      if (key == 0) {
        value[0] = ' ';
        value[1] = '\0';
      } else {
        strcpy(value, &line[i]);
      }
      print_key_value_pair_p(sorted_l, value, key);
    } else if (strcmp(command, "a") == 0) {
      int i = 1;
      int linelen = strlen(line);
      value_type value;
      for (i = 1; i < linelen && line[i] != ' '; i++) {
        /* do nothing */
      }
      line[linelen - 1] = '\0';
      key_type key = strlen(&line[i]);
      if (key == 0) {
        value[0] = ' ';
        value[1] = '\0';
      } else {
        strcpy(value, &line[i]);
      }
      print_key_value_pair_a(sorted_l, value, key);
    } else if (strcmp(command, "rem_first") == 0) {
      rem_first(sorted_l);
    } else if (strcmp(command, "rem_last") == 0) {
      rem_last(sorted_l);
    } else if (strcmp(command, "rem_small") == 0) {
      rem_small(sorted_l);
    } else if (strcmp(command, "rem_large") == 0) {
      rem_large(sorted_l);
    } else if (strcmp(command, "empty") == 0) {
      empty(sorted_l);
    } else if (strcmp(command, "size") == 0) {
      get_size(sorted_l);
    } else if (strcmp(command, "print_all") == 0) {
      print_all(sorted_l);
    } else if (strcmp(command, "print_sort") == 0) {
      print_sort(sorted_l);
    } else {
      printf("Error:      command unrecognizable\n");
    }
  }
  return (0);
}