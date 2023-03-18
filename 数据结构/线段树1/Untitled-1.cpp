#include <bits/stdc++.h>
#define lson (id << 1)
#define rson (id << 1 | 1)
using namespace std;
const int maxn = 1e5;
struct node{
    int left, right;
    int lazy, sum;
}t[maxn];
int len(int id) {return t[id].right = t[id].left;}
void update(int id){
    t[id].sum = t[lson].sum + t[lson].lazy * len(lson)
               +t[rson].sum + t[rson].lazy * len(rson);
}
void build(int id, int L, int R){
    t[id].left = L, t[id].right = R, t[id].lazy = 0;
    if (L == R) t[id].sum = a[L];
    int mid = (L + R) >> 1;
    build(lson, L, mid);
    build(rson, mid + 1, R);
}
void pushdown(int id){
    if (t[id].lazy != 0){
        t[lson].lazy += t[id].lazy; 
        t[rson].lazy += t[id].lazy;
        t[id].sum += t[id].lazy * len(id);
        t[id].lazy = 0;
    }
}
void change(int id, int L, int R, int val){
    if (t[id].left == L && t[id].right == R){
        t[id].lazy += val;
    }
    pushdown(id);
    if (R <= t[lson].right) change(lson, L, R, val);
    else if (L >= t[rson].left) change(rson, L, R, val);
    else{
        change(lson, L, t[lson].right, val);
        change(rson, t[rson].left, R, val);
    }
    update(id);
}
int query(int id, int L, int R){
    if (t[id].left == L && t[id].right == R){
        return t[id].sum + t[id].lazy * len(id);
    }
    pushdown(id);
    if (R <= t[lson].right) return query(lson, L, R);
    else if (L >= t[rson].left) return query(rson, L, R);
    else{
        return query(lson, L, t[lson].right) + query(rson, t[rson].left, R);
    }
}
int main(){

    return 0;
}