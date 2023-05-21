#include<bits/stdc++.h>
#define ls (o<<1)
#define rs (o<<1|1)
#define lowbit(x) x&(-x)
#define int long long
using namespace std;
const int maxn=314514;
inline int read(){
	register int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*f;
}
int t[maxn<<2],a[maxn],b[maxn],c[maxn],n,q;
void add(int x,int y){
	for(int i=x;i<=n;i+=lowbit(i)) c[i]+=y;
}
int sum(int x){
	int rt=0;
	for(int i=x;i;i-=lowbit(i)) rt+=c[i];
	return rt;
}
void build(int o,int l,int r){
    if(l==r) return t[o]=b[l],void();
    int mid=(l+r)>>1;
    build(ls,l,mid);
    build(rs,mid+1,r);
    t[o]=__gcd(t[ls],t[rs]);
}
void update(int o,int l,int r,int pos,int x){
	if(l==r) return t[o]+=x,void();
	int mid=(l+r)>>1;
	if(pos<=mid) update(ls,l,mid,pos,x);
	else update(rs,mid+1,r,pos,x);
	t[o]=__gcd(t[ls],t[rs]);
}
int query(int o,int l,int r,int ql,int qr){
	if(ql<=l&&qr>=r) return t[o];
	int mid=(l+r)>>1,rt=0;
	if(ql<=mid) rt=__gcd(rt,query(ls,l,mid,ql,qr));
	if(qr>mid) rt=__gcd(rt,query(rs,mid+1,r,ql,qr));
	return rt;
}
signed main(){
	n=read(),q=read();
    for(int i=1;i<=n;i++) a[i]=read(),b[i]=a[i]-a[i-1],add(i,b[i]);
    build(1,1,n);
    while(q--){
    	int op=read();
        if(op==2){
			int l=read(),r=read(),x=read();
			add(l,x);
			add(r+1,-x);
			update(1,1,n,l,x);
			if(r<n)update(1,1,n,r+1,-x);
		}
        else{
			int l=read(),r=read();
			printf("%lld\n",abs(__gcd(query(1,1,n,l+1,r),sum(l))));
		}
    }
}