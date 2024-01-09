#include<stdio.h>
#include<conio.h>
#define size 5
int iteam[size];
int front = -1;
int rear = -1;
int (isfull()){
	if((front==rear+1)||(front==0&&rear==size-1)){
		return 1;
	}
	return 0;
}
int (isempty()){
	if(front==-1){
		return 1;
	}
	return 0;
}
int enqueue(int value){
	if(isfull()){
		printf("\n sorry the queue is full");
	}
	else{
		if(front==-1){
			front = 0;
		}
		rear=(rear+1)%size;
		iteam[rear]=value;
		printf(" inserted  %d \n" ,value);
	}
	return 0;
}
int dequeue(){
	int value;
	if(isempty()){
		printf("\n The queue is empty");
		return -1;
	}
	else{
		value=iteam[front];
		if(front==rear){
			(front = -1);
			rear = -1;
		}
		else{
			(front=(front+1))%size;
		}
		printf("\n deleted element %d \n",value);
		return value;
	}
}
void display(){
	int i;
	if(isempty()){
		printf("\n empty queue \n");
	}
	else{
		printf("front %d",front);
		printf("iteam :");
		for(i=front;i!=rear;i=(i+1)%size){
			printf(" %d " , iteam [i] );
		}
			printf(" %d " , iteam [i] );
			printf("rear=%d", rear);
	}
}
void main(){
//	int iteam[size];
//	int rear = -1;
//	int front = -1;
	int n,c,value;
	printf("press 1 to start \n");
	scanf("%d",& n);
	while(n==1){
		printf("\n press 1 to insert \n");
		printf("press 2 to delete \n");
		printf("press 3 to display \n");
		printf("press 4 to exit \n");
		scanf("%d",& c);
		switch(c){
			case 1:
				printf("enter your element ");
				scanf("%d",& value);
			     enqueue(value);
			break;
			case 2:
				value = dequeue();
				if(value!=-1)
				{
					printf("dequeue element is : ");
				}
					break;
			case 3:
			display();
			break;
//			case 4:
//			return 0;
			default:
			printf("you are exited");
			printf("press enter to start");
			}
		}
	}
