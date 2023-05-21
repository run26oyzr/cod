#include<bits/stdc++.h>
#define int long long
#define F(i,a,b) for(int i=a;i<=(b);i++)
#define ls s[o][0]
#define rs s[o][1]
#define lson(k) (s[k][0])
#define rson(k) (s[k][1])
using namespace std;
inline int read(){
	register int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*f;
}
const int maxn=109125;
namespace treap{
	int a[maxn],sz[maxn],lz[maxn],h[maxn],s[maxn][2],sx[maxn],gc[maxn],tot=0,p=0;
	//a:val sz:size lz:翻转tag h:rnd s:左右子 sx:公差 gc:首项
	void pushup(int o){
		sz[o]=sz[ls]+sz[rs]+1;
	}
	void push_r(int o){
		lz[o]^=1;
		swap(ls,rs);
		sx[o]=sx[o]+gc[o]*(sz[o]-1);
		gc[o]=-gc[o];
	}
	void push_d(int o,int ss,int gg){
		gc[o]+=gg;
		sx[o]+=ss;
		a[o]+=ss+sz[ls]*gg;
	}
	void pushdown(int o){
		if(lz[o]){
			if(ls) push_r(ls);
			if(rs) push_r(rs);
			lz[o]=0;
		}
		if(gc[o]||sx[o]){
			if(ls) push_d(ls,sx[o],gc[o]);
			if(rs) push_d(rs,sx[o]+(sz[ls]+1)*gc[o],gc[o]);
			gc[o]=sx[o]=0;
		}
	}
	int add(int x){
		a[++tot]=x;
		sz[tot]=1;
		h[tot]=rand();
		return tot;
	}
	int merge(int x,int y){
		if(!x||!y) return x|y;
		if(h[x]<=h[y]){
			pushdown(x);
			s[x][1]=merge(s[x][1],y);
			pushup(x);
			return x;
		}
		else{
			pushdown(y);
			s[y][0]=merge(x,s[y][0]);
			pushup(y);
			return y;
		}
	}
	void split(int o,int v,int &x,int &y){
		if(!o) return x=y=0,void();
		pushdown(o);
		if(sz[ls]<v){
			x=o;
			split(rs,v-sz[ls]-1,rs,y);
			pushup(o);
			return;
		}
		y=o;
		split(ls,v,x,ls);
		pushup(o);
	}
	void solve(int o){
		if(!o) return;
		pushdown(o);
		solve(ls);
		printf("%lld ",a[o]);
		solve(rs);
	}
}
using namespace treap;
signed main(){
	srand(109109);
	int n=read(),m=read();
	F(i,1,n) p=merge(p,add(i));
	F(i,1,m){
		int op=read();
		if(op==1){
			int l=read(),r=read(),x,y,z;
			split(p,l-1,x,y);
			split(y,r-l+1,y,z);
			push_r(y);
			p=merge(x,merge(y,z));
		}
		else{
			int l=read(),r=read(),v=read(),x,y,z;
			split(p,l-1,x,y);
			split(y,r-l+1,y,z);
			push_d(y,v,v);
			p=merge(x,merge(y,z));
		}
	}
	solve(p);
}