#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>


void insert(node *head, int index, int value){
    for(int i = 0; i < index-1; i++){
        if(head == NULL){
            return;
        }
        head = head->next;
    }
    node *temp_node = head->next;
    node *new_node = (node *)malloc(sizeof(node));
    head->next = new_node;
    new_node->data = value;
    new_node->next = temp_node;
}


void delete_value(node *head, int value){
    while(head->next->data != value){
        head = head->next;
    }
    node *temp_node = head->next->next;
    free(head->next);
    head->next = temp_node;
}

void free_list(node *head){
    if (head->next){
        free_list(head->next);
    }
    free(head);
}

void print_list(node *head){
    while(head){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

