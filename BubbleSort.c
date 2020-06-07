#include <stdio.h>
#define N 10
void BubbleSort(int a[]){
	int i,j,temp;
	for(i = N - 1; i >= 0; i--) {
		for(j = 0; j < i; j++) {
			if(a[j]>a[j+1]) {
				int temp = a[j];
				a[j]  = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}
int main(){
	int a[N];
	int i;
	for(i = 0; i<N;i++){
		scanf("%d",&a[i]);
	}
	
	BubbleSort(a);
	printf("After BubbleSort : ");
	for(i = 0; i<N;i++){
		printf("%d ",a[i]);
	}
	putchar('\n');
	
	return 0;
} 
