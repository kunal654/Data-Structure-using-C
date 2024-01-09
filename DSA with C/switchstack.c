#include<stdio.h>
#include<conio.h>
void  main(){
	int top = -1;
	int bottom = -1;
	
	int max = 7; // it mean its maximum value goes to seven .
	int stack [20]; // it  mean stack value is 20 but in this program we already declared that our max value is 7 .
	int a,ch,i,flag=1;
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
					printf("\n enter the element");
					scanf("%d",&a);
					stack[++top]=a;
				}
				break;
				case 2:
					if(top==bottom){
						printf("\n stack is empty");
					}
					else{
						printf("\n pop character is:%d",stack[top]);
						top--;
					}
				break;
				case 3:
					printf("\n read the stack from bottom");
					printf(" the stack is: ->  ");
					for(i=0;i<=top;i++){
						printf("%d \n",stack[i]);
					}
					//printf("\n");
				break;
				case 4:
					flag=0;
				default:
					printf("you have exicted \n");
					printf("start again press enter");
				
		}
	}
}
