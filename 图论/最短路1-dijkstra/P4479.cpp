#include <bits/stdc++.h>
using namespace std;
const int maxn = 5 * 1e5 + 5;
int h[maxn], tot = 0;
struct node{
	int v, c, next;
}t[maxn << 1];
//u：开始， v:结束， c：权值 
void addEdge(int u, int v, int c){
	++tot;
	t[tot].c = c; t[tot].v = v; t[tot].next = h[u]; h[u] = tot;
}
int dis[maxn], vis[maxn];
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
		}	
	}
}
void dijkstra(){
	memset(dis, 0x3f3f3f3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	int u = s; dis[s] = 0; vis[s] = 1;
	for (int i = 1; i < n; i++){ //n-1遍 
		//1.从源点扩展，松弛 
		for (int j = h[u]; j; j = t[j].next){
			int v = t[j].v;
			if (vis[v]) continue;
			if (dis[u] + t[j].c < dis[v]) dis[v] = dis[u] + t[j].c;
		}
		//2.确定最短路的点 
		int mina = 0x3f3f3f3f;
		for (int j = 1; j <= n; j++){
			if (!vis[j]){
				if (dis[j] < mina){
					mina = dis[j];
					u = j;
				}
			}
		}
		vis[u] = 1;
	}
}
int main(){
	cin >> n >> m >> s;
	int u, v, c;
	for (int i = 1; i <= m; i++){
		cin >> u >> v >> c;
		addEdge(u, v, c);
	}
	dijkstra_queue();
	for (int i = 1; i <= n; i++){
		if (i == s) cout << 0 << " ";
		else{
			if (dis[i] == 0x3f3f3f3f) cout << 2147483647 << " ";
			else cout << dis[i] << " ";
		}
	}
}