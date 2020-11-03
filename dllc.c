#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node * next;
    struct node * prev;
}NODE;

NODE * head = NULL;
int nodeCount = 0;

NODE * create(){
    NODE * temp = (NODE *)malloc(sizeof(NODE));
    printf("enter node data\n");
    scanf("%d",&temp->data);
    temp -> next = NULL;
    temp -> prev = NULL;
    return temp;
}

void addFirst(){
    NODE * temp = create();
    if(head == NULL){
        head = temp;
        temp->prev = NULL;
        temp->next = NULL;
    }
    else{
       head->prev = temp;
       temp->next = head;
       temp->prev = NULL;
       head = temp;
    }
    temp = NULL;
    free(temp);
    nodeCount++; 
}

void addLast(){
    NODE * temp = create();
    if(head == NULL){
        head = temp;
        temp->next = NULL;
        temp->prev = NULL;
    }
    else{
        NODE * tmp = head;
        while(tmp->next!=NULL){
            tmp = tmp->next;
        }
        tmp->next = temp;
        temp->prev = tmp;
        temp->next = NULL;
    }
    temp = NULL;
    free(temp);
    nodeCount++;
}

void insert(){
    NODE * temp = create();
    if(head == NULL || temp->data < head->data){
        if(head!=NULL){
            temp->next = head;
            temp->prev = NULL;
            head->prev = temp;
            head = temp;
        }
        else{
            head = temp;
            temp->next = NULL;
            temp->prev = NULL;
        }
    }
    else
    {
        NODE * tmp = head;
        while(tmp->data < temp->data && tmp->next!=NULL){
            tmp = tmp->next;
        }
        if(tmp->next==NULL && temp->data > tmp->data){
            tmp->next = temp;
            temp->prev = tmp;
            temp->next = NULL;
        }
        else{
            tmp = tmp->prev;
            temp->next = tmp->next;
            tmp->next->prev = temp;
            temp->prev = tmp;
            tmp->next = temp;
        } 
    }
    temp = NULL;
    free(temp);
    nodeCount++;
}

void removes(int x){
    if(head == NULL){
        printf("nothing to remove\n");
        return;
    }
    else if(nodeCount == 1){
        head = NULL;
    }
    else if(x <= 0){
        NODE * temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
    }
    else if(x >= nodeCount){
        NODE * tmp = head;
        while(tmp->next!=NULL){
            tmp = tmp->next;
        }
        tmp->prev->next = NULL;
        free(tmp);
    }
    else{
        int pos = 1;
        NODE * tmp = head;
        while(pos<x){
            pos++;
            tmp = tmp->next;
        }
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
        free(tmp);
    }
    nodeCount--;
}

void display(){
    if(nodeCount==0){
        printf("list empty\n");
        return;
    }
    printf("the data is:\n");
    NODE * temp = head;
    while(temp->next!=NULL){
        printf("%d\n",temp->data);
        temp = temp->next;
    }
    printf("%d\n",temp->data);
    printf("the no: of nodes is %d\n",nodeCount);
}

void main(){
    int n;
    printf("Hello, Welcome to the doubly linked list\n");
    printf("what would you like to do?\n");
    printf("1. Add First\n");
    printf("2. Add Last\n");
    printf("3. Insert\n");
    printf("4. remove\n");
    printf("5. display\n");
    printf("6. exit\n");
    do{
        int c;
        scanf("%d",&n);
        switch (n)
        {
        case 1:
            printf("how many nodes would you like to add?\n");
            scanf("%d",&c);
            for(int i=0;i<c;i++){
                addFirst();
            }
            printf("what would you like to do next?\n");
            break;
        case 2:
            printf("how many nodes would you like to add?\n");
            scanf("%d",&c);
            for(int i=0;i<c;i++){
                addLast();
            }
            printf("what would you like to do next?\n");
            break;
        case 3:
            insert();
            printf("what would you like to do next?\n");
            break;
        case 4:
            if(nodeCount == 0){
                printf("nothing to remove\n");
                printf("what would you like to do next?\n");
                break;
            }
            printf("which node would you like to remove?\n");
            scanf("%d",&c);
            removes(c);
            printf("what would you like to do next?\n");
            break;
        case 5:
            display();
            printf("what would you like to do next?\n");
            break;
        default:
            if(n!=6){
                printf("%d not valid option, enter valid option\n",n);
                continue;
            }
        }
    }
    while(n!=6);
}