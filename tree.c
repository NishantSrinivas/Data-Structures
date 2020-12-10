//Don't insert more than 200 nodes!!
#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
typedef struct node
{
    int value;
    struct node *left;
    struct node *right;
}Node;
typedef struct queuenode
{
    Node* val;
    struct queuenode *next;
}Qnode;
int Qlength = 0;
int global = 0;
Node* root = NULL;
Node* createNode(int val)
{
    Node* temp = (Node* )malloc(sizeof(Node));
    temp->value = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
int insert(int val)
{
    Node* temp = createNode(val);
    Node* temps = root;
    if (root == NULL)
    {
        root = temp;
        return 0;
    }
    else
    {
        while (1)
        {
            if (val > temps->value)
            {
                if (temps->right == NULL)
                {
                    temps->right = temp;
                    return 0;
                }
                else
                {
                    temps = temps->right;
                }
            }
            else if (val < temps->value)
            {
                if (temps->left == NULL)
                {
                    temps->left = temp;
                    return 0;
                }
                else
                {
                    temps = temps->left;
                }
            }
            else
            {
                printf("value already present\n");
                return 0;
            }
        }
    }
}
int find(int val)
{
    Node* temps = root;
    if (root == NULL)
    {
        printf("there is no tree\n");
        return 0;
    }
    else
    {
        while (temps != NULL)
        {
            if (val == temps->value)
            {
                printf("value found\n");
                return 0;
            }
            else if (val > temps->value)
            {
                temps = temps->right;
            }
            else
            {
                temps = temps->left;
            }
        }
    }
    printf("value not present in tree!!\n");
    return 0;
}
Qnode *Qhead = NULL;
Qnode *Qtail = NULL;
Qnode *createQNode(Node* val)
{
    Qnode *temp = (Qnode *)malloc(sizeof(Qnode));
    temp->val = val;
    temp->next = NULL;
    return temp;
}
void displayQ(){
    Qnode * temp = Qhead;
    while(temp->next!=NULL){
        printf("%d ",temp->val->value);
        temp = temp->next;
    }
    printf("%d ",temp->val->value);
    printf("\n");
}
void enqueue(Node* val)
{
    Qnode *temp = createQNode(val);
    if (Qhead == NULL)
    {
        Qhead = temp;
        Qtail = Qhead;
    }
    else
    {
        Qtail->next = temp;
        Qtail = temp;
        temp->next = NULL;
    }
    Qlength++;
}
Node* dequeue()
{
    Qnode* temp = Qhead;
    if(Qhead==Qtail && Qhead!=NULL){
        temp = Qhead;
        Qhead = NULL;
        Qtail = Qhead;
    }
    else{
        Qhead = temp->next;
        temp->next = NULL;
    }
    Qlength--;
    return(temp->val);
}
void push(Node* val){
    Qnode* temp = createQNode(val);
    if(Qhead==NULL){
        Qhead = temp;
        Qtail = Qhead;
    }
    else{
        temp->next=Qhead->next;
        Qhead = temp;
    }
}
Node* pop()
{
    Qnode* temp = Qhead;
    if(Qhead==Qtail && Qhead!=NULL){
        temp = Qhead;
        Qhead = NULL;
        Qtail = Qhead;
    }
    else{
        Qhead = temp->next;
        temp->next = NULL;
    }
    Qlength--;
    return(temp->val);
}
void BFS(){
    int visited_array[200];
    int i = 0;
    enqueue(root);
    while(Qlength>0){
        Node * temp1 = dequeue();
        if(temp1!=NULL){
            visited_array[i] = temp1->value;
            i++;
            if(temp1->left!=NULL)  enqueue(temp1->left);
            if(temp1->right!=NULL) enqueue(temp1->right);
        }
        else{
            break;
        }
    }
    for(int j=0;j<i;j++){
        printf("%d ",visited_array[j]);
    }
    printf("\n");
}
void DFS_Preorder(Node* val){
    if(val == NULL){
        return;
    }
    else{
        printf("%d ",val->value);
        DFS_Preorder(val->left);
        DFS_Preorder(val->right);
    }
}
void DFS_Postorder(Node* val){
    if(val == NULL){
        return;
    }
    else{
        DFS_Postorder(val->left);
        DFS_Postorder(val->right);
        printf("%d ",val->value);
    }
}
void DFS_Inorder(Node* val){
    if(val == NULL){
        return;
    }
    else{
        DFS_Inorder(val->left);
        printf("%d ",val->value);
        DFS_Inorder(val->right);
    }
}
int main()
{
    insert(10);
    insert(6);
    insert(15);
    insert(3);
    insert(8);
    insert(20);
    BFS();
    DFS_Preorder(root);
    printf("\n");
    DFS_Inorder(root);
    printf("\n");
    DFS_Postorder(root);
    printf("\n");
    return 0;
}