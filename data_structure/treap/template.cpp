#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
struct Node{
	int size, val;
	int cnt;
	int rnd;
	int ch[2];
}t[maxn];
int tot;
int newNode(int val){
	++tot;
	t[tot].size = t[tot].cnt = 1;
	t[tot].rnd = rand();
	t[tot].val = val;
	return tot;
}
void update(int id){
	t[id].size = t[id].cnt + t[t[id].ch[0]].size + t[t[id].ch[1]].size;
}
//k:0左子 k:1右子 
void rotate(int &id, int k){
	int son = t[id].ch[k];
	t[id].ch[k] = t[son].ch[k ^ 1];
	t[son].ch[k ^ 1] = id;
	
	update(id);
	id = son;
	update(id);
}

void insert(int &id, int val){
	if (!id){
		id = newNode(val);
		return;
	}
	if (t[id].val == val) t[id].cnt++;
	else {
		int k = val > t[id].val;
		insert(t[id].ch[k], val);
		if (t[id].rnd > t[t[id].ch[k]].rnd)
			rotate(id, k);
	}
	update(id);
}
void del(int &id, int val){
	if (!id) return;
	if (t[id].val == val){
		if (t[id].cnt > 1) {t[id].cnt--; t[id].size--; return;}
		if (!t[id].ch[0] || !t[id].ch[1]) id = t[id].ch[0] + t[id].ch[1];
		int k = t[t[id].ch[0]].rnd > t[t[id].ch[1]].rnd;
		rotate(id, k);
		del(id, val);
	}
	else{
		t[id].size--;
		int k = val > t[id].val;
		del(t[id].ch[k], val);
	}
}
int rt = 0;
int rank_(int id, int val){ //排名 
	if (!id) return 1;
	int lsize = t[t[id].ch[0]].size;
	if (t[id].val == val) return lsize + 1;
	if (val < t[id].val) return rank_(t[id].ch[0], val);
	return lsize + t[id].cnt + rank_(t[id].ch[1], val);
}
int kth(int id, int k){ //val
	if (!id || k < 0 || t[id].size < k) return 0; //最小的数
	int lsize;
	if (k <= lsize) return kth(t[id].ch[0], k);
	if (k > lsize + t[id].cnt) return kth(t[id].ch[1], k - lsize + t[id].cnt);
	else return t[id].val;
}
int main(){
    /*
        前驱 kth(rt, rank(rt, val) - 1);
        后继 kth(rt, rank(rt, val + 1)); 
    */
    int n;
    cin >> n;
    int opt, x;
    int root = 0;
    while(n--){
        cin >> opt >> x;
        if (opt == 1) insert(root, x);
        if (opt == 2) del(root, x);
        if (opt == 3) cout << rank_(root, x) << endl;
        if (opt == 4) cout << kth(root, x) << endl;
        if (opt == 5) cout << kth(root, rank_(root, x) - 1) << endl;
        if (opt == 6) cout << kth(root, rank_(root, x + 1)) << endl;
    }
    system("pause");
	return 0;
}
