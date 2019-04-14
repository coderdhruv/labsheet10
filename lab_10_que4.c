#include<stdio.h>
#include<stdlib.h>
void swap(int *x,int *y){
	int r = *x;
	*x = *y;
	*y = r;
}
int *makeheap(int a[],int n){
	static int heap[1000];
	int i,j;
	heap[0] = 0;
	for(i=0;i<n;i++){
		heap[i+1] = a[i];
		j=i+1;		
		while((heap[j/2]>heap[j])&&j!=1){			
			swap(&heap[j/2],&heap[j]);
			if(j/2 == 1){
				break;
			}
			j=j/2;
		}
	}	
	return heap;
}
int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	int i,j;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int *ptr = makeheap(a,n);
	int flag = 0;
	printf("heap is:\n");
	for(i=1; i<n+1; i++){
		printf("%d ",ptr[i]);
	}
	printf("\n");
	for(i=0; i<n; i++){
		if(ptr[i+1] != a[i]){
			flag=1;
			break;
		}
	}
	if(flag==1){
		printf("FALSE");
	}
	else{
		printf("TRUE");
	}
}
