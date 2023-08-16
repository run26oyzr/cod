#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
struct node{
	int t, val;
	bool operator < (const node T)const{
		if (t == T.t) return val > T.val;
		return t < T.t;
	}
};
node t[maxn];
int main()
{
//	freopen("P2949_3.in", "r", stdin);
	priority_queue <int, vector<int>, less<int> >q;
	long long n, cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> t[i].t >> t[i].val;
	}
	sort(t + 1, t + n + 1);
	int tim = 0;
	for (int i = 1; i <= n; i++){
		if (tim < t[i].t) {
			q.push(t[i].val); 
			tim++;
		}
		else if (tim == t[i].t){
			if (t[i].val > q.top()){
				q.top();
				q.push(t[i].val);
			}
		}
	}
	while (!q.empty()){
		cnt += q.top();
		q.pop();
	}
	cout << cnt;
	return 0;
}
