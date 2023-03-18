#include <bits/stdc++.h>
using namespace std;
const int maxn = 2 * 1e5;
int n, q;
int tree1[maxn], tree2[maxn]; //tree1 行, tree2 列
int vis1[maxn], vis2[maxn]; //vis1  行, vis2 列
int lowbit(int x){return x & (-x);}
void add1(int id, int val){
    while(id <= n){
        tree1[id] += val;
        id += lowbit(id);
    }
}
int query1(int id){
    int res = 0;
    while(id >= 1){
        res += tree1[id];
        id -= lowbit(id);
    }
    return res;
}
void add2(int id, int val){
    while(id <= n){
        tree2[id] += val;
        id += lowbit(id);
    }
}
int query2(int id){
    int res = 0;
    while(id >= 1){
        res += tree2[id];
        id -= lowbit(id);
    }
    return res;
}
int main(){
    cin >> n >> q;
    int x1, x2, y1, y2, z;
    while(q--){
        scanf("%d %d %d", &z, &x1, &y1);
        if(z == 1){
            vis2[y1]++; vis1[x1]++;
            if(vis1[x1] == 1){
                add1(x1, 1);
            }
            if(vis2[y1] == 1){
                add2(y1, 1);
            }
        }
        if(z == 2){
            vis1[x1]--; vis2[y1]--;
            if(!vis1[x1]) add1(x1, -1);
            if(!vis2[y1]) add2(y1, -1);
        }
        if (z == 3){
            scanf("%d %d", &x2, &y2);
            if (query1(x2) - query1(x1 - 1) == x2 - x1 + 1 || query2(y2) - query2(y1 - 1) == y2 - y1 + 1) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        // cout << "hang:   ";
        // cout << query1(1) << ' ';
        // for (int i = 2; i <= n; i++){
        //     cout << query1(i) - query1(i - 1) << ' ';
        // }
        // cout << endl;
        // cout << "lie:    ";
        // cout << query2(1) << ' ';
        // for (int i = 2; i <= n; i++){
        //     cout << query2(i) - query2(i - 1) << ' ';
        // }
        // cout << endl;
    }
    // system("pause");
    return 0;
}