#ifndef _COMMANDS_
#define _COMMANDS_

#include "Sorted_List.h"
#include "Commands.h"

void psh(char *line, char *command, Sorted_node *sorted_l);
void apnd(char *line, char *command, Sorted_node *sorted_l);
void rem_first(Sorted_node *sorted_l);
void rem_last(Sorted_node *sorted_l);
void rem_small(Sorted_node *sorted_l);
void rem_large(Sorted_node *sorted_l);
void empty(Sorted_node *sorted_l);
void get_size(Sorted_node *sorted_l);

#endif
