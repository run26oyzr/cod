#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
int n, m, maxm = 1;
struct node{
    int x, y;
    bool operator < (const node T) const {
        return T.y < y;
    }
}ask[maxn];
int tree[maxn], t[maxn];
int lastpos[maxn];
int lowbit(int x) {return x & (-x);}
void add(int id, int val){
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
int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> t[i];
        add(i, 1);
        if (lastpos[t[i]] == 0) lastpos[t[i]] = i;
    }
    cin >> m;
    int x, y;
    for (int i = 1; i <= m; i++){
        cin >> ask[i].x >> ask[i].y;
    }
    sort(ask + 1, ask + m + 1);
    for (int j = 1; j <= m; j++){
        x = ask[j].x; y = ask[j].y;
        if (y > maxm){
            for (int i = maxm + 1; i <= y; i++){
                add(lastpos[t[i]], -1);
                lastpos[t[i]] = i;
                add(i, 1);
            }
            maxm = y;
        }
        cout << sum(y) - sum(x - 1) << endl;
    }
    system("Pause");
    return 0;
}