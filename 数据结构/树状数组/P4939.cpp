#include <bits/stdc++.h>
using namespace std;
const int maxn = 5 * 1e5 + 5;
int a[maxn], tree[maxn], t[maxn];
int n;
int lowbit(int x) {return x & (-x);}
void change(int id, int val){
    while (id <= n){
        tree[id] += val;
        id += lowbit(id);
    }
}
int ask(int id){
    int res = 0;
    while (id >= 1){
        res += tree[id];
        id -= lowbit(id);
    }
    return res;
}
int main(){
    int m;
    cin >> n >> m;
    int x, y, z;
    while (m--){
        cin >> x >> y;
        if (x == 0){
            cin >> z;
            change(y, 1);
            change(z + 1, -1);
        }
        else if (x == 1){
            cout << ask(y) << endl;
        }
    }
    system("Pause");
    return 0;
}