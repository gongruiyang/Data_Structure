#include <stdio.h>
#include <stdbool.h>
int reverse(int x){
    long count=0;
    while(x!=0){
        count=count*10+x%10;
        x=x/10;
    }
    return count;
}
bool isPalindrome(int x){
	if(x<0) return false;
	if(reverse(x) == x){
		return true;
	}
	return false;

}

int main(){
	printf("%d\n",isPalindrome(12321));

	return 0;
}
