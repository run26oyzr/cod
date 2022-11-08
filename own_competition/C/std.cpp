#include<bits/stdc++.h>
#define int long long
#define ls s[o][0]
#define rs s[o][1]
using namespace std;
inline int read(){
	register int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*f;
}
const int maxn=114514,mod=998244353;
int h[maxn],a[maxn],sz[maxn],cnt[maxn],s[maxn][2],tot,rt,p;
namespace treap{
	void pushup(int o){
		sz[o]=sz[ls]+sz[rs]+cnt[o];
	}
	void rotate(int &o,int k){
		int p=s[o][k^1];
		s[o][k^1]=s[p][k];
		s[p][k]=o;
		pushup(o);
		pushup(o=p);
	}
	void insert(int &o,int v){
		if(!o){
			o=++tot;
			sz[o]=1;
			cnt[o]=1;
			a[o]=v;
			h[o]=rand();
			s[o][0]=s[o][1]=0;
			return;
		}
		else sz[o]++;
		if(a[o]==v) return cnt[o]++,void();
		int k=v>a[o];
		insert(s[o][k],v);
		if(h[o]<h[s[o][k]]) rotate(o,k^1);
		pushup(o);
	}
	int rk(int o,int v){
		if(!o) return 0;
		if(v<a[o]) return rk(ls,v);
		if(a[o]==v) return sz[ls]+1;
		return sz[ls]+cnt[o]+rk(rs,v);
	}
	int sub(int o,int v){
		if(!o) return 0x3f3f3f3f;
		if(a[o]<v) return sub(rs,v);
		else return min(a[o],sub(ls,v));
	}
};
using namespace treap;
int f[maxn],fc[maxn];
struct node{
	int l,r;
	bool operator<(const node &a)const{
		return l<a.l;
	}
}b[maxn];
int qpow(int x,int y){
	int rt=1;
	for(;y;y>>=1,x=(x*x)%mod) if(y&1) rt=(rt*x)%mod;
	return rt;
}
signed main(){ 
	int n=read(),k=read(),ans=0;
	for(int i=1;i<=n;i++) b[i].l=read(),b[i].r=read();
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++){
		insert(p,b[i].r);
		if(b[i].r-b[i].l<k) continue;
		int cnt=i-rk(p,sub(p,b[i].l+k));
		ans+=cnt*(cnt-1)>>1;
		ans%=mod;
	}
	printf("%lld",ans);                    
}