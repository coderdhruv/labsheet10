#include<stdio.h>
#include<stdlib.h>
void merge(float a[],int n,float key){
	int i=0;	
		float c[n];
			for(i=0;i<n;i++){
				c[i] = a[i];
			}
		if(key<=a[0]){		
			a[0] = key;		
			for(i = 1; i<n+1;i++){
				a[i] = c[i-1];
			}
		}
		else if(key>=a[n-1]){
			a[n] = key;
		}
		else{
			int y;
			for(i=0;i<n-1;i++){
				if(key>=a[i] && key<=a[i+1]){
					y = i;
					break;	
				}
			}
			a[y+1] = key;
			for(i=y+2;i<n+1;i++){
				a[i] = c[i-1];
			}
		}	
}
int main(){
	int n,i=0;
	scanf("%d",&n);
	float a[n];
	for(i=0;i<n;i++){
		scanf("%f",&a[i]);		
	}
	float b[n];
	int g = 0;
	float c[n];
	int g2 = 0;
	for(i=0;i<n;i++){		
		if(g==0){
			b[g] = a[i];			
			c[g2] = a[i];
			g2++;
			g++;
		}
		else{
		merge(b,g,a[i]);
		g++;		
		if(g%2 == 0){
			c[g2]=(b[((g)/2)-1]+b[(g)/2])/2;
			g2++;
		}
		else{			
			c[g2] = b[g/2];
			g2++;
		}		
		}
		
	}
	for(i=0;i<g2;i++){
		printf("%f\n",c[i]);
	}
	
}
