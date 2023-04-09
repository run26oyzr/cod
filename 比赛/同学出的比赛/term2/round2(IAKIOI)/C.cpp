//treap板子忘了，自求多福…… 
#include <bits/stdc++.h>
#define ls t[id].lson
#define rs t[id].rson
using namespace std;
const int maxn = 1e5 + 5;
struct Node{
	int size, lson, rson;
	int lazy, val;
}t[maxn << 2];
int tot = 0;
int newNode(int x){
	++tot;
	t[tot].size = 1;
	t[tot].lazy = 0;
	t[tot].val = x;
	return tot;
}
void pushdown(int id){
	t[id].size = t[ls].size + t[rs].size;
	t[id].val = t[ls].val + t[rs].val;
}
void update(int id){
	t[ls].lazy = t[id].lazy;
	t[ls].val += t[id].lazy;
	t[rs].lazy = t[id].lazy;
	t[rs].val += t[id].lazy;
	t[id].lazy = 0;
}
int merge(int x, int y){//假设x的rnd<y的 
	pushdown(x); pushdown(y);
	if (t[x].val <= t[y].val){
		t[x].rson = merge(t[x].rson, y); update(x);
	}else{
		t[x].lson = merge(t[x].lson, y); update(x);
	}
	return x;
}
int split(int &x, int &y, int val){
	if (t[x].val < val){
		x = split(t[x].rson, y, val);
	}else{
		y = split(t[x].lson, y, val);
	}
}
int rt = 1, x, y;
int kth(int k){
	int id = rt;
	while(k){
		int lsize = t[ls].size;
		if (k < lsize) id = ls;
		else if (k > lsize + 1) id = rs;
		else return t[id].val;
	}
}
void add(int val){
	split(x, y, val);
	rt = merge(merge(x, newNode(val)), y);
}
int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++){
		int x;
		scanf("%d", &x);
		add(x);
	}
	int opt, x1, y1;
	while(m--){
		scanf("%d", &opt);
		if (opt == 1){
			scanf("%d %d", &x1, &y1);
			split(x, y, y1);
			t[x].lazy = y1;
			rt = merge(x, y);
		}else if(opt == 2){
			scanf("%d %d", &x1, &y1);
			split(x, y, y1 - 1);
			t[y].lazy = y1;
			rt = merge(x, y);
		}else if(opt == 3){
			scanf("%d", &x1);
			split(x, y, x1);
			rt = merge(merge(x, newNode(x1)), y);
		}else if(opt == 4){
			scanf("%d", &x1);
			split(x, y, x1);
			rt = y;
		}else if(opt == 5){
			scanf("%d", &x1);
			printf("%d\n", kth(x1));
		}else if(opt == 6){
			printf("%d\n", t[rt].size);
		}
	}
	return 0;
}
/**
 *treap:左小右大，上小下大 
 *treap的struct:
 * size, lazy, val, lson, rson
*/