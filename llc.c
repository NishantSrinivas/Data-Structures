/* 
    METHODS AVAILABLE 
        1. create -> creates a new node, populates it and returns its address.
        2. createEmpty -> creates a new node and returns its address.
        3. addFront -> adds a new node at the beginning.
        4. addLast -> adds a new node at the end.
        5. insert -> inserts a new node at any given position (takes position as argument).
        6. removenode -> removes any given node (takes position as argument).
        7. display -> prints the contents of the list.
        8. reverse -> reverses the linked list.
        9. sort -> sorts the linked list in ascending order.
        10. main -> driver function.
    struct node has been typedefed into NODE.
    pointer head -> points to the first element of the linked list.
    int nodeCount -> used to keep track of the #of nodes in list.
*/
#include<stdio.h>
#include<stdlib.h>
//to create the stucture of the node.
typedef struct node{
    int data;
    struct node * next;
}NODE; //use NODE instead of stuct node.
NODE * head = NULL; //head pointer, points to the first node in linked list.
int nodeCount = 0; //keeps track of #nodes in linked list.

//creates a new node and populates it with value and returns it address.
NODE * create(){
    NODE * new = (NODE *)malloc(sizeof(NODE));
    printf("enter data\n");
    scanf("%d",&new->data);
    new->next = NULL;
    return new;
}
NODE * createEmpty(){
    NODE * temp = (NODE *)malloc(sizeof(NODE));
    return temp;
}

//adds new node to the front of the list.
void addFront(){
    NODE * temp = create();
    if(head==NULL){
        head = temp;
    }
    else{
        temp->next = head;
        head = temp;
    }
    temp = NULL;
    free(temp);
    ++nodeCount;
}

//adds new node at the end.
void addLast(){
    NODE * temp = create();
    if(head == NULL){
        head = temp;
    }
    else{
        NODE * t = head;
        while(t->next!=NULL){
            t = t->next;
        }
        t->next = temp;
    }
    temp = NULL;
    free(temp);
    ++nodeCount;
}

//inserts at any arbitrary point in the middle.
void insert(int val){
    if(val<=0){
        addFront();
        return;
    }
    else if(val>nodeCount){
        addLast();
        return;
    }
    NODE * temp = create();
    if(head == NULL){
        head = temp;
    }
    else{
        NODE * t = head;
        int x = 1;
        while(x<val && t->next!=NULL){
            t = t->next;
            x++;
        }
        temp->next = t->next;
        t->next = temp;
    }
    temp = NULL;
    free(temp);
    ++nodeCount;
}

//prints the contents of the linked list.
void display(){
    NODE * temp = head;
    if(head==NULL || nodeCount==0){
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

//removes any arbitrary node from the list.
void removenode(int val){
    NODE * temp = head;
    NODE * prev = NULL;
    if(head==NULL){
        printf("Nothing to remove");
    }
    else{
        if(nodeCount==1){
            head = NULL;
        }
        else{
            int x = 1;
            while(x<val && temp->next!=NULL){
                prev = temp;
                temp = temp->next;
                x++;
            }
            prev->next = temp->next;
            temp = NULL;
            free(temp);
        }
    }
    --nodeCount;
}

//reverses the linked list.
void reverse(){
    NODE * temp = head->next;
    NODE * last = head;
    NODE * first = head;
    if(nodeCount == 1 || nodeCount == 0){
        printf("linked list cannot be reversed");
        return;
    }
    while(last->next!=NULL){ //last will point to the last node.
        last = last->next;
    }
    while(temp!=last){
        NODE * temp1 = createEmpty();
        temp1->data = temp->data;
        temp1->next = head;
        head = temp1;
        temp = temp->next;
    }
    NODE * fi = createEmpty();
    fi->data = last->data;
    fi->next = head;
    head = fi;
    first -> next = NULL;
}

//sorts the list using selection sort.
void sort(){
    if(head == NULL || nodeCount == 0){
        printf("nothing to sort\n");
        return;
    }
    NODE * p = head;
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

/*
//creates a new Linked list.
NODE * createLL(){
    NODE * head = NULL;
    return head;
}
*/

//main function
void main(){
    printf("Welcome to the linked list program\n what would you like to do?\n");
    printf("1. insert node at beginning\n");
    printf("2. insert node at the end\n");
    printf("3. insert node in some arbitrary position\n");
    printf("4. sort the linked list\n");
    printf("5. reverse the linked list\n");
    printf("6. remove arbitrary node\n");
    int val,c;
    scanf("%d",&val);
    switch(val){
        case 1:
            printf("How many node would you like to add?\n");
            scanf("%d",&c);
            for(int i=0;i<c;++i){
                addFront();
            }
            //sort();
            display();
            break;
        case 2:
            printf("How many node would you like to add?\n");
            scanf("%d",&c);
            for(int i=0;i<c;++i){
                addLast();
            }
            display();
            break;
        case 3:
            printf("where would you like to insert?\n");
            scanf("%d",&c);
            insert(c);
            display();
            break;
        case 4:
            sort();
            display();
            break;
        case 5:
            reverse();
            display();
            break;
        case 6:
            printf("which node would you like to remove?\n");
            scanf("%d",&c);
            removenode(c);
            display();
            break;
        default:
            printf("please enter valid value\n");
    }
}