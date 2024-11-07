#include<stdio.h>
#include<string.h>

struct st {
	int prn;
	char name[20];
	float marks;	
};
//shell sort 
// going   for the   bubble  sort

void   bubble_sort(struct st arr[],int n) {
	
	//we  have   to  make the   element   to  the  last  
	for(int  i  = 0 ;i < n  ;i++) {
		for(int  j  = 0;j<n-i-1;j++) {
			if(arr[j].prn >  arr[j+1].prn) {
				//call  for the swap
				struct  st temp  = arr[j];
				arr[j]  =  arr[j+1];
				arr[j+1]  =  temp;
				//swap(&arr[j],&arr[j+1]);
			}
		}
	}
}


void  insert_sort(struct  st arr[],int n) {
	/*
	It takes the  sammlest   indexcx   to the firsty
	[5,4,8,1,2]
	*/
	for(int i  =  0 ;i<  n  ;i++) {
		struct  st store  =  arr[i];
		int  j   =  i-1;
		while(j >=0 &&   arr[j].prn >  store.prn)  {
			//shift and  replace 
			arr[j+1] =  arr[j];
			//arr[j]  =  store;
			j--;
		}
		arr[j+1] =  store;
		
	}

}

void selection(struct st  arr[],int n) {
	for(int i  = 0 ;i < n;i++) {
		int   min  = i;
		for(int j = i+1 ;j < n ;j++) {
			if(arr[j].prn  <  arr[min].prn) {
			//update   the   min  to the  
				min  = j ;
			}
		}
		//swap  that   e   got
		struct st  temp  =  arr[i];
		arr[i]  =  arr[min];
		arr[min]=  temp;
	}

}

void   shell_sort(struct  st arr[],  int n ) {
	int  gap   =    (n >>  1) ; int  swap;
	while(gap >0 ) {
		
		do {
         swap  = 0;
			for(int i  =0 ;i < n -  gap ;i++) {
				if(arr[i].prn >  arr[i+gap].prn) {
					struct  st   temp  =  arr[i];
					arr[i]=  arr[i+gap];
					arr[i+gap] =  temp;
					swap = 1;	
				}
			}
		}while(swap == 1) ;
		gap/=2;
	}


}

void  accept(struct st arr[],int n) {
	for(int i  = 0 ; i < n  ;i++)  {
		printf("PRN :");
		scanf("%d",&arr[i].prn);
		printf(" Name  :");
		scanf("%s",arr[i].name);
		printf("Marks :");
		scanf("%f",&arr[i].marks);
	}

}
void display(struct  st arr[],  int  n) {
	printf("PRN\tNAME\tMARKs\n");
	for(int  i  = 0 ; i <  n; i++) {
		printf("%d %s %f \n",arr[i].prn,arr[i].name,arr[i].marks);
	}
}
int main() {
	//code  for the  bubble sorti
	int n ;
	printf("input n :) ");
	scanf("%d",&n);
	printf("\n");
	
	struct st  arr[n];
	accept(arr,n);
	 printf("SELECT THE SORTING ALGO \n 1. BUBBLE SORT \n 2. SELECTION SORT \n 3. INSERTION SORT \n 4. SHELL SORT\n");
    int cho;
    scanf("%d", &cho);

    switch (cho) {
        case 1:
            bubble_sort(arr, n);
            break;
        case 2:
            selection(arr, n);
            break;
        case 3:
            insert_sort(arr, n);
            break;
        case 4:
            shell_sort(arr, n);
            break;
        default:
            printf("Invalid Choice\n");
            return 1;
    }

    display(arr, n);
    scanf("%d",&cho);
    return 0;

}
