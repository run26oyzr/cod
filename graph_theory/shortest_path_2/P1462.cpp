#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5 * 1e4 + 5;
int h[maxn], tot = 0;
struct node{
	int v, c, next;
}t[maxn << 1];
void addEdge(int u, int v, int c){
	++tot;
	t[tot].c = c; t[tot].v = v; t[tot].next = h[u]; h[u] = tot;
}
int dis[maxn], vis[maxn];
int money[maxn], nowmoney;
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
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	dis[s] = 0;
    if (money[s] > nowmoney) return;
	// if (money[t[s].v] > nowmoney) return;
	q.push(Queue{s, 0});
	while(!q.empty()){
		Queue now = q.top(); q.pop();
		int u = now.u;
        // if (money[u] > nowmoney) continue;
		if (vis[u]) continue;
		vis[u] = 1;
		for (int j = h[u]; j; j = t[j].next){
			int v = t[j].v;
			if (money[v] > nowmoney) continue;
			if (!vis[v]){
				dis[v] = dis[u] + t[j].c;
				q.push(Queue{v, dis[v]});
			}
		}	
	}
}
signed main(){
    // freopen("P1462.in", "r", stdin);
    // freopen("P1462.out", "w", stdout);
	int b;
	cin >> n >> m >> b;
	int u, v, c;
    int maxc = 0, minc = 1e9;
	for (int i = 1; i <= n; i++){
		cin >> money[i];
		minc = min(minc, money[i]);
		maxc = max(maxc, money[i]);
	}
	for (int i = 1; i <= m; i++){
		cin >> u >> v >> c;
		if (u != v){
			addEdge(u, v, c);
			addEdge(v, u, c);
		}
	}
	int L = minc, R = maxc;
	while(L < R){
		s = 1;
		int mid = (L + R) / 2;
		nowmoney = mid;
		dijkstra_queue();
		if (dis[n] <= b) R = mid;
		else L = mid + 1;
	} 
    nowmoney = L;
    dijkstra_queue();
    if (dis[n] <= b) cout << L;
    else cout << "AFK";
    // system("Pause");
    return 0;
}