#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5e4 + 5;
struct Node{
	int x, y;
}t[maxn];
bool cmp(Node a, Node b){
	return a.x < b.x;
}
signed main(){
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> t[i].x >> t[i].y;
	Node a, b;
	int cnt = 0;
	sort(t + 1, t + n + 1, cmp);
	for (int i = 1; i <= n; i++){
		for (int j = i + 1; j <= min(i + 100, n); j++){
			if (t[j].x - t[i].x >= k) break;
			if (abs(t[i].y - t[j].y) < k){
				cnt++; 
				a.x = t[i].x, a.y = t[i].y;
				b.x = t[j].x, b.y = t[j].y;
			}
			if (cnt > 1) break;
		}
		if (cnt > 1) break;
	}
	if (cnt > 1){
		cout << -1;
	}else if (cnt == 1){
		cout << (k - abs(a.x - b.x)) * (k - abs(a.y - b.y));
	}else{
		cout << 0;
	}
	return 0;
}