#include <bits/stdc++.h>
using namespace std;
const int maxn = 5 * 1e5 + 5;
int rt[maxn];
struct Persistant_Treap{
    struct Node{
        int val, rnd;
        int size;
        int ch[2];
    }t[40 * maxn];
    int tot = 0;
    int newNode(int val){
        ++tot;
        t[tot].size = 1;
        t[tot].rnd = rand();
        t[tot].val = val;
        t[tot].ch[0] = t[tot].ch[1] = 0;
        return tot;
    }
    int copyNode(int p){
        ++tot;
        t[tot] = t[p];
        return tot;
    }
    void update(int id){
        t[id].size = 1 + t[t[id].ch[0]].size + t[t[id].ch[1]].size;
    }
    void split(int id, int val, int &x, int &y){
        if (!id) return (void)(x = y = 0);
        if (t[id].val <= val){
            x = copyNode(id);
            split(t[x].ch[1], val, t[x].ch[1], y);
            update(x);
        }
        else{
            y = copyNode(id);
            split(t[y].ch[0], val, x, t[y].ch[0]);
            update(y);
        }
    }
    int merge(int x, int y){
        if (!x || !y) return x + y;
        if (t[x].rnd < t[y].rnd){
            t[x].ch[1] = merge(t[x].ch[1], y);
            update(x);
            return x;
        }
        else{
            t[y].ch[0] = merge(x, t[y].ch[0]); //x 要写在前面！！！
            update(y);
            return y;
        }
    }
    void insert(int &root, int val){
        int x = 0, y = 0;
        split(root, val, x, y);
        root = merge(merge(x, newNode(val)), y);
    }
    void del(int &root, int val){
        int x = 0, y = 0, z = 0;
        split(root, val, y, z);
        split(y, val - 1, x, y);
        y = merge(t[y].ch[0], t[y].ch[1]);
        root = merge(merge(x, y), z);
    }
    int rank_(int &root, int val){
        int x = 0, y = 0;
        split(root, val - 1, x, y);
        int k = t[x].size + 1;
        root = merge(x, y);
        return k;
    }
    int kth(int &root, int k){
        int id = root;
        if (k == 0)
            return -2147483647;
        if (k > t[id].size)
            return 2147483647;
        while(id){
            int lsize = t[t[id].ch[0]].size;
            if (k <= lsize) id = t[id].ch[0];
            else if (k > lsize + 1) id = t[id].ch[1], k = k - lsize - 1;
            else return t[id].val;
        }
        return 0;
    }
    int pre(int &root, int val){
        return kth(root, rank_(root, val) - 1);
    }
    int nxt(int &root, int val){
        return kth(root, rank_(root, val + 1));
    }
    void inorder(int root){
        if (!root) return;
        inorder(t[root].ch[0]);
        cout << t[root].val << ' ';
        inorder(t[root].ch[1]);
    }
}treap;
int main(){
    srand(time(0));
    int n;
    cin >> n;
    int ver, op, x;
    rt[0] = 0;
    for (int i = 1; i <= n; i++){
        cin >> ver >> op >> x;
        rt[i] = rt[ver];
        if (op == 1)
            treap.insert(rt[i], x);
        else if (op == 2)
            treap.del(rt[i], x);
        else if (op == 3)
            cout << treap.rank_(rt[ver], x) << endl;
        else if (op == 4)
            cout << treap.kth(rt[ver], x) << endl;
        else if (op == 5)
            cout << treap.pre(rt[ver], x) << endl;
        else if (op == 6)
            cout << treap.nxt(rt[ver], x) << endl;
    }
    return 0;
}