#include<stdio.h>
typedef  struct poly {
	int  coffe;
	int  exp;
} poly;
void  accept(poly arr[],  int  n) {
	int  c,e;
	for(int i  = 0  ;i <  n  ;i++) {
		printf("Enter  the Coffectient \n");
		scanf("%d",&c);
		printf("Enter  the   Power \n");
		scanf("%d",&e);
		arr[i].coffe  =  c;
		arr[i].exp = e;
		 
	}
}
void  display(poly arr[],  int  n) {
	for(int i  = 0  ;i <  n  ;i++) {
		if(arr[i].coffe == 0 )  continue;
		printf("(%d)x^%d +",arr[i].coffe,arr[i].exp);
	}
}
void   add(poly ans[], poly p1[],poly p2[],int n,int m) {
	int i= 0 ;int j  = 0 ;  int  k  = 0;
	while( i < n &&  j < m ) {
		if(p1[i].exp  ==  p2[j].exp) {
			//printf("%dx^%d",p1[i].coffe,p1[i].exp);
			int  val  = p1[i].coffe+p2[j].coffe;
			if(val  != 0 ) {
				ans[k].coffe = val;
				ans[k].exp  =  p1[i].exp;
				k++;
			}
			i++;j++;
		}
		else  if(p1[i].exp >  p2[i].exp ) {
			ans[k]  = p1[i];
			k++;
			i++;
		}
		else {
			ans[k]=  p2[j];
			k++;
			j++;
		}
	}
	if( i  >= n ) {
		while(j <  m ) {
			ans[k]=  p2[j];
			k++;
			j++;
		}
	}
	else {
		while(i <  n ) {
			ans[k]=  p1[i];
			k++;
			i++;
		}
	}
}

void  multiply(poly ans[],poly poly1[],poly poly2[],int n, int m) {
	int  i  = 0 ; int  k = 0;
	while(i <  n ) {
		int j  = 0;
		while(j <  m ) {
			int   e  =  poly1[i].exp+poly2[j].exp;
			
			if(e  !=  0 ) {
				int   found  = 0 ;
				int prod  =  poly1[i].coffe*poly2[j].coffe;
				for(int  val  = 0 ; val<  k ;val++) {
					if(ans[val].exp ==  e) {
						ans[val].coffe+=prod;
						found =1;
						break;
					}
				}
				if(found  == 0 ) {
					ans[k].coffe=  prod;
					ans[k].exp  =  e;
					k++;
				}

			}
			j++;
		}
		i++;
	}

}

int  power(int x  ,  int  n) {
	if(n  == 0 ) return 1;
	int   s  =1;
	for(int i  = 0 ; i <  n  ;i++) s*=x;
	return s;
}
int  evaluate(poly  p1[],  int  x, int n ) {	
	int  sum  = 0 ;
	for(int i = 0 ; i < n ; i++ ) {
		int   val  =  power(x,  p1[i].exp);
		sum+=(p1[i].coffe*val);
		
	}
	return  sum;
	
	
}
int main() {
	printf("Polynomial \n");
	int n,m;
	printf("Enter  the Number of  the  term in  the  polynomail  1 \n");
	scanf("%d",&n);
	printf("Enter  the  Number  of the  terms  in  the   polynomial  2 \n");	
	scanf("%d",&m);
	poly  poly1[n];
	printf("Input  the   Polynomial 1\n");
	accept(poly1,n);

	poly poly2[m];
	printf("Input  the   Polynomial 2\n");
	accept(poly2,m);
	printf("The  Polynomial are \n");
	display(poly1,n);
	printf("\n");
	display(poly2,m);
	
	
	printf("Addition  of  the   Polynomial\n");  
	poly  ans[n+m];
	for(int i = 0 ;i < n+m ;i++) {	
		ans[i].coffe = 0;
		ans[i].exp=0;
	}
	add(ans,poly1,poly2,n,m);
	display(ans,n+m);
	printf("Going  For  the  Multiplicaton \n");
	poly  multi[n*m];
	for(int i = 0 ;i < n*m ;i++) {	
		multi[i].coffe = 0;
		multi[i].exp=0;
	}
	multiply(multi,poly1,poly2,n,m);
	display(multi,n*m);

	printf("Want  to  evalue  the   Expression \n Enter  the  value  to  eb  put on   ");
	int  x ;
	scanf("%d",&x);
	printf(" the  evalue pf  the   polynomial  1  on  x  is  %d",evaluate(poly1,x,n)); 
	
}