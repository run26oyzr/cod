#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 30005;
int v[maxn], a[maxn], tree[maxn], l[maxn], r[maxn];
int n;
int lowbit(int x) {return x & (-x);}//
void add (int id){
    while (id <= n){
        tree[id] ++;
        id += lowbit(id);
    }
}//
int sum(int id){
    int res = 0;
    while (id >= 1){
        res += tree[id];
        id -= lowbit(id);
    }
    return res;
}//
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){cin>>a[i];v[i]=a[i];}
    int m=unique(v+1,v+n+1)-v-1;
	sort(v+1,v+n+1);
    for(int i=1;i<=n;i++) a[i]=lower_bound(v+1,v+1+m,a[i])-v;
    int ans=0;
    for(int i=1;i<=n;i++){
		l[i]=sum(a[i]-1);
		add(a[i]);    	
	}
	memset(tree, 0, sizeof(tree));
	for(int i=n;i>=1;i--){
		r[i]=sum(n-a[i]);
		add(n+1-a[i]);
	}
    for (int i = 2; i <= n - 1; i++) ans += l[i] * r[i];
    cout << ans;
}
