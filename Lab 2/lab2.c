#include <stdio.h>
#include <stdlib.h>

// struct node{
//     int data; 
//     struct node *next; 
// };

// void print(struct node *head){
//     printf("[");
//     while(head->next != NULL){
//         printf("%d, ", head->data);
//         head = head->next;
//     }
//     printf("%d", head->data);
//     printf("]");
// }

struct node{
    void *p_data; //a pointer to data (allocated with malloc)
    int type; // 0 if int, 1 if float, 2 if double
    struct node *next;
};

void print_type(struct node *head){
    if(head->type == 0){
        printf("%d, ", *((int *)(head->p_data)));
    } else if (head->type == 1){
        printf("%f, ", *((float *)(head->p_data)));
    } else if (head->type == 2){
        printf("%lf, ", *((double *)(head->p_data)));
    }
}

void print(struct node *head){
    printf("[");
    while(head->next != NULL){
        // printf("%d, ", *((int *)(head->p_data)));
        print_type(head);
        head = head->next;
    }

    // printf("%d", *((int *)(head->p_data)));
    print_type(head);
    printf("\b\b]");
}

// void print2(struct node *head){
//     printf("%d ", head->data);
//     if(head->next == NULL){
//         return;
//     } else {
//         print2(head->next);
//     }
// }



void append_int(struct node *head, int value){
    struct node *cur = head;
    while(cur->next != NULL){
        cur = cur->next;
    }
    // cur->next is now equal to null
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->type = 0;
    int *p = (int*)malloc(sizeof(int));
    *p = value;
    node->p_data = p;
    node->next = NULL;
    cur->next = node;
}

void append_float(struct node *head, float value){
    struct node *cur = head;
    while(cur->next != NULL){
        cur = cur->next;
    }
    // cur->next is now equal to null
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->type = 1;
    float *p = (float*)malloc(sizeof(float));
    *p = value;
    node->p_data = p;
    node->next = NULL;
    cur->next = node;
}

void append_double(struct node *head, double value){
    struct node *cur = head;
    while(cur->next != NULL){
        cur = cur->next;
    }
    // cur->next is now equal to null
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->type = 2;
    double *p = (double*)malloc(sizeof(double));
    *p = value;
    node->p_data = p;
    node->next = NULL;
    cur->next = node;
}



int main(){
    struct node *node0 = (struct node *)malloc(sizeof(struct node));
    int *p = (int*)malloc(sizeof(int));
    *p = 1;
    node0->p_data = p;
    node0->next = NULL;
    append_int(node0, 3);
    append_float(node0, 2.0);
    append_double(node0, 4.34813471029384);
    // node0->data = 3; // the data in the address node0 // equivalent to (*node0).data = 3;

    // struct node *node1 = (struct node *)malloc(sizeof(struct node));
    // node0->next = node1; 
    // node1->data = 5;
    // node1->next = NULL;
    print(node0);




    return 0;
}