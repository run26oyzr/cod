#include <bits/stdc++.h>
using namespace std;
struct node{
	int id, val;
	bool operator < (const node T)const{
		if (val == T.val) return id < T.id;
		return val < T.val;
	}
};
const int maxn = 1e6 + 5;
node t[maxn];
int main()
{
	int n;
	double num = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		cin >> t[i].val;
		t[i].id = i;
	}
	sort (t + 1, t + n + 1);
	for (int i = 1; i <= n; i++){
		cout << t[i].id << ' ';
		num += t[i].val * (n - i);
	}
	num = num / n;
	printf("\n%.2lf", num);
	return 0;
}
