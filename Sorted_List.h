#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 0
#define FAILURE 1

#ifndef _SORTED_LIST_API_
#define _SORTED_LIST_API_

#ifdef INT
    typedef int value_type;
    typedef double key_type;
    typedef int (*MapFn)(int);
    typedef int (*RedFn)(int, int);
#endif

#ifdef CHAR
    typedef char value_type[80];
    typedef int key_type;
#endif

typedef struct normal_list {
  value_type value;
  key_type key;
  struct normal_list *next;
  struct normal_list *next_sort;
  struct normal_list *prev;
  struct normal_list *prev_sort;
} Node;

typedef struct Sorted_List {
  int size;
  struct normal_list *head;
  struct normal_list *head_sort;
  struct normal_list *tail;
  struct normal_list *tail_sort;
} Sorted_node;

int size(Sorted_node *sorted_l);
int push(Sorted_node *sorted_l, value_type value, key_type key);
int append(Sorted_node *sorted_l, value_type value, key_type key);
int remove_first(Sorted_node *sorted_l, value_type *value, key_type *key);
int remove_last(Sorted_node *sorted_l, value_type *value, key_type *key);
void print_all(Sorted_node *sorted_l);
void print_sort(Sorted_node *sorted_l);
int remove_largest_key(Sorted_node *sorted_l, value_type *value, key_type *key);
int remove_smallest_key(Sorted_node *sorted_l, value_type *value, key_type *key);
void empty_list(Sorted_node *sorted_l);
void destroy_list(Sorted_node *sorted_l);
void print_key_value_pair_p(Sorted_node *sorted_l, value_type value, key_type key);
void print_key_value_pair_a(Sorted_node *sorted_l, value_type value, key_type key);
Sorted_node *create_list (void);
Node *create_node(void);
Node *dup_node(Node *node);
Sorted_node *dup_list(Sorted_node *sorted_l);

#ifdef INT
 Sorted_node *map(Sorted_node *sorted_l, MapFn fn);
 Sorted_node *reduce(Sorted_node *sorted_l, RedFn fn, value_type init);
#endif


#endif