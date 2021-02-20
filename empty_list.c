#include "a4q1a.h"

void empty_list(Sorted_node *sorted_l) {
  Node *prev_node = NULL;
  Node *next_node = sorted_l->head;

  while (next_node != NULL) {
    prev_node = next_node;
    next_node = next_node->next;
    free(prev_node);
  }
  /* resetting all sorted_l values */
  sorted_l->size = 0;
  sorted_l->head = NULL;
  sorted_l->tail = NULL;
  sorted_l->head_sort = NULL;
  sorted_l->tail_sort = NULL;
}