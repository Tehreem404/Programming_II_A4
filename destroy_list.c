#include "a4q1a.h"

void empty_list(Sorted_node *sorted_l);

void destroy_list(Sorted_node *sorted_l) {
  empty_list(sorted_l);
  free(sorted_l);
}