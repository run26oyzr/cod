#include <bits/stdc++.h>
using namespace std;
typedef __int128 ll;
const int maxn = 1e5 + 5, maxm = 1e6 + 5;
struct Node{
	int v, next;
}t[maxm << 2];
int h[maxn], in[maxn], out[maxn], tot;
void addEdge(int u, int v){
	++tot;
	t[tot].v = v, t[tot].next = h[u], h[u] = tot;
	in[v]++;
}
struct node{
	ll p, q;
}f[maxn];

void plus_(int i, ll p2, ll q2){
	if (!f[i].q) f[i].q = 1;
    if (q2 == 0) q2 = 1;
	ll p1 = f[i].p;
	ll q1 = f[i].q;
	f[i].q *= q2;
	f[i].p = p1 * q2 + p2 * q1;
	ll gcd_ = __gcd(f[i].p, f[i].q);
	f[i].q /= gcd_;
	f[i].p /= gcd_;
//	cout << i << ' ' << f[i].p << ' ' << f[i].q << endl;
}
int n, m;
queue <int> q;
void topo(){
	for (int i = 1; i <= n; i++){
		if (in[i] == 0){
			q.push(i); f[i].p = 1; f[i].q = 1;
		}
	}
	while(!q.empty()){
		int u = q.front(); q.pop();
		for (int i = h[u]; i; i = t[i].next){
			int v = t[i].v;
			plus_(v, f[u].p, f[u].q * out[u]);
			in[v]--;
			if (in[v] == 0) {
				q.push(v);
			}
		}
	}
}
void print(ll v)
{
    if (!v) return;
    if (v < 0) v = -v;
    print(v / 10);
    putchar(v % 10 + '0');
}
int main(){
    // freopen("./noip_kezuo/P7113.in", "r", stdin);
    // freopen("./noip_kezuo/P7113.out", "w", stdout);
	cin >> n >> m;
	int x, y;
	for (int i = 1; i <= n; i++){
		cin >> x;
		for (int j = 1; j <= x;j++){
			cin >> y;
			addEdge(i, y);
		}
		out[i] = x;
	}
	topo();
	for (int i = 1; i <= n; i++){
		if (out[i] == 0){
			print(f[i].p);
			cout << ' ';
			print(f[i].q);
			cout << "\n";
		}
	}
	return 0;
}