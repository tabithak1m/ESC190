#ifndef linkedlist_h
#define linkedlist_h

typedef struct node{
    int data;
    struct node *next;
} node;

void insert(node *head, int index, int value);
void delete_value(node *head, int value);
void free_list(node *head);
void print_list(node *head);

#endif