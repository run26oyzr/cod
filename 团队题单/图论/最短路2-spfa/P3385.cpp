#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
int h[maxn], tot = 0;
int n, m;
struct node{
    int v, c, next;
}t[maxn << 2];
void addEdge(int u, int v, int c){
	++tot;
	t[tot].c = c; t[tot].v = v; t[tot].next = h[u]; h[u] = tot;
}
int s, dis[maxn], vis[maxn], num[maxn];
queue<int> q;
bool spfa(){
	while(!q.empty()) q.pop();
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	dis[s] = 0; q.push(s); num[s] = 1; vis[s] = 1;
	while(!q.empty()){
		int u = q.front(); q.pop(); vis[u] = 0;
		for (int i = h[u]; i; i = t[i].next){
			int v = t[i].v;
			if (dis[v] > dis[u] + t[i].c){
				dis[v] = dis[u] + t[i].c;
				if (!vis[v]){
					q.push(v); vis[v] = 1; num[v] ++;
					if(num[v] > n) return false;
				}
			}
		}
	}
	
	return true;
}
int main(){
	int T;
	cin >> T;
	while(T--){
		s = 1;
		tot = 0;
		cin >> n >> m;
		memset(num, 0, sizeof(num));
		memset(h, 0, sizeof(h));
		for (int i = 1; i <= maxn; i++){
			t[i].v = 0; t[i].c = 0; t[i].next = 0;
		}
		while(m--){
			int u, v, c;
			cin >> u >> v >> c;
			if (c >= 0){
				addEdge(u, v, c);
				addEdge(v, u, c);
			}
			else addEdge(u, v, c);
		}
		if (spfa()) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
    return 0;
}