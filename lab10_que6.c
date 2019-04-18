#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	int global[100000];
	int n;
	scanf("%d",&n);
	int i,j,k,g=0;
	int freq_min = 0;
	int freq_max = 0;
	int min = 100000;
	int max = 0;
	char ch[10];
	char query1[10] = "Push";
	char query2[10] = "Diff";
	char query3[10] = "CountHigh";
	char query4[10] = "CountLow";
	for(i=0;i<n;i++){
		int num;
		scanf("%s",ch);
		if(strcmp(ch,query1)==0){
			scanf("%d",&num);
			global[g] = num;
			g++;
			if(min != max){
				if(num == min){
					freq_min++;
				}
				if(num == max){
					freq_max++;		
				}
				if(num>max){
					max = num;
					freq_max = 1;
				}
				if(num<min){
					min = num;
					freq_min = 1;
				}				
			}
			else if(min == max){
				if(num == max){
					freq_max++;
					freq_min++;
				}
				if(num>max){
					max = num;
					freq_max = 1;
				}
				if(num<min){
					min = num;
					freq_min = 1;
				}
			}
		}
		else if(strcmp(ch,query2)==0){
			if
		}
	}
}

