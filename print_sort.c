#include "a4q1a.h"

void print_sort(Sorted_node *sorted_l) {
  Node *sort_iter = sorted_l->head_sort;

  printf("print_sort: Key Sort Order\n");
  while (sort_iter) {
    printf("      %f  %d\n", sort_iter->key, sort_iter->value);
    sort_iter = sort_iter->next_sort;
  }
}