#include <bits/stdc++.h>
using namespace std;
const int maxn = 15, maxk = 10, maxedge = (1 << maxk) * 100, maxm = 105;
int h[1 << maxk], tot = 0;
struct node{
	int v, next;
}t[maxedge << 1];
void addEdge(int u, int v){
	++tot;
	t[tot].v = v; t[tot].next = h[u]; h[u] = tot;
}
int dis[1 << maxk], vis[1 << maxk];
struct Queue{
	int u, dis;
	bool operator < (const Queue T)const{
		return dis > T.dis;
	}
};
priority_queue <Queue> q;
void dijkstra_queue(int s){
	memset(dis, 0x3f, sizeof(dis));
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
			if (dis[u] + 1 < dis[v]){
				dis[v] = dis[u] + 1;
				q.push(Queue{v, dis[v]});
			}
		}	
	}
}
int a[maxm][maxn];
int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    for (int s = 0; s < (1 << n); s++){
        for (int i = 1; i <= m; i++){
            int t = s;
            for (int j = 1; j <= n; j++){
                if (((s >> (j - 1)) & 1) && a[i][j] == 1)
                    t ^= (1 << (j - 1));
                if ((!((s >> (j - 1)) & 1)) && a[i][j] == -1)
                    t ^= (1 << (j - 1));
            }
            addEdge(s, t);
        }
    }
    dijkstra_queue((1 << n) - 1);
    if (dis[0] > 1e9) cout << -1;
    else cout << dis[0];
    return 0;
}