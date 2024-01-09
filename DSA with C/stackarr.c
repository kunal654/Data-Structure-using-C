#include<stdio.h>
#include<stdlib.h>
#define max 10
int count = 0;
struct stack{
	int items[max];
	int top;
};

typedef struct stack st;

void createemptystack(st *s){
	s->top=-1;
}

int isfull(st *s){
		if(s->top==max-1){
		return 1;
	}
	else{
	return 0;
}
}

	int isempty(st *s){
		if(s->top==-1){
		return 1;
	}
		else{
		return 0;
	
}
}


void push(st *s,int newitem){
	if (isfull(s)){
		printf("stackfull");
	}
	else{
		s->top++;
		s->items[s->top]=newitem;
	}
	count++;
}

void pop(st *s){
	if (isempty(s)){
		printf("stack is empty");
	}
	else{
		printf("item pop=%d",s->items[s->top]);
		s->top--;
	}
	count--;
	printf("\n");
	}
	//printing the element of stack
	void printstack(st *s){
		printf("stack");
		for(int i=0;i<count;i++){
			printf("%d",s->items[i]);
		}
		printf("\n");
	}
	
	int main(){
		int ch,n;
		st *s=(st *)malloc(sizeof(st));
		createemptystack(s);
		printf("enter the value of stack ");
		for(int i = 0;i<4;i++){
			scanf("%d",&items[n]);
			push(s,n);
		}
//		push(s,1);
//		push(s,2);
//		push(s,3);
//		push(s,4);
		printstack(s);
		pop(s);
		printf("after poping out");
		printstack(s);
		
	}
	
