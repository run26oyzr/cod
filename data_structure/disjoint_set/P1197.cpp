#include <bits/stdc++.h>
using namespace std;
const int maxn = 2 * 1e5 + 5, maxm = 4 * 1e5 + 5;
int cnt = -1;
int fa[maxn];
int ans[maxn];
int tot;
int attacked[maxn];
int attack_order[maxn];
struct Node{
    int next, val, previos;
}t[maxm];
int h[maxn];
void addedge(int u, int v){
	++cnt;
	t[cnt].previos = u, t[cnt].val = v; t[cnt].next = h[u]; h[u] = cnt;
}
int getfather(int x){
    if (fa[x] == x) return x;
    return fa[x] = getfather(fa[x]);
}
void merge(int x, int y){
    int fx = getfather(x);
    int fy = getfather(y);
    fa[fy] = fx;
}
int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) fa[i] = i;
    int x, y;
    while(m--){
        cin >> x >> y;
        addedge(x, y);
        addedge(y, x);
    }
    int k;
    cin >> k;
    tot = n - k;
    for (int i = 1; i <= k; i++){
        cin >> attack_order[i];
        attacked[attack_order[i]] = 1;
    }
    for (int i = 1; i <= 2 * m; i++){
        if (!attacked[t[i].val] && !attacked[t[i].previos] && (getfather(t[i].val) != getfather(t[i].previos))){
            merge(t[i].val, t[i].previos);
            tot--;
        }
    }
    ans[k + 1] = tot;
    for (int i = k; i >= 1; i--){
        tot++;
        attacked[attack_order[i]] = 0;
        for (int j = h[attack_order[i]]; j; j = t[j].next){
            if (!attacked[t[j].val] && (getfather(t[j].val) != getfather(attack_order[i]))){
                tot--;
                merge(attack_order[i], t[j].val);
            }
        }
        ans[i] = tot;
    }
    for (int i = 1; i <= k + 1; i++) cout << ans[i] << endl;
    system("Pause");
    return 0;
}