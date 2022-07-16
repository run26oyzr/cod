#include <bits/stdc++.h>
using namespace std;
const int maxn = 5 * 1e5 + 5;
int h[maxn], tot = 0;
struct node{
	int v, c, next;
}t[maxn << 1];
//u：开始， v:结束， c：权值 
int cow[maxn];
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
    while(!q.empty()) q.pop();
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
			if (dis[u] + t[j].c < dis[v]){
				dis[v] = dis[u] + t[j].c;
				q.push(Queue{v, dis[v]});
			}
		}	
	}
}

int main(){
    int p;
	cin >> n >> m >> p;
	int u, v, c;
    int x;
    for (int i = 1; i <= n; i++){
        cin >> x;
        cow[x]++;
    }
	for (int i = 1; i <= p; i++){
		cin >> u >> v >> c;
		addEdge(u, v, c);
        addEdge(v, u, c);
	}
    int ans = 1e9;
	// cout << endl;
	for (int i = 1; i <= m; i++){
        s = i;
        dijkstra_queue();
        int num = 0;
        for (int i = 1; i <= m; i++){
            num += dis[i] * cow[i];
        }
        // cout << i << ' ' << num << endl;
		ans = min(ans, num);
    }
    cout << ans;
    system("Pause");
}