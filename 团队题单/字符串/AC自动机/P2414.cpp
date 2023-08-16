#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int ch[maxn][26];
int CH[maxn][26];
char s[maxn];
int flag[maxn], fail[maxn];
int fa[maxn];
int tot = 0, rt = 0, n;

struct Node{
    int v, nxt;
}t[maxn];
int h[maxn], totEdge = 0;
void addEdge(int u, int v){
    ++totEdge;
    t[totEdge].v = v; t[totEdge].nxt = h[u]; h[u] = totEdge;  
}
int dfn[maxn], size[maxn], end_[maxn], now = 0;
void dfs(int u){
    size[u] = 1;
    dfn[u] = ++now;
    for(int i = h[u]; i; i = t[i].nxt){
        int v = t[i].v;
        dfs(v);
        size[u] += size[v];
    }
    end_[u] = now;  
}

queue <int> q; 
void getFail(){
	for(int i = 0; i < 26; i++){
		if(ch[rt][i]){
			fail[ch[rt][i]] = rt;
            addEdge(fail[ch[rt][i]], ch[rt][i]);
			q.push(ch[rt][i]);
		}
	}
	int p;
	while(!q.empty()){
		p = q.front(); q.pop();
		for(int i = 0; i < 26; i++){
			if(ch[p][i]){
				fail[ch[p][i]] = ch[fail[p]][i];
                addEdge(fail[ch[p][i]], ch[p][i]);
				q.push(ch[p][i]);
			}else{
				ch[p][i] = ch[fail[p]][i];
			}
		}
	} 
}

int tree[maxn];
int lowbit(int x) {return x & (-x);}
void add(int id, int val){
    while(id <= now){
        tree[id] += val;
        id += lowbit(id);
    }
}
int query(int id){
    int res = 0;
    while(id >= 1){
        res += tree[id];
        id -= lowbit(id);
    }
    return res;
}

struct Query{
    int x, y;
    int id, ans;
}Q[maxn];
bool cmp1(Query a, Query b){
    return a.y < b.y;
}
bool cmp2(Query a, Query b){
    return a.id < b.id;
}

bool vis[maxn];
int flag_[maxn];
int ql[maxn], qr[maxn];
void DFS(int u){
    if(vis[u]) return;
    // cout << "--start dfs: " << u << endl;
    vis[u] = true;
    if(u != rt) add(dfn[u], 1);
    if(flag_[u]){
        for(int i = ql[flag_[u]]; i <= qr[flag_[u]]; i++){
            Q[i].ans = query(end_[flag[Q[i].x]]) - query(dfn[flag[Q[i].x]] - 1);
            // cout << u << ' ' << flag[Q[i].x] << ' ' << end_[flag[Q[i].x]] << ' ' << dfn[flag[Q[i].x]] << ' ' << Q[i].ans << endl;
        }
    }
    for(int i = 0; i < 26; i++){
        if(CH[u][i]){
            // if(!vis[CH[u][i]]) cout << "--start dfs " << CH[u][i] << " from " << u << endl;
            DFS(CH[u][i]);
        }
    }
    if(u != rt) add(dfn[u], -1);
    // cout << "--end dfs: " << u << endl;
}

int main(){
	cin >> s;
	n = strlen(s);
	int p = rt;
    int cnt = 0;
	for(int i = 0; i < n; i++){
        if(s[i] == 'P'){
            flag[++cnt] = p;
            flag_[p] = cnt;
        }
        else if(s[i] == 'B')
            p = fa[p];
        else{
            if(!ch[p][s[i] - 'a']){
                ch[p][s[i] - 'a'] = ++tot;
                fa[tot] = p;
            }
            p = ch[p][s[i] - 'a'];
        }
	}
    for(int i = 0; i <= tot; i++){
        for(int j = 0; j < 26; j++){
            CH[i][j] = ch[i][j];
        }
    }
    // for(int i = 1; i <= cnt; i++){
    //     int tmp = flag[i];
    //     int pos = 0;
    //     while(tmp != rt){
    //         // cout << tmp << ' ';
    //         int father = fa[tmp];
    //         for(int j = 0; j < 26; j++){
    //             if(ch[father][j] == tmp){
    //                 s[++pos] = j + 'a';
    //                 // cout << (char)(j + 'a') << endl;
    //             }
    //         }
    //         tmp = father;
    //     }
    //     reverse(s + 1, s + pos + 1);
    //     for(int j = 1; j <= pos; j++) cout << s[j];
    //     cout << endl;
    // }
	getFail();
    dfs(rt);
    int m;
    cin >> m;
    for(int i = 1; i <= m; i++){
		cin >> Q[i].x >> Q[i].y;
        Q[i].id = i;
	}
    sort(Q + 1, Q + m + 1, cmp1);
	for(int i = 1, pos = 1; i <= m; i = pos){
        ql[Q[i].y] = i;
        while(Q[pos].y == Q[i].y) pos++;
        qr[Q[i].y] = pos - 1;
    }
    DFS(rt);
    sort(Q + 1, Q + m + 1, cmp2);
    for(int i = 1; i <= m; i++){
        cout << Q[i].ans << endl;
    }
	return 0;
}