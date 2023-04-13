#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
template<typename T> inline void read(T &x){
	x = 0;
	bool F = 0;
	char c = getchar();
	for (;!isdigit(c);c = getchar()) if (c == '-') F = 1;
	for (;isdigit(c);c = getchar()) x = (x<<1)+(x<<3)+(c^48);
	if (F) x = -x;
}
struct Node{
    int val, rnd;
    int size;
    int ch[2];
    int lazy;
}t[maxn << 1];
int tot = 0;
int newNode(int val){
    ++tot;
    t[tot].size = 1;
    t[tot].lazy = 0;
    t[tot].rnd = rand();
    t[tot].val = val;
    t[tot].ch[0] = t[tot].ch[1] = 0;
    return tot;
}
void pushdown(int id){
	t[t[id].ch[0]].lazy += t[id].lazy;
	t[t[id].ch[0]].val += t[id].lazy;
	t[t[id].ch[1]].lazy += t[id].lazy;
	t[t[id].ch[1]].val += t[id].lazy;
	t[id].lazy = 0;
}
void update(int id){
    t[id].size = 1 + t[t[id].ch[0]].size + t[t[id].ch[1]].size;
}
void split(int id, int val, int &x, int &y){
    if (!id) return (void)(x = y = 0);
    pushdown(id);
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
//    pushdown(x); pushdown(y);
    if (t[x].rnd <= t[y].rnd){
    	pushdown(x);
        t[x].ch[1] = merge(t[x].ch[1], y);
        update(x);
        return x;
    }
    else{
    	pushdown(y);
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
    int x, y;
    split(rt, val, x, y);
    rt = y;
}
int kth(int k){
    int id = rt;
    while(id){
    	pushdown(id); 
        int rsize = t[t[id].ch[1]].size;
//    	cout << "kth---" << id << ' ' << rsize << ' ' << k << ' ' << t[id].val << endl;
        if (k <= rsize) id = t[id].ch[1];
        else if (k > rsize + 1) id = t[id].ch[0], k = k - rsize - 1;
        else return t[id].val;
    }
}
signed main(){
	srand(time(0));
    int n, m;
   	read(n); read(m);
    int opt, x, val;
    for (int i = 1; i <= n; i++){
    	read(x);
    	insert(x);
	}
    while(m--){
        read(opt);
		int x_, y_, z_;
		if (opt == 1){
			read(x); read(val);
			split(rt, x, x_, y_);
			t[x_].lazy = -val;
			t[x_].val -= val;
			rt = merge(x_, y_);
		}else if (opt == 2){
			read(x); read(val);
			split(rt, x - 1, x_, y_);
			t[y_].lazy = val;
			t[y_].val += val;
			rt = merge(x_, y_);	
		}else if (opt == 3){
			read(x);
			insert(x);
		}else if (opt == 4){
			read(x);
			del(x);
		}else if (opt == 5){
			read(x);
			cout << kth(x) << '\n';
		}else if (opt == 6){
			cout << t[rt].size << '\n';
//			cout << "output---" << t[rt].size << endl;
		} 
//		for (int i = 1; i <= tot; i++){
//			cout << kth(i) << ' ';
//		}
//		cout << endl;
    }
    return 0;
}