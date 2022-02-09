#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>




char * my_strcat(char *dest, char *src){
    int i = 0;
    while(dest[i] != '\0'){
        i++;
    }
    int j = 0;
    while(src[j] != '\0'){
        dest[i++] = src[j++];
    }
    dest[i] = '\0';
    return dest;
}

int my_strcmp_rec(char *str1, char *str2){
    if(*str1 == '\0' && *str2 == '\0'){
        return 0;
    }
    if(*str1 == '\0' || *str2 == '\0' || *str1 != *str2){
        return *str1 - *str2;
    }
    return my_strcmp_rec(str1 + 1, str2 + 1);
}

int my_atoi(char *str){
    int i = 0;
    int final = 0;
    while(str[i] != '\0'){
        if(!isdigit(str[i])){
            return 0;
        }
        final *= 10;
        final += (str[i] - '0');
        i++;
    }
    return final;
}
// str[i] is the same as *(str + i)

struct node {
    int data; 
    struct node *next;
};

int floyd(struct node* head){
    struct node* tortoise = head;
    struct node* hare = head;
    while(hare != NULL){
        hare = hare->next;
        if(hare == NULL){
            return 0;
        }
        hare = hare->next;
        tortoise = tortoise->next;
        if(hare == tortoise){
            return 1;
        }
    }
    return 0;
}

int main(){
    char char1[20] = "Hi ";
    char char2[20] = "There";
    char char3[20] = "1234";
    printf("%s\n%s\n%s\n", my_strcat(char1, char2), char1, char2);
    printf("%d\n", my_strcmp_rec(char1, char2));
    printf("%d\n", my_atoi(char3));
    struct node* node1 = (struct node *)malloc(sizeof(struct node));
    struct node* node2 = (struct node *)malloc(sizeof(struct node));
    struct node* node3 = (struct node *)malloc(sizeof(struct node));
    node1->data = 1;
    node1->next = node2;
    node2->data = 2;
    node2->next = node3;
    node3->data = 3;
    node3->next = node3;
    printf("%d", floyd(node1));

    return 0;
}