#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Commands.h"
#include "Sorted_List.h"

int sqr (int num){
    num = num * num;
    return (num);
}

int add (int num1, int num2){
    return(num1 + num2);
}

int main(int argc, char *argv[]) {
    Sorted_node *sort_l = create_list();
    MapFn map_sqr = sqr;
    push(sort_l, 1, 4.0);
    push(sort_l, 5, 7.0);
    push(sort_l, 8, 4.0);

    Sorted_node * mapped_l = map(sort_l, map_sqr);
    
    print_all(sort_l);
    print_all(mapped_l);

    int init = 0;
    RedFn red_add = add;
    Sorted_node * reduced_l = reduce(sort_l, red_add, init);

    print_all(sort_l);
    print_all(reduced_l);
}