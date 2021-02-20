#include "Commands.h"
#include "Sorted_List.h"

void rem_first(Sorted_node *sorted_l) {
  value_type value;
  key_type key;
  if (sorted_l == NULL) {
    printf("rem_first:  Nothing to remove\n");
  } else {
    #ifdef INT
      remove_first(sorted_l, &value, &key);
      printf("rem_first:  %f  %d\n", key, value);
    #endif
    #ifdef CHAR
      remove_first(sorted_l, &value, &key);
      printf("rem_first:  %d  %s\n", key, value);
    #endif

  }
}

void rem_last(Sorted_node *sorted_l) {
  value_type value;
  key_type key;
  if (sorted_l == NULL) {
    printf("rem_last:   Nothing to remove\n");
  } else {
    #ifdef INT
      remove_last(sorted_l, &value, &key);
      printf("rem_last:   %f  %d\n", key, value);
    #endif
    #ifdef CHAR
      remove_last(sorted_l, &value, &key);
      printf("rem_last:   %d  %s\n", key, value);
    #endif
  }
}

void rem_small(Sorted_node *sorted_l) {
  value_type value;
  key_type key;
  if (sorted_l == NULL) {
    printf("rem_small:  Nothing to remove\n");
  } else {
    #ifdef INT
      remove_smallest_key(sorted_l, &value, &key);
      printf("rem_small:  %f  %d\n", key, value);
    #endif
    #ifdef CHAR
      remove_smallest_key(sorted_l, &value, &key);
      printf("rem_small:  %d  %s\n", key, value);
    #endif
  }
}

void rem_large(Sorted_node *sorted_l) {
  value_type value;
  key_type key;
  if (sorted_l == NULL) {
    printf("rem_large:  Nothing to remove\n");
  } else {
    #ifdef INT
      remove_largest_key(sorted_l, &value, &key);
      printf("rem_large:  %f  %d\n", key, value);
    #endif
    #ifdef CHAR
      remove_largest_key(sorted_l, &value, &key);
      printf("rem_large:  %d  %s\n", key, value);
    #endif
  }
}

void empty(Sorted_node *sorted_l) {
  empty_list(sorted_l);
  printf("empty:      size=%d", size(sorted_l));
}

void get_size(Sorted_node *sorted_l) {
  printf("size:       List size = %d\n", size(sorted_l));
}