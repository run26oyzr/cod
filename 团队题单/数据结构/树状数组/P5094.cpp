#include <bits/stdc++.h>
using namespace std;
const int maxn = 5 * 1e4 + 5;
int n;
int tree[maxn], tree2[maxn];
struct node{
    int pos, v;
    bool operator < (const node T)const{
        return T.v < v;
    } 
}t[maxn];
int lowbit(int x) {return x & (-x);}
void add (int id, int val = 1){
    while (id <= n){
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
void add2(int id, int val){
    while (id <= n){
        tree2[id] += val;
        id += lowbit(id);
    }
}
int sum2(int id){
    int res = 0;
    while (id >= 1){
        res += tree2[id];
        id -= lowbit(id);
    }
    return res;
}
int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> t[i].v >> t[i].pos;
    }
    sort(t + 1, t + n + 1);
    long long ans = 0;
    long long sum_pre = 0;
    for (int i = 1; i <= n; i++){
        int a = sum(t[i].pos);
        int b = sum2(t[i].pos);
        ans += (a * t[i].pos - b) * t[i].v;
        ans += ((sum_pre - b) - (i - a - 1) * t[i].pos) * t[i].v;
        sum_pre += t[i].pos;
        add(t[i].pos);
        add2(t[i].pos, t[i].pos);
    }
    cout << ans;
    system("Pause");
    return 0;
}