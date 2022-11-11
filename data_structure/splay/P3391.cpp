#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
struct Node{
    int val, rnd;
    int size;
    int ch[2];
    int rev;
}t[maxn << 1];
int tot = 0;
int newNode(int val){
    ++tot;
    t[tot].size = 1;
    t[tot].rnd = rand();
    t[tot].val = val;
    t[tot].ch[0] = t[tot].ch[1] = 0;
    return tot;
}
void pushdown(int id){
    if (t[id].rev){
        swap(t[id].ch[0], t[id].ch[1]);
        t[t[id].ch[0]].rev ^= 1;
        t[t[id].ch[1]].rev ^= 1;
        t[id].rev = 0;
    }
}
void update(int id){
    t[id].size = 1 + t[t[id].ch[0]].size + t[t[id].ch[1]].size;
}
void splitk(int id, int k, int &x, int &y){
    if (!id) return (void)(x = y = 0);
    pushdown(id);
    int lsize = t[t[id].ch[0]].size;
    if (k <= lsize)
        y = id, splitk(t[y].ch[0], k, x, t[y].ch[0]);
    else
        x = id, splitk(t[x].ch[1], k - lsize - 1, t[x].ch[1], y);
    update(id);
}
int merge(int x, int y){
    if (!x || !y) return x + y;
    pushdown(x); pushdown(y);
    if (t[x].rnd <= t[y].rnd){ //heap
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

void inorder(int id){
    if (!id) return;
    pushdown(id);
    if (t[id].ch[0]) inorder(t[id].ch[0]);
    cout << t[id].val << ' ';
    if (t[id].ch[1]) inorder(t[id].ch[1]);
}
int rt = 0;
void reverse(int l, int r){
    int x, y, z;
    splitk(rt, l - 1, x, y);
    splitk(y, r - l + 1, y, z);
    t[y].rev ^= 1;
    rt = merge(merge(x, y), z);
}
void insert(int val){
    rt = merge(rt, newNode(val));
}
int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        insert(i);
    }
    int x, y;
    for (int i = 1; i <= m; i++){
        cin >> x >> y;
        reverse(x, y);
        // for (int i = 1; i <= n; i++){
        //     cout << kth(i) << ' ';
        // }
        // cout << endl;
    }
    inorder(rt);
    system("pause");
    return 0;
}