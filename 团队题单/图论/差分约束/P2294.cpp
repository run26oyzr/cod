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
bool spfa(int x){
    s = x;
	while(!q.empty()) q.pop();
	memset(dis, -1, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	dis[s] = 0; q.push(s); num[s] = 1; vis[s] = 1;
	while(!q.empty()){
		int u = q.front(); q.pop(); vis[u] = 0;
		for (int i = h[u]; i; i = t[i].next){
			int v = t[i].v;
			if (dis[v] < dis[u] + t[i].c){
				dis[v] = dis[u] + t[i].c;
				if (!vis[v]){
					q.push(v); vis[v] = 1; num[v] ++;
					if(num[v] > n) return true;
				}
			}
		}
	}
	return false;
}
int main(){
    int T;
    cin >> T;
    while(T--){
        tot = 0;
        cin >> n >> m;
        memset(num, 0, sizeof(num));
        memset(h, 0, sizeof(h));
        for (int i = 1; i <= n; i++){
            t[i].v = t[i].c = t[i].next = 0;
        }
        int x, y, z;
        for (int i = 1; i <= m; i++){
            cin >> x >> y >> z;
            addEdge(y, x - 1, z);
            addEdge(x - 1, y, -z);
        }
        int flag = 0;
        for (int i = 1; i <= n; i++){
            if (spfa(i)) flag = 1;
        }
        if (flag) cout << "false" << endl;
        else cout << "true" << endl;
    }
    system("pause");
    return 0;
}