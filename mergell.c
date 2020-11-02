/*
    The program takes two liked lists and combines them in sorted order.
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node * next;
}NODE;

NODE * head1 = NULL;
NODE * head2 = NULL;
NODE * head3 = NULL;
int nodeCount = 0;

NODE * create(){
    NODE * temp = (NODE *)malloc(sizeof(NODE));
    printf("enter data\n");
    scanf("%d",&temp->data);
    temp->next = NULL;
    return temp;
}

NODE * createEmpty(){
    NODE * temp = (NODE *)malloc(sizeof(NODE));
    temp -> data = 0;
    temp -> next = NULL;
    return temp;
}

void add1(){
    printf("adding in list 1\n");
    NODE * temp = create();
    if(head1==NULL){
        head1 = temp;
    }
    else{
        NODE * t = head1;
        while(t->next!=NULL){
            t = t->next;
        }
        t->next = temp;
        temp = NULL;
        free(temp); 
    }
}

void add2(){
    printf("adding in list 2\n");
    NODE * temp = create();
    if(head2==NULL){
        head2 = temp;
    }
    else{
       NODE * t = head2;
        while(t->next!=NULL){
            t = t->next;
        }
        t->next = temp;
        temp = NULL;
        free(temp);
    }
}

void sort(){
    if(head3 == NULL || nodeCount == 0){
        printf("nothing to sort\n");
        return;
    }
    NODE * p = head3;
    NODE * q = NULL;
    NODE * min = NULL;
    int temp;
    for(int i=0;i<nodeCount;i++){
       min = q = p;
       for(int j=i;j<nodeCount;j++){
           if(q->data < min->data){
               min = q;
           }
           q = q->next;
       }
       temp = min->data;
       min->data = p->data;
       p->data = temp;
       p = p->next;
    }
}

void nodeCounts(){
    NODE * temp = head3;
    while(temp->next!=NULL){
        temp = temp->next;
        ++nodeCount;
    }
    ++nodeCount;
}
void displays(){
    NODE * temp = head3;
    if(head3==NULL || nodeCount==0){
        printf("no data to print\n");
        return;
    }
    printf("data :\n");
    while(temp->next!=NULL){
        printf("%d \n",temp->data);
        temp = temp->next;
    }
    printf("%d \n",temp->data);
    printf("no of nodes = %d\n",nodeCount);
}

void merge(){
    head3 = head1;
    NODE * temp = head3;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = head2;
    temp = NULL;
    free(temp);
    nodeCounts();
    displays();
}

void main(){
    int a,b;
    printf("enter the number of nodes for lists 1 and 2\n");
    scanf("%d%d",&a,&b);
    for(int i=0;i<a;++i){
        add1();
    }
    for(int j=0;j<b;++j){
        add2();
    }
    merge();
    //displays();
    sort();
    displays();
}