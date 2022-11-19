#include <bits/stdc++.h>
using namespace std;
#define ls t[id].ch[0]
#define rs t[id].ch[1]
const int maxn = 1e5 + 5;
int a[maxn];
struct Node{
    int val, rnd;
    int size;
    int ch[2];
    int rev;
    int mina;
}t[maxn << 1];
int tot = 0;
int newNode(int val){
    ++tot;
    t[tot].size = 1;
    t[tot].rnd = rand();
    t[tot].val = val;
    t[tot].ch[0] = t[tot].ch[1] = 0;
    t[tot].mina = val;
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
    t[id].mina = t[id].val;
    if(t[id].ch[0]) t[id].mina = min(t[id].mina, t[t[id].ch[0]].mina);
    if(t[id].ch[1]) t[id].mina = min(t[id].mina, t[t[id].ch[1]].mina);
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
void reverse(int l, int r){
    int x, y, z;
    splitk(rt, l - 1, x, y);
    splitk(y, r - l + 1, y, z);
    t[y].rev ^= 1;
    rt = merge(merge(x, y), z);
}
int query(){
	int id = rt;
	int res = 1;
	while(id){
		int lsize = t[ls].size;
		if (ls && t[ls].mina == t[id].mina) id = ls;
		else if (rs && t[rs].mina == t[id].mina) id = rs, res += lsize + 1;
		else return res + lsize;
	}
}
void insert(int val){
    rt = merge(rt, newNode(val));
}
void inorder(int id){
    if (!id) return;
    inorder(ls);
    cout << t[id].val << ' ';
    inorder(rs);
}
int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
    	cin >> a[i];
        insert(a[i]);
    }
    for (int i = 1; i <= n; i++){
    	int val = query();
        // cout << val << endl;
        cout << val + i - 1 << ' ';
		reverse(1, val);
        int x, y;
        splitk(rt, 1, x, y);
        rt = y;
        // inorder(rt);
        // cout << endl;
    }
    system("pause");
    return 0;
}
