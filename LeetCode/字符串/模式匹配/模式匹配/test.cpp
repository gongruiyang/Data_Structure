#include <stdio.h>
#include <Windows.h>
#pragma warning(disable:4996)
bool patternMatching(char* pattern, char* value) {
	int count_a = 0, count_b = 0;	//����ͳ��a��b�ĸ���
	int len_pat = strlen(pattern);	//��pattern����
	int len_val = strlen(value);	//��value����

	for (int i = 0; i < len_pat; i++) {	//�ó�a��b����
		if (pattern[i] == 'a') {
			++count_a;
		}
		else {
			++count_b;
		}
	}

	if (count_a < count_b) {	//��a�ĸ���С��b�ĸ���ʱ����ab����
		int t = count_a;
		count_a = count_b, count_b = t;
		for (int i = 0; i < len_pat; i++) {
			if (pattern[i] == 'a') {
				pattern[i] = 'b';
			}
			else {
				pattern[i] = 'a';
			}
		}
	}

	if (len_val == 0) {	//����ַ���valueΪ�� ���ж�pattern���Ƿ���b����û�������aΪ�մ���������
		return count_b == 0;
	}
	if (len_pat == 0) {	//��patternΪ�գ��򷵻�false
		return false;
	}

	for (int len_a = 0; count_a * len_a <= len_val; ++len_a) {
		int rest = len_val - count_a * len_a;
		if ((count_b == 0 && rest == 0) ||
			(count_b != 0 && rest % count_b == 0)) {
			int len_b = (count_b == 0 ? 0 : rest / count_b);
			int pos = 0;
			char value_a[1001], value_b[1001], sub[1001];
			value_a[0] = value_b[0] = sub[0] = '\0';
			bool correct = true;
			for (int i = 0; i < len_pat; i++) {
				if (pattern[i] == 'a') {
					for (int j = 0; j < len_a; j++) sub[j] = value[j + pos];
					sub[len_a] = '\0';
					if (!strlen(value_a)) {
						strcpy(value_a, sub);
					}
					else if (strcmp(value_a, sub)) {
						correct = false;
						break;
					}
					pos += len_a;
				}
				else {
					for (int j = 0; j < len_b; j++) sub[j] = value[j + pos];
					sub[len_b] = '\0';
					if (!strlen(value_b)) {
						strcpy(value_b, sub);
					}
					else if (strcmp(value_b, sub)) {
						correct = false;
						break;
					}
					pos += len_b;
				}
			}
			if (correct && value_a != value_b) {
				return true;
			}
		}
	}
	return false;
}
int main(){
	char pattern[10] = "abba";
	char value[100] = "dogcatcatdog";

	printf("%d\n", patternMatching(pattern, value));

	system("pause");
	return 0;
}