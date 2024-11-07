#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Node {
	char  w[10];
	char m[10];
	struct  Node *left;
	struct Node *right;
}Node ;
Node* create_node() {
	Node* newnode =  (Node*)malloc(sizeof(Node));
	printf("Enther  the   word \n");scanf(" %s", newnode->w);
	printf("Enter  the  meaning  \n");scanf(" %s",newnode->m);
	newnode->left  = NULL;
	newnode->right =  NULL;
	return newnode;
}
void  create_nr(Node   *root) {
	
	int   c  =1;
	do {
		Node *curr  = root;
		Node *newnode =  create_node();
		int  f = 0;
		while( f == 0 ) {
			if(strcmp(curr->w,newnode->w) > 0) {
				if(curr->left  == NULL) {
					curr->left  =  newnode;
					f= 1;
				}
				curr =  curr->left;
			}
			else  {
				if(curr->right  == NULL) {
					curr->right    =newnode;
					f =1;
				}
				curr=  curr->right;
			}
		}
		printf("want  to  enter  more  Node  ( 1 | 0 ) \n");
		scanf("%d" ,  &c);

	}while(c ==1);
}
int  isEmpty(int   t) {
	return t == -1;
}
Node *pop(Node *s[],  int   *t) {
	if(isEmpty(*t)) {printf("EMpty stack");}
	Node *r  =  s[*t];
	(*t)--;
	return  r;

} 
void  push(Node *root ,  Node* s[] ,  int  *t) {
	(*t)++;
	s[*t] =  root;
}
void inorder_nr(Node  *root) {
	Node *s[100];
	int  t =-1;
	Node *curr  =  root;
	while(1) {
		while(curr   != NULL) {
			push(curr,  s , &t);		
			curr  =  curr->left;
		}
		if(isEmpty(t))  break;
		curr  = pop(s,&t);
		printf("%s = %s  ",  curr->w , curr->m);
		curr  =  curr->right;
	}
}
int  search_r(Node  *root,  char wo[10]){
	if(root  == NULL)  return  0;
	if(strcmp(root->w,wo) == 0  ) {
		return 1;
	}  
	else if(strcmp(root->w , wo) > 0 ) {
		return search_r(root->left,  wo);
	}
	else {
		return search_r(root->right,  wo);
	}
}
int  search_nr(Node *root) {
	char wo[10];
	scanf(" %s" ,  wo);
	int  f =0;
	Node *curr  =  root;
	while(curr  != NULL &&   f == 0 ) {
		if(strcmp(curr->w,  wo) == 0  ) {
			f =1;
			return f;
		}
		else if(strcmp(curr->w, wo ) > 0) {
			curr =  curr->left;
		}	
		else {
			curr=  curr->right;
		}
	}
	return  f;

}
void   delete(Node  *root  ) {
	char   w[10];
	scanf(" %s",w);
	Node *parent = NULL;
	Node *curr  =  root;
	while(curr != NULL  &&  strcmp(curr->w,w) != 0) {
		parent   = curr;
		if(strcmp(curr->w,w) > 0) {
			curr  =  curr->left;
		}
		else {
			curr  =  curr->right;
		}
	} 
	if(curr  ==  NULL) {
		printf("Not  found  \n");
		return ;
	}
	
	if(curr->left == NULL   && curr->right == NULL) {
		printf("Leaf   Node \n");
		if(parent->left  == curr) parent->left  =NULL;
		else  parent->right = NULL;
		free(curr);
	}
	else if(curr->left  ==NULL  && curr->right  != NULL) {
		printf("Node  witj  right  child \n");
		if(parent->left == curr) {
			parent->left  =  curr->right;
			free(curr);
		}
		else  {
			parent->right  =  curr->right;
			free(curr);
		}
	}
	else  if(curr->left   != NULL  && curr->right  ==  NULL) {
		printf("Node  with  Both  child \n");
		if(parent->left == curr) {
			parent->left  =  curr->left;

			curr->left  =NULL;
			curr->right  = NULL;
			free(curr);
		}
		else  {
			parent->right  =  curr->left;
			curr->left  =NULL;
			curr->right  = NULL;
			free(curr);
		}
	}
	else {
		printf("Two  Childs \n");
		Node  *succ   = curr->right;
		while(succ->left  !=  NULL) {
			succ =  succ->left;
		}
		succ->left  =  curr->left;
		if(parent->left == curr) {
			parent->left  =  curr->right;
			curr->left  =NULL;
			curr->right  = NULL;
			free(curr);
		}
		else  {
			parent->right  =  curr->right;
			curr->left  =NULL;
			curr->right  = NULL;
			free(curr);
		}
	
		
		
	}
}
int  main() {
	Node *root  =  create_node();
	create_nr(root);
	inorder_nr(root);
	printf("%d " , search_nr(root));
	delete(root);
	inorder_nr(root);
	

}
