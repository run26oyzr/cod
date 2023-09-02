#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5, maxlog = 17;
struct Segment_Tree{
	int tot = 0;
	struct Node{
		int lson, rson;
		int size;
	}t[maxn * maxlog * maxlog * 2];
	int newNode(){
		++tot;
        // t[tot].size = 1;
		return tot;
	}
	void update(int id){
		t[id].size = t[t[id].lson].size + t[t[id].rson].size;
	}
	void change(int &id, int L, int R, int pos, int c){
        if (!id)
            id = newNode();
		if (L == pos && R == pos){
			t[id].size += c;
			return;
		}
		int mid = (L + R) >> 1;
		if (pos <= mid)
			change(t[id].lson, L, mid, pos, c);
		else
			change(t[id].rson, mid + 1, R, pos, c);
		update(id);
	}
    int kth(int rtl[], int totl, int rtr[], int totr, int L, int R, int k){
		if (L == R){
			return L;
		}
        int lsize = 0;
        for (int i = 1; i <= totl; i++)
            lsize -= t[t[rtl[i]].lson].size;
        for (int i = 1; i <= totr; i++)
            lsize += t[t[rtr[i]].lson].size;
        int mid = (L + R) >> 1;
        if (k <= lsize){
            for (int i = 1; i <= totl; i++)
                rtl[i] = t[rtl[i]].lson;
            for (int i = 1; i <= totr; i++)
                rtr[i] = t[rtr[i]].lson;
            return kth(rtl, totl, rtr, totr, L, mid, k);
        }else{
            for (int i = 1; i <= totl; i++)
                rtl[i] = t[rtl[i]].rson;
            for (int i = 1; i <= totr; i++)
                rtr[i] = t[rtr[i]].rson;
            return kth(rtl, totl, rtr, totr, mid + 1, R, k - lsize);
        }
	}
    int rank(int rtl[], int totl, int rtr[], int totr, int L, int R, int val){
		if (L == R){
			return 1;
		}
        int mid = (L + R) >> 1;
        if (val <= mid){
            for (int i = 1; i <= totl; i++)
                rtl[i] = t[rtl[i]].lson;
            for (int i = 1; i <= totr; i++)
                rtr[i] = t[rtr[i]].lson;
            return rank(rtl, totl, rtr, totr, L, mid, val);
        }else{
            int lsize = 0;
            for (int i = 1; i <= totl; i++)
                lsize -= t[t[rtl[i]].lson].size;
            for (int i = 1; i <= totr; i++)
                lsize += t[t[rtr[i]].lson].size;
            for (int i = 1; i <= totl; i++)
                rtl[i] = t[rtl[i]].rson;
            for (int i = 1; i <= totr; i++)
                rtr[i] = t[rtr[i]].rson;
            return rank(rtl, totl, rtr, totr, mid + 1, R, val) + lsize;
        }
	}
}Tree;
int n;
struct Binary_Indexed_Tree{
    int rt[maxn];
    int lowbit(int x){return x & (-x);}
    void change(int id, int pos, int val){
        while (id <= n){
            Tree.change(rt[id], 0, 1e9, pos, val);
            id += lowbit(id);
        }
    }
    int rtl[maxlog], rtr[maxlog];
    int kth(int l, int r, int k){
        if (k == 0) 
            return -2147483647;
        if (k > r - l + 1)
            return 2147483647;
        int totl = 0, totr = 0;
        for (int i = l - 1; i; i -= lowbit(i))
            rtl[++totl] = rt[i];
        for (int i = r; i; i -= lowbit(i))
            rtr[++totr] = rt[i];
        return Tree.kth(rtl, totl, rtr, totr, 0, 1e9, k);
    }
    int rank(int l, int r, int val){
        int totl = 0, totr = 0;
        for (int i = l - 1; i; i -= lowbit(i))
            rtl[++totl] = rt[i];
        for (int i = r; i; i -= lowbit(i))
            rtr[++totr] = rt[i];
        return Tree.rank(rtl, totl, rtr, totr, 0, 1e9, val);
    }
}BIT;
int a[maxn];
int main(){
    int m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        BIT.change(i, a[i], 1);
    } 
    char opt;
    int l, r, pos, k;
    while (m--){
        cin >> opt;
        if (opt == 'Q'){
            scanf("%d %d %d", &l, &r, &k);
            cout << BIT.kth(l, r, k) << endl;
        }else if (opt == 'C'){
            scanf("%d %d", &pos, &k);
            BIT.change(pos, a[pos], -1);
            BIT.change(pos, k, 1);
            a[pos] = k;
        }
    }
    return 0;
}