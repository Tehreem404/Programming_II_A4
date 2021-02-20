#include "a4q1a.h"

int remove_largest_key(Sorted_node *sorted_l, value_type *value, key_type *key) {
  if (sorted_l == NULL) {
    printf("Error: sorted_l is not a valid pointer\n");
    return (FAILURE);
  }
  if (key == NULL) {
    printf("Error: key is not a valid pointer\n");
    return (FAILURE);
  }
  if (value == NULL) {
    printf("Error: value is not a valid pointer\n");
    return (FAILURE);
  }

  /* Removing the largest in sort */
  Node *temp = sorted_l->tail_sort;
  temp->prev_sort->next_sort = NULL;
  sorted_l->tail_sort = temp->prev_sort;

  /* Creating temps to find removed node's insertion position */
  Node *temp_prev = temp->prev;
  Node *temp_next = temp->next;
  /* Checking for NULL cases */
  /* if (temp_next == NULL && temp_prev == NULL){

    } else  */
  if (temp_next == NULL) {
    /* Linking next to NULL */
    temp_prev->next = NULL;
    sorted_l->tail = temp_prev;
  } else if (temp_prev == NULL) {
    /* Linking prev to NULL */
    temp_next->prev = NULL;
    sorted_l->head = temp_next;
  } else {
    /* Linking the previous and next nodes */
    temp_next->prev = temp_prev;
    temp_prev->next = temp_next;
  }

  *value = temp->value;
  *key = temp->key;
  sorted_l->size--;
  
  /* Freeing the removed node */
  free(temp);
  return (SUCCESS);
}
