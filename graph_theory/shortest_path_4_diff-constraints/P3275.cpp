#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
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
    tot = 0;
    cin >> n >> m;
    int x, y, z;
    for (int i = 1; i <= m; i++){
        scanf("%d %d %d" , &x, &y, &z);
        if (x == 1){
            addEdge(y, z, 0);
            addEdge(z, y, 0);
        }
        if (x == 2){
            if (y == z){
                cout << -1;
                return 0;
            }
            addEdge(y, z, 1);
        }
        if (x == 3){
            addEdge(z, y, 0);
        }
        if (x == 4){
            if (y == z){
                cout << -1;
                return 0;
            }
            addEdge(z, y, 1);
        }
        if (x == 5){
            addEdge(y, z, 0);
        }
    }
    n++;
    for (int i = 1; i < n; i++){
        addEdge(n, i, 1);
    }
    if (spfa(n)) cout << -1;
    else{
        int ans = 0;
        for (int i = 1; i < n; i++){
            ans += dis[i];
        }
        cout << ans;
    }
    system("pause");
    return 0;
}