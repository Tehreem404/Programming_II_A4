/*ALL documentation in associated .h file*/

#include "Sorted_List.h"

Sorted_node *create_list(void) {
  Sorted_node *sorted_l = malloc(sizeof(Sorted_node));
  sorted_l->size = 0;
  sorted_l->head = NULL;
  sorted_l->tail = NULL;
  sorted_l->head_sort = NULL;
  sorted_l->tail_sort = NULL;

  return (sorted_l);
}

int size(Sorted_node *sorted_l) { return (sorted_l->size); }

int push(Sorted_node *sorted_l, value_type value, key_type key) {
  Node *push_node = malloc(sizeof(Node));
  if (push_node == NULL) {
    printf("Error: memory cannot be allocated\n");
    return (FAILURE);
  }
  push_node->key = key;

  #ifdef INT
    push_node->value = value;
  #endif

  #ifdef CHAR
    strcpy(push_node->value, value);
  #endif
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
    sorted_l->head->prev = push_node;
    push_node->next = sorted_l->head;
    sorted_l->head = push_node;
  }
  sorted_l->size++;
  return (SUCCESS);
}

int append(Sorted_node *sorted_l, value_type value, key_type key) {
  Node *push_node = malloc(sizeof(Node));
  if (push_node == NULL) {
    printf("Error: memory cannot be allocated\n");
    return (FAILURE);
  }
  push_node->key = key;

  #ifdef INT
    push_node->value = value;
  #endif

  #ifdef CHAR
    strcpy(push_node->value, value);
  #endif

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

int remove_first(Sorted_node *sorted_l, value_type *value, key_type *key) {
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

  /* Removing the head */
  Node *temp = sorted_l->head;
  temp->next->prev = NULL;
  sorted_l->head = temp->next;

  /* Creating temps to find removed node's sort position */
  Node *temp_prev = temp->prev_sort;
  Node *temp_next = temp->next_sort;
  /* Checking for NULL cases */
  if (temp_next == NULL && temp_prev == NULL) {
    sorted_l->head_sort = temp;
    sorted_l->head = temp;
    sorted_l->tail = temp;
    sorted_l->tail_sort = temp;
  } else if (temp_next == NULL) {
    /* Linking next to NULL */
    temp_prev->next_sort = NULL;
    sorted_l->tail_sort = temp_prev;
  } else if (temp_prev == NULL) {
    /* Linking prev to NULL */
    temp_next->prev_sort = NULL;
    sorted_l->head_sort = temp_next;
  } else {
    /* Linking the previous and next nodes */
    temp_next->prev_sort = temp_prev;
    temp_prev->next_sort = temp_next;
  }

  #ifdef INT
    *value = temp->value;
  #endif

  #ifdef CHAR
    strcpy(*value, temp->value);
  #endif

  *key = temp->key;
  sorted_l->size--;

  /* Freeing the removed node */
  free(temp);
  return (SUCCESS);
}

int remove_last(Sorted_node *sorted_l, value_type *value, key_type *key) {
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

  /* Removing the head */
  Node *temp = sorted_l->tail;
  temp->prev->next = NULL;
  sorted_l->tail = temp->next;

  /* Creating temps to find removed node's sort position */
  Node *temp_prev = temp->prev_sort;
  Node *temp_next = temp->next_sort;
  /* Checking for NULL cases */
  if (temp_next == NULL && temp_prev == NULL) {
    sorted_l->head_sort = temp;
    sorted_l->head = temp;
    sorted_l->tail = temp;
    sorted_l->tail_sort = temp;
  } else if (temp_next == NULL) {
    /* Linking next to NULL */
    temp_prev->next_sort = NULL;
    sorted_l->tail_sort = temp_prev;
  } else if (temp_prev == NULL) {
    /* Linking prev to NULL */
    temp_next->prev_sort = NULL;
    sorted_l->head_sort = temp_next;
  } else {
    /* Linking the previous and next nodes */
    temp_next->prev_sort = temp_prev;
    temp_prev->next_sort = temp_next;
  }

  #ifdef INT
    *value = temp->value;
  #endif

  #ifdef CHAR
    strcpy(*value, temp->value);
  #endif

  *key = temp->key;
  sorted_l->size--;

  /* Freeing the removed node */
  free(temp);
  return (SUCCESS);
}

int remove_smallest_key(Sorted_node *sorted_l, value_type *value,
                        key_type *key) {
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

  /* Removing the smallest key */
  Node *temp = sorted_l->head_sort;
  temp->next_sort->prev_sort = NULL;
  sorted_l->head_sort = temp->next_sort;

  /* Creating temps to find removed node's insertion position */
  Node *temp_prev = temp->prev;
  Node *temp_next = temp->next;
  /* Checking for NULL cases */
  if (temp_next == NULL && temp_prev == NULL) {
  } else if (temp_next == NULL) {
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

  #ifdef INT
    *value = temp->value;
  #endif

  #ifdef CHAR
    strcpy(*value, temp->value);
  #endif

  *key = temp->key;
  sorted_l->size--;

  /* Freeing the removed node */
  free(temp);
  return (SUCCESS);
}

int remove_largest_key(Sorted_node *sorted_l, value_type *value,
                       key_type *key) {
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
  if (temp_next == NULL && temp_prev == NULL) {
  } else if (temp_next == NULL) {
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

  #ifdef INT
    *value = temp->value;
  #endif

  #ifdef CHAR
    strcpy(*value, temp->value);
  #endif

  *key = temp->key;
  sorted_l->size--;

  /* Freeing the removed node */
  free(temp);
  return (SUCCESS);
}

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

void destroy_list(Sorted_node *sorted_l) {
  empty_list(sorted_l);
  free(sorted_l);
}

/* value_type map_reduce(Sorted_node *sorted_l, RedFn fn, MapFn fn, value_type init,
                      int order) {
  Node *node = sorted_l->head;
  value_type result = init;

  if (sorted_l == NULL) {
    printf("Error:      Invalid pointer to sorted_l\n");
    exit(FAILURE);
  }

  for (i = 0; i < size(sorted_l); i++) {
    result = reduce(node->value, map(result),);
    node = node->next
  }

  return (result);
} */

#ifdef INT
  Sorted_node *map(Sorted_node *sorted_l, MapFn fn) {
    Node *node = sorted_l->head;
    Sorted_node *new_list = create_list();
    int i;

    if (sorted_l == NULL) {
      printf("Error:      Invalid pointer to sorted_l\n");
      exit(FAILURE);
    }

    for (i = 0; i < size(sorted_l); i++) {
      append(new_list, fn(node->value), node->key);
      node = node->next;
    }

    return (new_list);
  }

  Sorted_node *reduce(Sorted_node *sorted_l, RedFn fn, value_type init) {
    Node *node = sorted_l->head;
    Sorted_node *new_list = create_list();
    value_type result = init;
    int i;

    if (sorted_l == NULL) {
      printf("Error:      Invalid pointer to sorted_l\n");
      exit(FAILURE);
    }

    for (i = 0; i < size(sorted_l); i++) {
      append(new_list, fn(node->value, result), node->key);
      node = node->next;
    }

    return (new_list);
  }
#endif
/**
 * Print statements will be different based on the datatype
 * #ifdef lets us conditionally compile code based on which type we are using
 */

/*Put Code for printing Integer data here*/
#ifdef INT
    void
    print_all(Sorted_node *sorted_l) {
  Node *iter = sorted_l->head;

  printf("print_all: Insertion Order\n");
  while (iter) {
    printf("     %f  %d\n", iter->key, iter->value);
    iter = iter->next;
  }
}

void print_sort(Sorted_node *sorted_l) {
  Node *sort_iter = sorted_l->head_sort;

  printf("print_sort: Key Sort Order\n");
  while (sort_iter) {
    printf("     %f  %d\n", sort_iter->key, sort_iter->value);
    sort_iter = sort_iter->next_sort;
  }
}

void print_key_value_pair_a(Sorted_node *sorted_l, value_type value,
                            key_type key) {
  append(sorted_l, value, key);
  printf("a:          %f  %d\n", key, value);
}

void print_key_value_pair_p(Sorted_node *sorted_l, value_type value,
                            key_type key) {
  push(sorted_l, value, key);
  printf("p:          %f  %d\n", key, value);
}

#endif

/*Put Code for printing Char data here*/
#ifdef CHAR
void print_all(Sorted_node *sorted_l) {
  Node *iter = sorted_l->head;

  printf("print_all: Insertion Order\n");
  while (iter) {
    printf("     %d  %s\n", iter->key, iter->value);
    iter = iter->next;
  }
}

void print_sort(Sorted_node *sorted_l) {
  Node *sort_iter = sorted_l->head_sort;

  printf("print_sort: Key Sort Order\n");
  while (sort_iter) {
    printf("     %d  %s\n", sort_iter->key, sort_iter->value);
    sort_iter = sort_iter->next_sort;
  }
}

void print_key_value_pair_a(Sorted_node *sorted_l, value_type value,
                            key_type key) {
  append(sorted_l, value, key);
  printf("a:          %d  %s\n", key, value);
}

void print_key_value_pair_p(Sorted_node *sorted_l, value_type value,
                            key_type key) {
  push(sorted_l, value, key);
  printf("p:          %d  %s\n", key, value);
}

#endif
