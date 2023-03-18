#include <bits/stdc++.h>
using namespace std;
const int maxn = 5 * 1e5 + 5, mod = 100003;
int h[maxn], tot = 0;
struct node{
	int v, c, next;
}t[maxn << 1];
void addEdge(int u, int v, int c){
	++tot;
	t[tot].c = c; t[tot].v = v; t[tot].next = h[u]; h[u] = tot;
}
int dis[maxn], vis[maxn], ans[maxn];
int s;
int n, m;
struct Queue{
	int u, dis;
	bool operator < (const Queue T)const{
		return dis > T.dis;
	}
};
priority_queue <Queue> q;
void dijkstra_queue(){
	memset(dis, 0x3f3f3f3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	dis[s] = 0;
	q.push(Queue{s, 0});
    ans[1] = 1;
	while(!q.empty()){
		Queue now = q.top(); q.pop();
		int u = now.u;
		if (vis[u]) continue;
		vis[u] = 1;
		for (int j = h[u]; j; j = t[j].next){
			int v = t[j].v;
			if (vis[v]) continue;
			if (dis[u] + t[j].c < dis[v]){
				dis[v] = dis[u] + t[j].c;
				q.push(Queue{v, dis[v]});
			}
            if (dis[v] == dis[u] + 1){
                ans[v] = (ans[v] + ans[u]) % mod;
            }
		}	
	}
}
int main(){
	cin >> n >> m;
	s = 1;
	int u, v, c;
	for (int i = 1; i <= m; i++){
		cin >> u >> v;
		c = 1;
		addEdge(u, v, c);
		addEdge(v, u, c);
	}
	dijkstra_queue();
	for (int i = 1; i <= n; i++){
		cout << ans[i] << endl;
	}
    
}