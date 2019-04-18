#include<stdio.h>
#include<stdlib.h>

int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	int i,j;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int cnt=0;
	for(i=0;i<n;i++){
		for(j=i;j<n;j++){
			int b[j-i+1];
			int g=0,k;
			int cnt1=0,cnt0=0;
			for(k=i;k<=j;k++){
				b[g] = a[k];
				if(b[g]==1){
					cnt1++;
				}
				else{
					cnt0++;
				}
				g++;
			}
			if(cnt1==cnt0){
				cnt++;
			}
		}
	}
	printf("count is %d",cnt);
}

