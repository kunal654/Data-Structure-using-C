#include<stdio.h>
#include<conio.h>
#define max 5
main(){
	int qa[max];
	int rear = -1;
	int front = -1;
	int ch,a,i,n;
	printf("\n Press 1 to start");
	scanf("%d",&n);
	while(n==1){
		printf("\n Press 1 to insert");
		printf("\n Press 2 to delete");
		printf("\n Press 3 to display");
		printf("\n Press 4 to exit");
		printf("\n ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				if(rear==(max-1)){
					printf("stack is full");
				}
				else{
					if(front == -1){
						front = 0;
					}
					printf("\n enter the elment of queue");
					scanf("%d",&a);
					rear=rear+1;
					qa[rear]=a;
				}
				break;
			case 2:
				if(front = -1 || front > rear){
					printf("stack is empty");
					}
					else{
						printf("\n element deleting is %d",qa[front]);
						front = front+1;
					}
				break;
			case 3:
				printf("\n queue from the bottom is:");
				for(i=front;i<=rear;i++){
					printf("%d \t",qa[i]);
				}0
				break;
			case 4:
				n = 0;
			default:
				printf("\n you are exited");
				printf("\n press enter to start again");
					
				
		}
	}
}
