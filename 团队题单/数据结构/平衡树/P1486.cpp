#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5 + 5;
struct Node{
    int val, rnd;
    int size;
    int ch[2];
}t[maxn << 1];
int tot = 0;
int delta = 0;
int leaved = 0; 
int newNode(int val){
    ++tot;
    t[tot].size = 1;
    t[tot].rnd = rand();
    t[tot].val = val;
    t[tot].ch[0] = t[tot].ch[1] = 0;
    return tot;
}
void update(int id){
    t[id].size = 1 + t[t[id].ch[0]].size + t[t[id].ch[1]].size;
}
void split(int id, int val, int &x, int &y){
    if (!id) return (void)(x = y = 0);
    if (t[id].val <= val){
        x = id;
        split(t[x].ch[1], val, t[x].ch[1], y);
    }
    else{
        y = id;
        split(t[y].ch[0], val, x, t[y].ch[0]);
    }
    update(id);
}
int merge(int x, int y){
    if (!x || !y) return x + y;
    if (t[x].rnd <= t[y].rnd){
        t[x].ch[1] = merge(t[x].ch[1], y);
        update(x);
        return x;
    }
    else{
        t[y].ch[0] = merge(x, t[y].ch[0]);
        update(y);
        return y;
    }
}
int rt = 0;
void insert(int val){
    int x, y;
    split(rt, val, x, y);
    rt = merge(merge(x, newNode(val)), y);
}
void del(int val){
    int x, y, z;
    split(rt, val, y, z);
    split(y, val - 1, x, y);
    leaved += t[x].size;
    rt = merge(y, z);
}
int kth(int k){
    int id = rt;
    while(id){
        int lsize = t[t[id].ch[0]].size;
        if (k <= lsize) id = t[id].ch[0];
        else if (k > lsize + 1) id = t[id].ch[1], k = k - lsize - 1;
        else return t[id].val;
    }
}
signed main(){
    int n, m;
    cin >> n >> m;
    char c;
    int x;
    int ans;
    while(n--){
        cin >> c >> x;
        if (c == 'I') insert(x - delta);
        if (c == 'A') delta += x;
        if (c == 'S') {
            delta -= x;
            del(m - delta);
        }
        if (c == 'F') {
            if (x > tot - leaved) cout << -1 << endl;
            else cout << kth(tot - leaved - x + 1) + delta << endl;
        }
    }
    cout << leaved;
    system("pause");
    return 0;
}