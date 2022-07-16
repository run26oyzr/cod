#include <bits/stdc++.h>
using namespace std;
const int maxn = 5 * 1e5 + 5;
int n, m;
int tree[maxn], c[maxn];
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
    cin >> n >> m;
    int x, y, z;
    for (int i = 1; i <= n; i++) {cin >> x; add(i, x);}
    while (m--){
        cin >> x >> y >> z;
        if (x == 1){
            add(y, z);
        }
        else if (x == 2){
            cout << sum(z) - sum(y - 1) << endl;
        }
    }
    system("Pause");
}