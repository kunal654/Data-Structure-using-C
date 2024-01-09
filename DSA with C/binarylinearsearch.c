#include<stdio.h>
int linearsearch(int arr[],int size,int element){
    for(int i=0;i< size;i++){
        if(arr[i]==element){
            return i;
        }
    }
    return -1;
}
int main(){
    int arr[]={1,2,3,5,15,20,22};
    int size=sizeof(arr)/sizeof(int);
    int element = 55;
    int searchIndex = linearsearch(arr,size,element);
    printf("The element %d was found at index %d \n",element,searchIndex);
    return 0;
}