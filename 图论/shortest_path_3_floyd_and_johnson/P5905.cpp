#include <bits/stdc++.h>
using namespace std;
const int maxn = 3 * 1e3 + 5, maxm = 6 * 1e3 + 5;

int h[maxn];
int n, m, tot;
struct node{
    int v, c, next;
}t[maxm << 2];
void addEdge(int u, int v, int c){
	++tot;
	t[tot].c = c; t[tot].v = v; t[tot].next = h[u]; h[u] = tot;
}

int s, H[maxn], vis[maxn], num[maxn], dis[maxn];
queue<int> q;
bool spfa(){
	while(!q.empty()) q.pop();
	memset(H, 0x3f, sizeof(H));
	memset(vis, 0, sizeof(vis));
	H[s] = 0; q.push(s); num[s] = 1; vis[s] = 1;
	while(!q.empty()){
		int u = q.front(); q.pop(); vis[u] = 0;
		for (int i = h[u]; i; i = t[i].next){
			int v = t[i].v;
			if (H[v] > H[u] + t[i].c){
				H[v] = H[u] + t[i].c;
				if (!vis[v]){
					q.push(v); vis[v] = 1; num[v] ++;
					if(num[v] > n) return false;
				}
			}
		}
	}
	return true;
}

struct Queue{
	int u, dis;
	bool operator < (const Queue T)const{
		return dis > T.dis;
	}
};
priority_queue <Queue> Q;
void dijkstra_queue(){
    while(!Q.empty()) Q.pop();
	for (int i = 1; i <= n; i++) dis[i] = 1e9;
	memset(vis, 0, sizeof(vis));
	dis[s] = 0;
	Q.push(Queue{s, 0});
	while(!Q.empty()){
		Queue now = Q.top(); Q.pop();
		int u = now.u;
		if (vis[u]) continue;
		vis[u] = 1;
		for (int j = h[u]; j; j = t[j].next){
			int v = t[j].v;
			if (vis[v]) continue;
			if (dis[u] + t[j].c < dis[v]){
				dis[v] = dis[u] + t[j].c;
				Q.push(Queue{v, dis[v]});
			}
		}	
	}
}

int main(){
    cin >> n >> m;
    int x, y, z;
    for (int i = 1; i <= m; i++){
        cin >> x >> y >> z;
        addEdge(x, y, z);
    }
    for (int i = 1; i <= n; i++){
        addEdge(0, i, 0);
    }
    s = 0;
    if (!spfa()){
        cout << -1;
        system("pause");
        return 0;
    }
    for (int i = 1; i <= n; i++){
        for (int j = h[i]; j; j = t[j].next) t[j].c = t[j].c + H[i] - H[t[j].v];
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++){
        ans = 0;
        s = i;
        dijkstra_queue();
        for (int j = 1; j <= n; j++){
            if (dis[j] == 1e9) ans += 1e9;
            else ans += j * (dis[j] - H[i] + H[j]);
        }
        cout << ans << endl;
    }
    system("pause");
    return 0;
}