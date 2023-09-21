#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 9 * 1e4 + 5;
int h[605], tot = 0;
int N;
struct node{
    int v, c, next;
}t[maxn << 1];
void addEdge(int u, int v, int c){
	++tot;
	t[tot].c = c; t[tot].v = v; t[tot].next = h[u]; h[u] = tot;
}
int s, dis[605], vis[605], num[605];
queue <int> q;
bool spfa(){
	while(!q.empty()) q.pop();
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
    memset(num, 0, sizeof(num));
	dis[s] = 0; q.push(s); num[s] = 1; vis[s] = 1;
	while(!q.empty()){
		int u = q.front(); q.pop(); vis[u] = 0;
		for (int i = h[u]; i; i = t[i].next){
			int v = t[i].v;
			if (dis[v] > dis[u] + t[i].c){
				dis[v] = dis[u] + t[i].c;
                num[v]++;
				if (!vis[v]){
					q.push(v); vis[v] = 1;
				}
				if(num[v] > N) 
                    return true;
			}
		}
	}
	return false;
}
int a[305][305], b[305][305];
signed main(){
    int T;
    cin >> T;
    while (T--){
        tot = 0;
        memset(h, 0, sizeof(h));
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n - 1; i++){
            for (int j = 1; j <= m - 1; j++){
                cin >> b[i][j];
            }
        }
        for (int i = 1; i <= n; i++)
            a[i][m] = 0;
        for (int i = 1; i <= m; i++)
            a[n][i] = 0;
        for (int i = n - 1; i >= 1; i--){
            for (int j = m - 1; j >= 1; j--){
                a[i][j] = b[i][j] - a[i + 1][j] - a[i][j + 1] - a[i + 1][j + 1];
            }
        }
        //1~n:r_i, 每行加减的量; n+1~n+m:c_i, 每列加减的量
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                int x = i; //r_i
                int y = n + j; //c_j
                if (i % 2 == j % 2){
                    addEdge(y, x, a[i][j]);
                    addEdge(x, y, 1e6 - a[i][j]); 
                }else if (i % 2 == 0 || j % 2 == 0){
                    addEdge(x, y, a[i][j]);
                    addEdge(y, x, 1e6 - a[i][j]); 
                }
            }
        }
        N = s = n + m + 1;
        for (int i = 1; i <= n; i++){
            addEdge(s, i, 0);
        }
        if (spfa()){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
            for (int i = 1; i <= n; i++){
                for (int j = 1; j <= m; j++){
                    int x = i; //r_i
                    int y = n + j; //c_j
                    if (i % 2 == j % 2){
                        a[i][j] = a[i][j] + dis[y] - dis[x];
                    }else if (i % 2 == 0 || j % 2 == 0){
                        a[i][j] = a[i][j] - dis[y] + dis[x];
                     }
                }
            }
            for (int i = 1; i <= n; i++){
                for (int j = 1; j <= m; j++){
                    cout << a[i][j] << ' ';
                }
                cout << endl;
            }
        }   
    }
    return 0;
}