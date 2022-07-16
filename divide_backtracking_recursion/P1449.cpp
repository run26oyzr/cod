#include <bits/stdc++.h>
using namespace std;
long long a[505];
int main()
{
	long long num = 0, i = 0;
	char c;
	while (true){
		scanf("%c", &c);
		if (c >= '0' && c <= '9') num = num * 10 + c - '0';
		else if (c == '.') {a[++i] = num; num = 0;} 
		else if (c == '-') {a[i - 1] = a[i - 1] - a[i]; i--;}
		else if (c == '*') {a[i - 1] = a[i - 1] * a[i]; i--;}
		else if (c == '/') {a[i - 1] = a[i - 1] / a[i]; i--;}
		else if (c == '+' && i != 1) {a[i - 1] = a[i - 1] + a[i]; i--;}
		else if (c == '@') break;
	}
	cout << a[1];
	return 0;
}
