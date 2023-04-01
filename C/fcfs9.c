#include<stdio.h>
#include <stdlib.h>

void sortBased(int a[], int b[], int c[], int n){
	
	for(int i = 0; i < n-1; i++){
		for(int j=i+1; j<n;j++){
			if(c[i] > c[j]){
				int t1=c[i];
				c[i]=c[j];
				c[j]=t1;
				t1=a[i];
				a[i]=a[j];
				a[j]=t1;
				t1=b[i];
				b[i]=b[j];
				b[j]=t1;
			}
		}
	}
	
}


int main(){
	
	
	int n;
	printf("Enter number of processess: ");
	scanf("%d", &n);

	int PID[n],AT[n], BT[n], CT[n], TAT[n], WT[n];
	
	for(int i=0;i<n;i++){
		printf("Enter AT for P%d: ",i+1);
		scanf("%d", &AT[i]);
		printf("Enter BT for P%d: ",i+1);
		scanf("%d", &BT[i]);

		PID[i] = i+1;
	}
	sortBased(PID, BT, AT); // last argument is sorted and remaining based on the last.

	
	
}
