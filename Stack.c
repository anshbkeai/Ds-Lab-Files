#include<stdio.h>
#include<string.h>


int   isFull(int stack[], int top, int  n) {
	
	if(top == n-1)  return  1;
	return  0;
}
void push(int  stack[10],int val,int *top, int n ) {
	if(*top  == n-1) {
		printf("Stack is Full  Cannot  Insert More  Elemets\n");
		return ;
	}
	(*top)++;
	stack[(*top)] =  val;

}
int  pop(int stack[10],  int  *top) {
	if((*top)  ==  -1) {
		printf("Stack is  Empty");
		return ' ';
	}
	int  val  =  stack[(*top)--];
	return  val;
}
int main() {

	printf("Enter  the  size of  the   stack\n");
	int  n ;
	scanf("%d",  &n);
	int st[n];
	int  top = -1;
	int ch  = 1;
	while(ch  == 1) {
		printf("1.Push\n2.Pop\n3.Print\n");
		int c ;scanf("%d",&c);
		if(c == 1) {
			int  val ;
			printf("Input t eh   valuse  to  be pushed\n");
			scanf(" %d",&val);
			push(st,val,&top,n);
		}
		else  if(c  ==  2) {
			int  val = pop(st,&top);
			printf("Value   Poped  up is %d\n",val);
		
		}
		else  if(c  ==  3) {
			printf("| %d |<- Top \n",st[top]);
			for(int i  =  top-1 ; i >=0 ;i--) {
				
				printf("| %d |\n",st[top]);
			}
		}
		else {
			break;
		}
		printf("Do you want  to  enter  more  input(1/0)  \n");
		scanf("%d",&ch);
	}





}
