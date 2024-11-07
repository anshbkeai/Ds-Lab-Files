#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef  struct student {
	char  dep[20];
	char  name[20];
	int  year;
	int  roll;
} student;

typedef struct Node {
	struct student st;
	struct Node *next;
}Node;
void add(Node *head, student  s) {
	Node *newnode  =  (Node *)malloc(sizeof(Node));
	newnode->st  =  s;
	newnode->next  =NULL;
	if(head  ==  NULL) {
		head =  newnode;
		return ;
	}
	Node  *curr  =  head;
	while(curr->next != NULL) {
		curr=  curr->next;
	}
	curr->next =  newnode;
	
}



void  display(Node *head) {
	if(head  == NULL) {
		printf("Empty Linked List \n");
		return; 
	}
	Node *curr  =  head;
	while(curr  != NULL){
		printf(" %s %d \n" ,curr->st.name,curr->st.year);
		printf("\t | \t\n");
		printf("\t V \t\n");
		curr=  curr->next;
	}
}

student  delete(Node *head,int y) {
	student s;
	if(head  == NULL) {

		printf("Empty Linked List");
		
		strcpy(s.name,"EMpty");s.year  = -1;
		return  s;
	}
	if(head->st.year == y)  {
		student   st  =  head->st;
		head  =  head->next;
		return  st;
	}

	Node  *curr  =  head;
	while(curr->next  !=  NULL) {
		if(curr->next->st.year == y ) {
			s=  curr->next->st;	
			Node *temp   = curr->next;
			curr->next  =  curr->next->next;
			free(temp);
			return  s;
		}
	}
	return  s;
}

Node *middle_n(Node *head) {
	Node  *slow = head;
	Node  *fast  =  head->next;
	while(fast  !=NULL && fast->next  !=NULL) {
		slow  =  slow->next;
		fast  =  fast->next->next;
	}
	return slow;
}

Node* merge_Linked(Node* node1, Node* node2) {
    // Assuming the Given Linked List are to be sorted Order
    // edge case can be if any one is null

    Node* curr1 = node1;
    Node* curr2 = node2;

    Node* newnode = (Node*)malloc(sizeof(Node));
    Node* curr = newnode;

    if (curr1->st.year > curr2->st.year) {
        curr->st = curr2->st;
        curr2 = curr2->next;
    } else {
        curr->st = curr1->st;
        curr1 = curr1->next;
    }

    curr->next = NULL;

    Node* temp = (Node*)malloc(sizeof(Node));
    temp->next = NULL;

    while (curr1 != NULL && curr2 != NULL) {
        if (curr1->st.year > curr2->st.year) {
            curr->next = curr2;
            curr2 = curr2->next;
        } else {
            curr->next = curr1;
            curr1 = curr1->next;
        }
        curr = curr->next;
    }

    if (curr1 == NULL) {
        while (curr2 != NULL) {
            curr->next = curr2;
            curr2 = curr2->next;
            curr = curr->next;
        }
    } else {
        while (curr1 != NULL) {
            curr->next = curr1;
            curr1 = curr1->next;
            curr = curr->next;
        }
    }

    return newnode;
}
Node*  sort(Node *head) {
	if(head  == NULL  ||  head->next  == NULL )  return  head;
	
	Node *middle  =  middle_n(head);
	Node  *right  =  middle->next;
	middle->next  = NULL;
	Node *left  =  head;
	left =  sort(left);
	right =sort(right);
	
	return  merge_Linked(left,right);

}

int main() {	
	Node  *head  =  (Node *)malloc(sizeof(Node));
		student  s;
		scanf("%s",s.name);
		s.year =  100;
	head->st  =  s;
	head->next  = NULL;
	for(int i  =  0 ; i < 6 ; i++)  {
		
		scanf("%s",s.name);
		s.year =  10-i;
		add(head,s);
	}
	display(head);
	delete(head ,  0);
	display(head);
	sort(head);
	display(head);

}