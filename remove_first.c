#include "a4q1a.h"

int remove_first(Sorted_node *sorted_l, value_type *value, key_type *key) {

  if (sorted_l == NULL) {
    printf("Error: sorted_l is not a valid pointer\n");
    return(FAILURE);
  }
    if (key == NULL) {
    printf("Error: key is not a valid pointer\n");
    return(FAILURE);
  }
    if (value == NULL) {
    printf("Error: value is not a valid pointer\n");
    return(FAILURE);
  }

  /* Removing the head */
  Node *temp = sorted_l->head;
  temp->next->prev = NULL;
  sorted_l->head = temp->next;

  /* Creating temps to find removed node's sort position */
  Node *temp_prev = temp->prev_sort;
  Node *temp_next = temp->next_sort;
  /* Checking for NULL cases */
/*   if (temp_next == NULL && temp_prev == NULL){

  } else  */if (temp_next == NULL){
    /* Linking next to NULL */
    temp_prev->next_sort = NULL;
    sorted_l->tail_sort = temp_prev;
  } else if (temp_prev == NULL){
    /* Linking prev to NULL */
    temp_next->prev_sort = NULL;
    sorted_l->head_sort = temp_next;
  } else {
    /* Linking the previous and next nodes */
    temp_next->prev_sort = temp_prev;
    temp_prev->next_sort = temp_next;
  }

  *value = temp->value;
  *key = temp->key;
  sorted_l->size--;

  /* Freeing the removed node */
  free (temp);
  return(SUCCESS);
}
