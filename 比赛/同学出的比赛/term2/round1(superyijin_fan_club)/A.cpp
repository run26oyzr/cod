#include <bits/stdc++.h>
using namespace std;
stack <int> num;
int main(){
	int cnt = 0;
	char c;
	while(true){
		scanf("%c", &c);
		if (c == '('){
			cnt++;
			num.push(cnt);
		}
		if (c == ')'){
			printf("%d ", num.top());
			num.pop();
			if(num.empty()) break;
		}
	}
	return 0;
}