#include<stdio.h>
#include<conio.h>
void main(){
	int max=7;
	int top=-1;
	int bottom=-1;
	int stack[20];
	int i,n,ch,flag=1;
	while(flag!=0){
	printf("Press 1 for Push");
	printf("\nPress 2 for pop \n");
	printf("press 3 for display \n");
	printf("press 4 for exit \n");
	printf("Enter your choice \n");
	printf("\n");
	scanf("%d",&ch);
	switch(ch){
		case 1:
			if(top==(max-1)){
				printf("Stack is full \n");
			}
			else{
				printf("enter the element for the stack = ");
				scanf("%d",&n);
				stack[++top]=n;
			}
		    break;
		case 2 :
			if(top==-1){
				printf("staack is empty \n");
			}
			else{
				printf("your poping element is %d \n",stack[top]);
				top--;
			}
			break;
		case 3:
			printf("Elemenets of the stack are : ");
			for(i=0;i<=top;i++){
				printf("%d ", stack[i]);
			}
			break;
		case 4:
			flag=0;
			break;
		default:
			printf("You have exited successfully");
	}
  }
}
