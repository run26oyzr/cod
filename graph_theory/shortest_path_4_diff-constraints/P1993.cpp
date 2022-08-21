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
					if(num[v] > n) return true;
				}
			}
		}
	}
	return false;
}
int main(){
	tot = 0;
	cin >> n >> m;
	s = n + 1;
	memset(num, 0, sizeof(num));
	memset(h, 0, sizeof(h));
    int x, y, z, a;
	for (int i = 1; i <= m; i++){
        cin >> a >> x >> y;
        if (a == 1){
            cin >> z;
            addEdge(x, y, -z);
        }
        if (a == 2){
            cin >> z;
            addEdge(y, x, z);
        }
        if (a == 3){
            addEdge(x, y, 0);
        }
    }
    n++;
    for (int i = 1; i <= n; i++){
        addEdge(n, i, 0);
    }
	if (spfa()) cout << "No" << endl;
	else{
        cout << "Yes";
    }
    system("pause");
    return 0;
}