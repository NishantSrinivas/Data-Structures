#include<stdio.h>
void insert(int arr[],int len){
   int temp;
   for(int i=1;i<len;i++){
       if(arr[i]<arr[i-1]){
           temp=arr[i];
           while(i>0 && arr[i-1]>temp){
               arr[i] = arr[i-1];
               i--;
           }
           arr[i] = temp;
       }
   }
}
void bubble(int arr[],int len){
    int temp;
    for(int i=0;i<len-1;i++){
        for(int j=i+1;j<len;j++){
            if(arr[j]<arr[i]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void select(int arr[],int len){
    int temp;
    int val = arr[0];
    int pos = 0;
    for(int i=0;i<len;i++){
        pos = i;
        for(int j=i+1;j<len;j++){
            if(arr[j]<arr[pos]){
                pos = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[pos];
        arr[pos] = temp;
    }
}
void main(){
    int a[9] = {1,2,13,9,16,4,11,25,14};
    //select(a,9);
    //insert(a,9);
    //bubble(a,9);
    for(int i=0;i<9;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}