//code  For  the   sparse Matix
#include<stdio.h>
#include<string.h>


int   accept(int  matrix[][20], int m, int n ) {
	int   c= 0;
	for(int i  = 0; i < m  ; i++) {
		for(int j = 0 ; j  < n  ; j++) {
			printf("Enter  the   Element  for  the   row  %d and  column  %d ",i,j);
			scanf("%d",&matrix[i][j]);
			if(matrix[i][j] != 0 )   c++;
			printf("\n");
		}
	
	}
	return  c;
}

void   display_original(int  matrix[][20], int m, int n) {
		for(int i  = 0; i < m  ; i++) {
		for(int j = 0 ; j  < n  ; j++) {
			printf("%d | ",matrix[i][j]);
		}
		printf("\n");
	
	} 
}

void  convert_to_sparse(int  matrix[][20] ,  int  sparse[][3],  int m ,  int  n ) {
	int   t =1;
   	for(int i  = 0 ;i <m   ;i++) {
		for(int j  = 0 ;j  < n  ;j++) {
			if(matrix[i][j] != 0 ) {
				sparse[t][0] =  i;
				sparse[t][1] = j;
				sparse[t][2]  = matrix[i][j];
				t++;
			}
		
		}
	}

}

void  display_sparse(int  sparse[][3],  int t) {
	
	for(int i  = 0 ; i  <  t+1;i++) {
		
		printf("%d\t%d\t%d|\n",sparse[i][0],sparse[i][1],sparse[i][2]);
		
	}
}

void  simple_transpose(int  sparse[][3] ,  int  simple[][3]) {
	simple[0][0]  =  sparse[0][1];
	simple[0][1]  =  sparse[0][0];
	int  t     =  sparse[0][2];
	simple[0][2]  =  t;
	int  col  =  sparse[0][1];
	int  idx = 1;
	for(int  i  = 0 ; i <  col; i++) {
		for(int  j  = 1 ;j <= t;j++) {
			if(sparse[j][1] == i){
				simple[idx][0] = sparse[j][1];simple[idx][1]=  sparse[j][0];simple[idx][2]=  sparse[j][2];
				idx++;
			}
		}  
	}
}

void   fast_transpose(int  sparse[][3],  int   fast[][3]) {
	fast[0][0]  =  sparse[0][1];
	fast[0][1]  =  sparse[0][0];
	int  t     =  sparse[0][2];
	int   col  =  sparse[0][1];
	fast[0][2]  =  t;
	int  idx_count[col];int freq_count[col];
	for(int  i  = 0 ; i <  col ;i++) freq_count[i] = 0;
	for(int  i =1  ;i <=t;i++) freq_count[sparse[i][1]]++;
	idx_count[0] = 1 ;
	for(int i  =  1; i  <  col  ;i++) {
		idx_count[i] =  freq_count[i-1]+idx_count[i-1];
	}
	for(int  i = 1 ;i <=t;i++) {
		int c =  sparse[i][1];
		fast[idx_count[c]][0] =  c;
		fast[idx_count[c]][1] =  sparse[i][0];
		fast[idx_count[c]][2] =  sparse[i][2];
		idx_count[c]++;
	}
}
int  main() {
	
	//Input  of  the  Normal  matrix;
	int m , n;
	printf("Enter  the  No  of  the  Rows  and  the Column \n");
	scanf("%d",&m);
	printf("No  of  Column\n");
	scanf("%d",&n);
	int  matrix[m][n];
	int  t  =accept(matrix,m,n);
	printf("The   ORiginal  Matrix  is  \n");
	display_original(matrix,m,n);

	printf("SO THE   COPACT   FORM  OF  THE  MATRIX IS  \n");
	int sparse[50][3];
	sparse[0][0]  = m;sparse[0][1] = n ;sparse[0][2] =  t;
	convert_to_sparse(matrix,sparse,m,n);
	display_sparse(sparse,t);

	int  simple[50][3];
	simple_transpose(sparse,simple);
	printf("The  simple  Transpose  s  \n") ;
	display_sparse(simple,t);
	
	int fast[50][3];
	fast_transpose(sparse,fast);
	printf("\nThe  Fast  Transpose  s  \n") ;
	display_sparse(fast,t);

/*
Additoion is  good  we   can   do  tha t by  using he ploynomial and   we  can  answeer  that

*/



} 
