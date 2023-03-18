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
    int x, y;
    while (m--){
        cin >> x >> y;
        change(x, 1);
        change(y + 1, -1);
    }
    for (int i = 1; i <= n; i++){
        if (ask(i) != 1){
            cout << i << ' ' << ask(i);
            system("Pause");
            return 0;
        }
    }
    cout << "OK";
    system("Pause");
    return 0;
}