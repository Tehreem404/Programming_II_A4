#include "a4q1a.h"

void print_all(Sorted_node *sorted_l) {
  Node *iter = sorted_l->head;

  printf("print_all: Insertion Order\n");
  while (iter) {
    printf("      %f  %d\n", iter->key, iter->value);
    iter = iter->next;
  }
}