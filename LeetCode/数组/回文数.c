#include <stdio.h>
#include <stdbool.h>
bool isPalindrome(int x){
	if(x<0) return false;
	int y = x,len  = 0,index = 0,a[11];

	while(y != 0){
		a[len] = y % 10;
		y /= 10;
		len++;
	}
	while(index < len/2){	
		if(a[index] != a[len-index-1]){
			return false;
		}
		index++;
	}
	return true;
}

int main(){
	printf("%d\n",isPalindrome(123));

	return 0;
}

