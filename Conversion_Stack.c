#include<stdio.h>
#include<string.h>

int   isFull(int  top, int  n) {
	return  top==n-1;
}
int isEmpty(int   top) {
	return top  == -1;
}
void   push(char  st[100],  char  val  , int *top,  int  n) {
	if(isFull(*top, n )) {
		printf("The   Stack is  Full \n");
		return ;
	}
	(*top)++;
	st[(*top)] =  val;
	
}
char   pop(char  st[100] , int   *top) {
	if(isEmpty(*top)) {
		printf("Stack is  Empty\n");
		return  '1';
	}
	char   val  = st[(*top)];
	(*top)--;
	return val;
}
int  isp(char  ch ) {
	if(ch  == '+' || ch == '-')   return  1;
	if(ch  == '*' ||  ch =='/')  return  2;
	if(ch  == '^' )  return  3;
	//if(ch  == '(')  return  5;
	return 0;
}
int  icp(char   ch) {
	if(ch  == '+' || ch == '-')   return  1;
	if(ch  == '*' ||  ch =='/')  return  2;
	if(ch  == '^' )  return  4;
	return 0;

}
int  isp1(char  ch ) {
	if(ch  == '+' || ch == '-')   return  1;
	if(ch  == '*' ||  ch =='/')  return  2;
	if(ch  == '^' )  return  4;
	//if(ch  == '(')  return  5;
	return 0;
}
int  icp1(char   ch) {
	if(ch  == '+' || ch == '-')   return  1;
	if(ch  == '*' ||  ch =='/')  return  2;
	if(ch  == '^' )  return  3;
	return 0;

}
int  isoperator(char  ch) {
return  (ch  == '+') || (ch  == '-')||(ch  == '*')||(ch  == '/')||(ch  == '^')||(ch  == '(')||(ch  == ')');

}
void  infix_postfix(char infix[100], char  postfix[100]) {
	char  st[100];  int   top =-1;
	int k  = 0;
	for(int i  = 0 ; i <  strlen(infix) ;i++) {
		if(isoperator(infix[i])) {
			if(infix[i] == '(') {
				push(st,'(', &top,100);
			}
			else if(infix[i] == ')') {
				while(!isEmpty(top ) && st[top] != '(') {
					postfix[k] =  pop(st,&top);
					k++;
				}
				char   c   =  pop(st,&top);  //  remove  the   breacket

			}
			else {
				while(!isEmpty(top)&&isp(st[top]) >=  icp(infix[i])) {
					postfix[k] =  pop(st,&top);
					k++;
				}
				push(st,infix[i],  &top,100);
			}

		}
		else {
			postfix[k]  = infix[i];
			k++;
		}
	}
	while(!isEmpty(top)) {
	postfix[k] =  pop(st,&top);
	
	k++;
	}
	postfix[k] = '\0';
	printf("The  postfix  is   %s \n " , postfix);

}


void  infix_prefix(char  infix[100] ,  char  prefix[100]) {
	char   st[100]; int  top  =-1;
	char  reverse_infix[ strlen(infix)];  int  k  = 0;
	for(int i  =  strlen(infix)-1 ;i >=0 ;i--) {
		if(infix[i] == '(') {
			reverse_infix[k] = ')';
		}
		else  if(infix[i] == ')'){	
			reverse_infix[k]  = '(';

		}
		else {
			reverse_infix[k] =  infix[i];
		}
		k++;
	}
	printf("The  reverse  infix  oid %s \n ",reverse_infix);
	  k =0;
	char  reverse_prefix[strlen(infix)];
	for(int i  = 0 ;i <  strlen(infix) ;i++) {
		if(isoperator(reverse_infix[i])) {
			if(reverse_infix[i] == '(') {
				push(st,reverse_infix[i],&top,100);
			}
			else if(reverse_infix[i]==')') {
				while(!isEmpty(top) && st[top] != '(') {
					reverse_prefix[k] = pop(st,&top);
					k++;
				}
				char  c  = pop(st,&top);
			}
			else{
				while(!isEmpty(top) &&   isp1(st[top]) >  icp1(reverse_infix[i])) {
					reverse_prefix[k] = pop(st,&top); k++;
				}
				push(st,reverse_infix[i],&top,100);
			}
		}
		else {
			reverse_prefix[k]   =  reverse_infix[i];
			k++;
		}
		
	}
	while(!isEmpty(top)) {
		reverse_prefix[k++] = pop(st,&top);
	} 
	k = 0;
	printf(" %s \n ", reverse_prefix);
	for(int i  = strlen(reverse_prefix)-1; i >=0 ;i--) {
		prefix[k] =  reverse_prefix[i];
		k++;
	}
	prefix[k]= '\0';
	
	
	
}

void   push1(char  st[][100],  char  *val  , int *top,  int  n) {
	if(isFull(*top, n )) {
		printf("The   Stack is  Full \n");
		return ;
	}
	(*top)++;
	strcpy(st[*top],val);
	
}
void pop1(char stack[][100], int *top, char *result) {
    if (isEmpty(*top)) {
        strcpy(result, "");
        return;
    }
    strcpy(result, stack[(*top)]);
    (*top)--;
}


void  postfix_infix(char postfix[100],  char infix[100]) {
	char   stack[100][100];int   top =-1;
	char temp[100] = "(";
    for (int i = 0; i < strlen(postfix); i++) {
        if (isoperator(postfix[i])) {
            char op2[100], op1[100];
            char temp1[2] = {postfix[i], '\0'};
            char ans[100] = "(";
            char close[100] = ")";

            pop1(stack, &top, op2);
            pop1(stack, &top, op1);
            strcat(op1, temp1);
            strcat(op1, op2);
            strcat(op1, close);
            strcat(ans, op1);
            strcpy(temp, ans);
            printf("%s \t %s \t %s\n", op1, temp, op2);
            push1(stack, temp, &top, 100);
        } else {
            char operand[2] = {postfix[i], '\0'};
            printf("Value gone in stack: %s\n", operand);
            push1(stack, operand, &top, 100);
        }
    }
		strcpy(infix, stack[top]);
	

}

void   postfix_prefix(char  postfix[],  char   prefix[]) {
	char st[100][100]; int   top  =-1;
	char  temp[100] ;
	for(int i  = 0 ;i <  strlen(postfix) ;i++) {
		if(isoperator(postfix[i])) {
			char op2[100];  char op1[100];
			char  oper[200]= {postfix[i], '\0'};
			pop1(st,&top,op2);
			pop1(st,&top,op1);
			
			strcat(oper,op1);
			strcat(oper,op2);		
			strcpy(temp,oper);
			printf("The  vlaue  on  the   stack  is  pushed %s \n" ,  temp);
			push1(st,temp,&top,100);
			
		}
		else{
			char  oper[2]= {postfix[i], '\0'};
			  printf("Value gone in stack: %s\n", oper);
			push1(st,oper,&top,100);
		}
	
	}
	printf("he Prefix is  %s",st[top]);

} 


void prefix_infix(char  prefix[],  char   infix[]) {
	char st[100][100]; int   top  = -1;
	char   reverse_prefix[strlen(prefix)];
	int k  = 0 ;
	for(int i  =  strlen(prefix)-1;  i>= 0 ;i--) {
		reverse_prefix[k]=  prefix[i];
		k++;
	
	}
	printf("The   reverse  Prefix  is  %s \n", reverse_prefix);
	for(int i  = 0 ; i <  strlen(reverse_prefix) ; i++) {
		char  ch  =  reverse_prefix[i];
		char   temp[100] = {'('};
		char close[2] = {')'};
		if(isoperator(ch)) {
			char  op1[100];char op2[100];
			char  oper[100] ={ch , '\0'};
			pop1(st,&top,op1);
			pop1(st,&top,op2);
			strcat(temp,op1);
			strcat(temp,oper);
			strcat(temp,op2);
			strcat(temp,close);
			printf("The  valuse   puhser  in  the   stack si %s \n",  temp);
			push1(st,temp ,  &top , 100); 

		}
		else {
			char   oper[2] = {ch,'\0'};
			push1(st,oper,&top,100);
		}

	}
	char  reverse_infix[100];
	printf("The  revrse_ infix is %s \n", st[top]);
	pop1(st,&top,reverse_infix);
	

		
}



void   push2(int  st[100],  int  val  , int *top,  int  n) {
	if(isFull(*top, n )) {
		printf("The   Stack is  Full \n");
		return ;
	}
	(*top)++;
	st[(*top)] =  val;
	
}
int pop2(int  st[100] , int   *top) {
	if(isEmpty(*top)) {
		printf("Stack is  Empty\n");
		return  '1';
	}
	int   val  = st[(*top)];
	(*top)--;
	return val;
}
int   power (int  a  ,  int b) {
	if(b  ==  0) return 1;
	return  a*(power(a,b-1));
}
int  eval(int  a   , int   b  ,  char  o) {
	if(o == '+')  return a+b;
	if(o  == '-')  return  a-b;
	if(o == '*') return  a*b;
	if(o  == '/')  return  a/b;
	if(o  == '^')  return  power(a,b);
}
int  evaluation( char postfix[]) {
	int st[100]; int  top  =-1;
	for(int i  = 0 ; i < strlen(postfix);i++) {
		if(isoperator(postfix[i])) {
			int   op2  =  pop2(st,&top);
			int   op1= pop2(st,&top);
			int  val  =  eval(op1,op2,postfix[i]);
			push2(st,val,&top,100);
			
		}
		else {
			push2(st,postfix[i]-'0',&top,100);
		}
	}
return st[top];

}
int main() {
/*
	printf("Hello  User Input  the   Infix   Expression \n");
	char  infix[100];
	scanf(" %s",infix);
	printf("The Expression  you  have Entered is  %s\n",infix);
	
	char postfix[strlen(infix)];
	infix_postfix(infix,postfix);
	printf("\n Thus  the  Postfix Expression  Obtained  is   %s  \n",postfix);
	
	char prefix[strlen(infix)];
	infix_prefix(infix, prefix );
	printf("\n Thus  the  Prefix Expression  Obtained  is  %s \n", prefix);
 */



	//to  convert  to  the  postfix   expression  
	char postfix1[100];
	scanf(" %s",postfix1);
	printf("The Expression  you  have Entered is  %s\n",postfix1);
	printf("The  Evau pf  the  Expression is %d \n",evaluation(postfix1));

	char  infix1[strlen(postfix1)];
	postfix_infix(postfix1,infix1);
	printf("\nThe  Infix   Expression  Obtained %s \n" , infix1);  

	char prefix1[strlen(postfix1)];
	postfix_prefix(postfix1,prefix1);

/*
	char prefix2[100];
	scanf(" %s",prefix2);
	printf("The Expression  you  have Entered is  %s\n",prefix2);

	char  infix2[strlen(prefix2)];
	prefix_infix(prefix2,infix2);
	printf("\nThe  Infix   Expression  Obtained %s \n" , infix2); 
	//printf("%d",'3'-'0');
*/
	
	

}
