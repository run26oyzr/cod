#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
map <int, string> book;
struct Node{
    int val, rnd;
    int size;
    int ch[2];
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
void update(int id){
    t[id].size = 1 + t[t[id].ch[0]].size + t[t[id].ch[1]].size;
}
/*
    <= val: x
    > val : y
*/
void split(int id, int val, int &x, int &y){//x小y大 bst
    if (!id) return (void)(x = y = 0);
    if (t[id].val <= val){ //id 以及 id 的左子都是x的
        x = id;
        split(t[x].ch[1], val, t[x].ch[1], y);
        // update(x);
    }
    else{
        y = id;
        split(t[y].ch[0], val, x, t[y].ch[0]);
        // update(y);
    }
    update(id);
}
/*

    void splitk(int id, int k, int &x, int &y){
        if (!id) return (void)(x = y = 0);
        int lsize = t[t[id].ch[0]].size;
        if (k <= lsize)
            y = id, splitk(t[y].ch[0], k, x, t[y].ch[0]);
        else
            x = id, splitk(t[x].ch[1], k - lsize - 1, t[x].ch[1], y);
        update(id);
    }
*/
int merge(int x, int y){
    if (!x || !y) return x + y;
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
int rt = 0;
void insert(int val, int z){
    int x, y;
    split(rt, val, x, y);
    rt = merge(merge(x, newNode(z)), y);
}
void query(int val){
    int x, y, z;
    split(rt, val, x, y);
    split(rt, val - 1, x, z);
    cout << book[t[z].val] << endl;
    rt = merge(merge(x, z), y);
}
int main(){
    /*
        //insert val
        int x, y;
        split(rt, val, x, y);
        rt = merge(merge(x, newNode(val)), y);

        //del val
        split(rt, val, y, z);
        split(y, val - 1, x, y);
        y = merge(t[y].ch[0], t[y].ch[1]);
        rt = merge(merge(x, y), z);

        //rank val
        split(rt, val - 1, x, y);
        k = t[x].size + 1;
        merge(x, y);
    */
    int n;
    cin >> n;
    string s;
    for (int i = 1; i <= n; i++){
        cin >> s;
        insert(i - 1, tot + 1);
        book[tot] = s;
    }
    int m;
    cin >> m;
    int x;
    for (int i = 1; i <= m; i++){
        cin >> s >> x;
        insert(x, tot + 1);
        book[tot] = s;
    }
    for (int i = 0; i < m + n; i++){
        query(i);
    }
    // int q;
    // cin >> q;
    // for (int i = 1; i <= q; i++){
    //     cin >> x;
    //     query(x);
    // }
    system("pause");
    return 0;
}