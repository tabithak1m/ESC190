#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>


// 1. Write a header file for operating on linked lists (include at least inserting a value, 
//    deleting a node with a specified value (if there is more than one, delete the first one), 
//    and freeing the entire linked list). 
//    Write a file linkedlist.c that implements the functions declared in the h file. 
//    Now write a main file with a main function that uses the functions declared in the h file. 
//    Make sure that everything compiles and runs correctly.



// 2. In Python, write a function find(L, e) that takes in a sorted list L and an element e, 
//    and returns the lowest index in L such that L[i] == e. (-1 if there is no such index)
//    Write a function that takes in a sorted linst L and an element e, 
//    and returns the index of the highest index in L such that L[i] == e. (-1 if there is no such index).
//    The function should run in O(log(n)) time.
//    This should help you with Project 1.


int main(){
    node *node0 = (node *)malloc(sizeof(node));
    node0->data = 0;
    node *node1 = (node *)malloc(sizeof(node));
    node1->data = 1;
    node *node2 = (node *)malloc(sizeof(node));
    node2->data = 2;
    node0->next = node1;
    node1->next = node2;
    node2->next = NULL;
    print_list(node0);
    insert(node0, 2, 10);
    print_list(node0);
    delete_value(node0, 10);
    print_list(node0);
    free_list(node0);
    print_list(node0);
    return 0;
}