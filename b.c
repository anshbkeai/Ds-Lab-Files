#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef  struct   Node {
	int data;
	struct Node *left;
	struct  Node *right;

}Node;

Node*  create_node() {
	Node * newnode =(Node*)malloc(sizeof(Node));
	printf("Ente  the  data \n");
	scanf("%d",&newnode->data);
	newnode->left  =NULL;
	newnode->right  =  NULL;
	return  newnode;
}
void  create_r(Node  *root) {
	printf("Creating  Node  fro  the   Recursiove  method");
	Node *curr =  root;
	printf("Do you  want   to insert a   left  child  to  the   root %d (1 | 0) \n",curr->data);
	int  c;scanf("%d",&c) ;
	if(c == 1) {
		Node * newnode = create_node();
		curr->left   =  newnode;
		create_r(newnode);
		
	} 
	printf("Do you  want   to insert a   right  child  to  the   root %d (1 | 0) \n",curr->data);
	scanf("%d",&c) ;
	if(c == 1) {
		Node * newnode = create_node();
		curr->right   =  newnode;
		create_r(newnode);
		
	} 
	
} 

void create_nr(Node *root) {
    int ch;
    do {
        Node *curr = root;
        Node *newnode = create_node(); // Create a new node for insertion
        int flag = 0;

        while (flag == 0) {
            char c;
            printf("Enter 'l' for left child and 'r' for right child: ");
            scanf(" %c", &c);

            if (c == 'l') {
                // If left child is NULL, insert the new node here
                if (curr->left == NULL) {
                    curr->left = newnode;
                    flag = 1; // Node inserted, exit the loop
                } else {
                    curr = curr->left; // Move to the left child
                }
            } else if (c == 'r') {
                // If right child is NULL, insert the new node here
                if (curr->right == NULL) {
                    curr->right = newnode;
                    flag = 1; // Node inserted, exit the loop
                } else {
                    curr = curr->right; // Move to the right child
                }
            } else {
                printf("Invalid input. Please enter 'l' or 'r'.\n");
            }
        }

        // Ask if the user wants to insert more nodes
        printf("Do you want to insert more nodes? (1 for Yes, 0 for No): ");
        scanf("%d", &ch);
    } while (ch == 1);
}
void  preorder(Node  *root) {
	if(root  == NULL)  return;
	printf("%d  " , root->data );
	preorder(root->left);
	preorder(root->right);
}
void  inorder(Node  *root) {
	if(root  == NULL)  return;
	
	inorder(root->left);
	printf("%d  " , root->data );
	inorder(root->right);
}
int  isEmpty( int  top)  {
	return  (top ==-1);
}

Node *pop(Node *s[] , int *t) {
	if(isEmpty(*t)) {
		printf("E pty");
	}
	Node  *r  =  s[*t];
	(*t)--;
	return  r;
}
void  push(Node *root,Node *s[] ,  int *top) {
	(*top)++;
	s[*top] =  root;
	
}
void  inorder_r(Node  *root) {
	Node *st[100];
	int   top   =-1;
	Node *curr  =  root;
	while(1) {
		while(curr != NULL) {
			push(curr,st,&top);
			curr=  curr->left;
		}
		if(isEmpty(top))  break;
		curr  =  pop(st,&top);
		printf("%d " ,  curr->data);
		curr =  curr->right;
	}
}
void   postorder_r(Node *root) {
	Node* s[100];
	int t  =-1;
	Node *curr   =  root;
	while(1) {
		while(curr != NULL ) {
			push(curr,s,&t);
			curr  =  curr->left;
		}
		
		if(s[t]->right == NULL) {
			curr  =  pop(s,&t);
			printf("%d " ,  curr->data); 
		}
		while(!isEmpty(t) &&  s[t]->right  == curr) {
			curr  =  pop(s , &t);
			printf("%d " ,  curr->data);
		}
		if(isEmpty(t))  break;
		curr  =  s[t]->right;

	}
}
int   Qempty(int f  ,  int  r) {
	return  f ==r;
}
Node*  dequeue(Node  *q[] , int *f , int  *r) {
	if(Qempty(*f,*r)) {
		printf("Empty");
	}
	(*f)++;
	return  q[*f];
}
void  add(Node   *root,  Node *q[],  int  *f , int  *r) {
	//not  ot c hkec  for  the  full
	(*r)++;
	q[*r] =  root;
}

void   bfs(Node  *root) {
	Node *q[100];
	int  f  =-1;
	int  r  = -1;
	add(root,q,&f,&r);
	while(!Qempty(f,r)) {
		Node  *curr  =  dequeue(q,&f,&r);
		printf("%d  " ,  curr->data);
		if(curr->left   !=  NULL) {
			add(curr->left ,  q,  &f,&r);
		}
		if(curr->right  !=NULL) {
			add(curr->right ,  q,&f, &r);
		}
	}

}

Node *copy_r(Node  *root) {
	if(root  ==NULL)  return  root;
	Node *temp  =  (Node * )malloc(sizeof(Node));
	temp->data  = root->data;
	temp->left  =  copy_r(root->left);
	temp->right  =  copy_r(root->right);
	return  temp;

}
//fi 
Node *copy_nr(Node  *root) {
	Node   *newnode = (Node*)malloc(sizeof(Node));  
	Node *copy= newnode;
	copy->data = root->data;
	Node *s[100];
	int   t =-1;
	Node *curr =  root;
	while(1) {
		printf("  %d t =   " ,  t);	
		while(curr != NULL) {
			if(curr->left  != NULL) {
				copy->left =  (Node*)malloc(sizeof(Node));
				copy->left->data  =  curr->left->data;
			}
			if(curr->right   != NULL) {
				copy->right =  (Node*)malloc(sizeof(Node));
				copy->right->data  =  curr->right->data;
			}
			printf("\n Val  assing %d " ,  t);
			push(copy,s,&t);
			push(curr,s,&t);
			copy =  copy->left;
			curr= curr->left;
		}
		if(isEmpty(t)) {  
			break;
		}
		else {
			
			copy  = pop(s,&t);
			curr = pop(s,&t);
			printf("t =  %d", t);
			copy =  copy->right;
			curr=  curr->right;
		}
		
		 
	}
	return  newnode;
}

int  height_nr(Node *root) {
	// uising  the  post  order;
	Node* s[100];
	int   t  = -1;
	int  d= 0;
	Node *curr  =  root;
	while(1) {
		while(curr  != NULL) {
			push(curr,s,&t);
			if(d < t) {d =  t;}	
			curr =  curr->left;
		}	
		if(s[t]->right  == NULL) {
			curr  =  pop(s,&t);
			//visist
		}
		while(!isEmpty(t) &&  s[t]->right  ==  curr) {
			curr = pop(s,&t);	
		}
		if(isEmpty(t))  break;
		curr  =  s[t]->right;
	}
	return d+1;

}
int   height_r(Node  *root) {
	if(root  == NULL)  return 0;
	int  l  =  height_r(root->left);
	int  r  =  height_r(root->right);
	if(l >  r) return l+1;
	else  return  r+1;
}

void  mirror_r(Node *root) {
	if(root  == NULL)  return;
	Node *temp =  root->left;
	root->left  =  root->right;
	root->right  =  temp;
	if(root->left  !=NULL) mirror_r(root->left);
	if(root->right  !=NULL)  mirror_r(root->right);
}
void  mirror_nr(Node *root) {
	//this uses  the   bfs   traversal  to  get  to  tht  
	Node *q[100];
	int  f  =-1;int  r  = -1;
	Node *curr  =  root;
	add(curr,q,&f,&r);
	while(!Qempty(f,r)) {
		curr  =  dequeue(q,&f,&r);
		Node*  temp  =  curr->left;
		curr->left   =  curr->right  ;
		curr->right =  temp;
		if(curr->left  !=  NULL) add(curr->left,q,&f,&r);
		if(curr->right != NULL) add(curr->right,q,&f,&r);
		
	}
	

}
int  main() {
	Node *root =  create_node();
	create_r(root);
	preorder(root);
	printf("\n");
	inorder_r(root);
	printf("\n");
	postorder_r(root);
	printf("\n");
	bfs(root);
	printf("The   Cpy   r \n");
	//Node* cpy  =  copy_r(root);
	//printf("Inorder  of  the   copied ");
	//inorder_r(cpy);
	printf("\n  the  anoter recuse   copy ");
	Node *cpy  =  copy_nr(root);
	printf("\n");
	bfs(cpy);
	printf("The  height  of  the  tree is %d" ,height_r(cpy) );
	mirror_r(cpy);
	printf("\n");
	bfs(cpy);
	mirror_nr(cpy);
	printf("\n");
	bfs(cpy);

}
