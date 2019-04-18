#include<stdio.h>
#include<stdlib.h>
void swap(int *x,int *y){
	int r = *x;
	*x = *y;
	*y = r;
}
int main(){
int a[10] = {1,2,3,4,5,6,7,8,9,10};
int i,j;
for(i=0;i<4;i++){
	for(j=i;j<10;j++){
		if(a[i]<a[j]){
			swap(&a[i],&a[j]);
		}
	}
}
for(i=0;i<4;i++){
	printf("%d ",a[i]);
}
}
