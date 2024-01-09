#include<stdio.h>
#include<conio.h>
#define max20
void main(){
	int top = -1;
	int bottom = -1;
	int stack[20];
	int max = 7;
	int a,i,ch,flag=1;
	while(flag!=0){
		printf("\n press 1 for push");
		printf("\n press 2 for pop");
		printf("\n press 3 for display");
		printf("\n press 4 for exit");
		printf("\n");
		printf("\n enter your choice");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				if(top==(max-1)){
					printf("\n stack is full");
				}
				else{
					printf("\n enter elment of stack");
					scanf("%d",&a);
					stack[++top]=a;
				}
				break;
			case 2:
				if(top==bottom){
					printf("\n stack is empty");
				}
				else{
					printf("\n your poping element is %d",stack[top]);
					top--;
				}
				break;
			case 3:
				printf("\n the stack from the bottom is:");
				for(i=0;i<=top;i++){
					printf("%d",stack[i]);
				}
					break;
			case 4:
				flag = 0;
			default:
				printf("\n you are exited");
				printf("\n press enter to start again");
		}
		
	}
}
