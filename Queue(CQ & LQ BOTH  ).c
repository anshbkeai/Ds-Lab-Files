#include<stdio.h>
#include<string.h>

typedef struct  job {
	int  id;
	char name[20];
} job ;
 int  isFull(int n  ,  int  r){
	return  r== n-1;
}
int isEmpty(int f,  int  r) {
	return  f== r;
}
void  enqueue(job  arr[] ,int n ,  job val  , int  *f,  int  *r ) {
	if(isFull(n , *r) == 1) {
		printf("\nQueue is  Full  Cannot  able  to  add  the   elemnts \n");
		return ;
	}
	(*r)++;
	arr[(*r)] =  val;
	printf("Added %d \n",val);

}

void   addCQ(job  arr[] ,int n ,  job val  , int  *f,  int  *r) {
	if(((*r)+1) %  n ==  (*f))  {
		printf("Queue is  Full ");
		return ;
	}
	(*r) = ((*r)+1) %  n ;
	arr[(*r)] =  val;
	printf("Added \n");
	
	
}
job  deleteCQ(job  arr[], int  *f,  int *r,  int n ) {
	if((*f) == (*r)) {
		printf("Queue  is empry");
		job  j;j.id = -1;
		strcpy(j.name,"NULL");
		return j;

	}
	(*f) =  ((*f)+1)%n;
	return  arr[(*f)];

}
job  dequeue(job  arr[],  int  *f,  int  *r) {
	if(isEmpty(*f,*r)) {
		printf("Sorry Queue is  Empty\n");
		job  j;j.id = -1;
		strcpy(j.name,"NULL");
		return j;
	}
	(*f)++;
	job j   =  arr[(*f)];
	return  arr[(*f)];
	//return  j;
	
}


int  main() {
	//code   for  the   liner  Queue
	int n ;
	printf("Enter  the  number o  the   Jobs");
	scanf("%d",&n);
	struct  job queue[n];
//  This  is  the   Code  for  the  Liner  Queue
	int  f =0;
	int  r  = 0;
	char  ch  = 'y';
	while(ch  == 'y') {
		printf("1.enqueue \n 2.Dequeue \n 3.Front \n 4.Rear \n 5.Dislplay \n  Enter  the  Choice  == ");		
		int  c ;
job j1;
		scanf("%d",&c);
		switch(c) {
			case 1:
				printf("Enter  the   Details 1.Id \n 2.Name \n");
				job  j;
				scanf("%d",&j.id);
				scanf("%s",j.name);
				addCQ(queue,n,j,&f,&r);
				break;
			case  2: 	
				 j1 = deleteCQ(queue,&f,&r,n);
				printf("the   Dequeue  Object  %d  =   %s\n",j1.id,j1.name);
				
				
				break;
			case 3:
				if(isEmpty(f,r)) {
					printf("Sorry Queue is  Empty\n");
					break;
				}
				else {
					printf("the   Front Object  %d  =   %s",queue[f+1].id,queue[f+1].name);	
					break;	
				}
				
			case 4:
				printf("the   Rear  Object  %d  =   %s",queue[r].id,queue[r].name);
				break;
			case  5:
				for(int i  =  f+1; i <r+1 ; i++) {
					if(i  == f+1 ){
						printf("Front ->");
					}
					if(i  ==r ) {
						printf("Rear ->");
					}
					printf("  %d  =   %s\n",queue[i].id,queue[i].name);
				}
				break;
		
		}
		printf("y or  n \n");
		scanf(" %c" , &ch);

	}


	
	



}
