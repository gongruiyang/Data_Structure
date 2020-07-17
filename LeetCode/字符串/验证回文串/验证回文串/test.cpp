#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>
#include <assert.h>
#include <string.h>
#pragma warning(disable:4996)

bool isPalindrome(char * s){
	int len = strlen(s);
	if (len == 0 || len == 1){
		return true;
	}
	int count1 = 0, count2 = 0;
	char *end = s;
	end += len - 1;
	while (end >= s){
		while (end >= s){
			if (*end >= 'a' && *end <= 'z' || *end >= 'A'&&*end <= 'Z' || *end >= '0' && *end <= '9'){
				count1++;
				break;
			}
			else{
				end--;
				continue;
			}
		}
		while (end >= s){
			if (*s >= 'a' && *s <= 'z' || *s >= 'A'&&*s <= 'Z' || *s >= '0' && *s <= '9'){
				count2++;
				break;
			}
			else{
				s++;
				continue;
			}
		}
		if (end < s) break;
		if (*end == *s || *end == toupper(*s) || *end == tolower(*s)){
			end--;
			s++;
			continue;
		}else{
			return false;
		}
	}
	return true;
}
int main(){
	char s[100];
	gets(s);
	bool flag = isPalindrome(s);
	printf("%d", flag);

	system("pause");
	return 0;
}