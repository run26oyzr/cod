#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2 * 1e6 + 5;
int n, m;
struct node{
    int x, y, id;
    bool operator < (const node T) const {
        return y < T.y;
    }
}ask[maxn];
int ans[maxn];
int tree[maxn], t[maxn];
int lastpos[maxn];
int lowbit(int x) {return x & (-x);}
void add(int id, int val){
    // if (id == 0) return;
    while(id <= n){
        tree[id] += val;
        id += lowbit(id);
    }
}
int sum(int id){
    int res = 0;
    while (id >= 1){
        res += tree[id];
        id -= lowbit(id);
    }
    return res;
}
signed main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> t[i];
        // add(t[i], 1);
        // if (lastpos[t[i]] == 0) lastpos[t[i]] = i;
    }
    cin >> m;
    int x, y;
    for (int i = 1; i <= m; i++){
        cin >> ask[i].x >> ask[i].y;
        ask[i].id = i;
    }
    sort(ask + 1, ask + m + 1);
    int left = 1;
    for (int j = 1; j <= m; j++){
        x = ask[j].x; y = ask[j].y;
        for (int i = left; i <= y; i++){
            if (lastpos[t[i]]) add(lastpos[t[i]], -1);
            add(i, 1);
            lastpos[t[i]] = i;
        }
        left = y + 1;
        ans[ask[j].id] = sum(y) - sum(x - 1);
    }
    for (int i = 1; i <= m; i++){
        cout << ans[i] << endl;
    }
    system("Pause");
    return 0;
}