#include <bits/stdc++.h>
#define int unsigned long long
#define ls (t[id].ch[0])
#define rs (t[id].ch[1])
using namespace std;
const int maxn = 1e5 + 5;
const int base = 131;
int base_pow[maxn];
void init(){
    base_pow[0] = 1;
    for (int i = 1; i < maxn; i++)
        base_pow[i] = base_pow[i - 1] * base;
}
struct Node{
    int rnd, size;
    int ch[2];
    int val, Hash;
}t[maxn << 1];
int tot = 0;
int newNode(int val){
    ++tot;
    t[tot].size = 1;
    t[tot].rnd = rand();
    t[tot].val = val;
    t[tot].ch[0] = t[tot].ch[1] = 0;
    t[tot].Hash = val;
    return tot;
}
void update(int id){
    t[id].size = 1 + t[ls].size + t[rs].size;
    t[id].Hash = t[ls].Hash * base_pow[t[rs].size + 1] + t[id].val * base_pow[t[rs].size] + t[rs].Hash;
}
void splitk(int id, int k, int &x, int &y){
    if (!id) return (void)(x = y = 0);
    int lsize = t[ls].size;
    if (k <= lsize)
        y = id, splitk(t[y].ch[0], k, x, t[y].ch[0]);
    else
        x = id, splitk(t[x].ch[1], k - lsize - 1, t[x].ch[1], y);
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
void inorder(int id){
    if (!id) return;
    if (t[id].ch[0]) inorder(t[id].ch[0]);
    cout << (char)(t[id].val) << ' ';
    if (t[id].ch[1]) inorder(t[id].ch[1]);
}
int rt = 0;
int a, b, c;
char s[maxn];
int get_Sub(int l, int r){
    splitk(rt, l - 1, a, b);
    splitk(b, r - l + 1, b, c);
    // cout << l << ' ' << r << ' ' << t[b].size << ' ' << t[b].Hash << endl;
    int res = t[b].Hash;
    rt = merge(merge(a, b), c);
    return res;
}
signed main(){
    init();
    int n, m;
    cin >> s + 1;
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++)
        rt = merge(rt, newNode(s[i]));
    cin >> m;
    char op, C;
    int x, y;
    while (m--){
        cin >> op;
        if (op == 'Q'){
            cin >> x >> y;
            if (x > y)
                swap(x, y);
            int l = 0, r = t[rt].size - y + 1, ans;
            while (l < r){
                int mid = (l + r + 1) / 2;
                if (get_Sub(x, x + mid - 1) == get_Sub(y, y + mid - 1))
                    l = mid;
                else r = mid - 1;
            }
            cout << l << endl;
        }else if (op == 'R'){
            cin >> x >> C;           
            splitk(rt, x - 1, a, b);
            splitk(b, 1, b, c);
            t[b].val = C; t[b].Hash = C;
            rt = merge(merge(a, b), c);
        }else if (op == 'I'){
            cin >> x >> C;
            splitk(rt, x, a, b);
            rt = merge(merge(a, newNode(C)), b);
        }
    }
    return 0;
}