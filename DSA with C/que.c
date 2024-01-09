#include<stdio.h>
#include<conio.h>
#define max 5 // declared queue to max size is 5.
main(){
	int qa[max];
	int rear = -1;
	int front = -1;
	int c,i,additem,n;
	printf("press 1 to start \n");
	scanf("%d",&n);
	while(n==1){
		printf("press 1 to insert \n");
		printf("press 2 to delete \n");
		printf("press 3 to display \n");
		printf("press 4 to exit \n");
		scanf("%d",& c);
		switch(c){
			case 1:
				if(rear == max-1){
					printf("queue overflow");
				}
				else{
					if(front == -1){
						front = 0;
					}
					printf("please enter element \n");
					scanf("%d",&additem);
					rear =rear+1;
					qa[rear] = additem;
				}
				break;
			case 2:
				if(front == -1 || front > rear){
					printf("queue underflow \n");
					return ;
				}
				else{
					printf("element deleted from queue  is : %d\n" , qa[front]);
					front = front+1;
				}
				break;
			case 3:
				if(front == -1){
					printf("empty queue \n");
				}
				else{
					printf("the queue is : \n");
					printf("read in the : \n ----> \n");
					for(i = front;i<=rear;i++){
						printf("%d \t " ,qa[i]);
						
					}
					printf("\n");
				}
			    break;
			case 4:
				n = 0;
			default : 
			          printf("you are exited \n");
			          printf("to start again press enter");
	    }
	}
}


