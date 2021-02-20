#include "a4q1a.h"

int append(Sorted_node *sorted_l, value_type value, key_type key) {
  Node *push_node = malloc(sizeof(Node));
  if (push_node == NULL) {
    printf("Error: memory cannot be allocated\n");
    return (FAILURE);
  }
  push_node->key = key;
  push_node->value = value;

  if (sorted_l == NULL) {
    printf("Error: the list is empty\n");
    return (FAILURE);
  }

  if (sorted_l->head_sort == NULL) {
    sorted_l->head_sort = push_node;
    sorted_l->head = push_node;
    sorted_l->tail = push_node;
    sorted_l->tail_sort = push_node;
  } else {
    Node *temp_next = sorted_l->head_sort;
    Node *temp_prev = temp_next->prev_sort;

    /* traversing through the temps to see which position new node should be
     * inserted */
    while ((temp_next != NULL) && (push_node->key > temp_next->key)) {
      temp_prev = temp_next;
      temp_next = temp_next->next_sort;
    }

    /* Checking the positions of the temps and linking the new node in the
     * sorted order */
    if (temp_prev == NULL) {
      temp_next->prev_sort = push_node;
      push_node->next_sort = temp_next;
      sorted_l->head_sort = push_node;
    } else if (temp_next == NULL) {
      temp_prev->next_sort = push_node;
      push_node->prev_sort = temp_prev;
      sorted_l->tail_sort = push_node;
    } else if (temp_next != NULL && temp_prev != NULL) {
      temp_next->prev_sort = push_node;
      push_node->next_sort = temp_next;
      temp_prev->next_sort = push_node;
      push_node->prev_sort = temp_prev;
    }

    /* linking the new node in insertion order */
    sorted_l->tail->next = push_node;
    push_node->prev = sorted_l->tail;
    sorted_l->tail = push_node;
  }
  sorted_l->size++;
  return (SUCCESS);
}