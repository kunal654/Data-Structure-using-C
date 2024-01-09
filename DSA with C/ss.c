#include<stdio.h>
#include<conio.h>
#define max20
void main(){
    int max = 20;
	int top = -1;
	int bottom = -1;
	int stack [7];
	int ch,a,i,flag = 1;
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
					printf("\n enter your element");
					scanf("%d",&a);
					stack[++top]=a;
				}
				break;
			case 2:
				if(top == bottom){
					printf("stack is empty");
				}
				else{
					printf("your poping elemenet is %d :",stack[top]);
					top--;
				}
				break;
			case 3:
				printf("\n read the stack from the bottom ");
				printf(" the stack is  \n");
				for(i=0;i<=top;i++){
					printf("%d",stack[i]);
				}
			case 4:
				flag = 0;
			default:
				printf("\n you are exited");
				printf("\n press enter to start again");
		}
	}
	
}
