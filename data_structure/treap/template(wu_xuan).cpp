#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
struct Node{
    int val, rnd;
    int size;
    int ch[2];
}t[maxn << 1];
int tot = 0, rt = 0;
int newNode(int val){
    ++tot;
    t[tot].size = 0;
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
        split(t[id].ch[1], val, t[id].ch[1], y);
        // update(x);
    }
    else{
        y = id;
        split(t[id].ch[0], val, x, t[id].ch[0]);
        // update(y);
    }
    update(id);
}
int merge(int x, int y){
    if (!x || !y) return x + y;
    if (t[x].rnd < t[y].rnd){ //heap
        t[x].ch[1] = merge(t[x].ch[1], y);
        update(x);
        return x;
    }
    else{
        t[y].ch[0] = merge(t[y].ch[0], x);
        update(y);
        return y;
    }
}
void insert(int val){
    int x, y;
    split(rt, val, x, y);
    rt = merge(merge(x, newNode(val)), y);
}
void del(int val){
    int x, y, z;
    split(rt, val, y, z);
    split(y, val - 1, x, y);
    y = merge(t[y].ch[0], t[y].ch[1]);
}
int rank_(int val){
    int x, y;
    split(rt, val - 1, x, y);
    int k = t[x].size + 1;
    merge(x, y);
    return k;
}
int kth(int id, int k){
    while(id){
        int lsize = t[t[id].ch[0]].size;
        if (k <= lsize) id = t[id].ch[0];
        else if (k > lsize + 1) id = t[id].ch[1];
        else return t[id].val;
    }
}
int pre(int val){
    return kth(rt, rank_(val) - 1);
}
int hou_ji(int val){
    return kth(rt, rank_(val + 1));
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
    return 0;
}