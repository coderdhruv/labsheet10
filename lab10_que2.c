#include<stdio.h>
#include<stdlib.h>
int heap[100000];
void swap(int *x,int *y){
	int r = *x;
	*x = *y;
	*y = r;
}
int *makeheap(int a[],int n){	
	int i,j,k;		
	for(i=0 ; i<n ; i++){
		heap[i] = a[i];
		j=i;		
		while((heap[(j-1)/2]<heap[j])&&j!=0){			
			swap(&heap[(j-1)/2],&heap[j]);		
			if((j-1)/2 == 0){
				break;
			}
			j=(j-1)/2;
		}
	}	
	return heap;
}
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	int a[n];
	int i,j;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int *ptr = makeheap(a,n);
	int flag = 0,sum=0;
	printf("max heap is:\n");
	for(i=0; i<n; i++){
		printf("%d ",ptr[i]);
	}
	for(i=1 ;i<=k ;i++){		
		sum = sum + ptr[0];
		*ptr = *ptr/2;					
		ptr = makeheap(ptr,n);
	}
	printf("\n%d",sum);
}
