//简兮简兮，方将万舞。《诗经·简兮》
//朕躬有罪，无以万方；万方有罪，罪在朕躬。《论语·尧曰》
#include<bits/stdc++.h>
#include<ext/pb_ds/detail/standard_policies.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#define int long long
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define clr clear
#define fi first
#define se second
#define mx3(a,b,c) ((a>b?a:b)>c?(a>b?a:b):c)
#define mn3(a,b,c) ((a<b?a:b)<c?(a<b?a:b):c)
#define infll 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define ook order_of_key
#define ins insert
#define oset tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define pii pair<int,int>
#define pqueue priority_queue
#define F(i,a,b) for(int i=a;i<=(b);i++)
#define F2(i,a,b) for(int i=a;i<(b);i++)
#define dF(i,a,b) for(int i=a;i>=(b);i--)
#define WH while
#define CO continue
#define BR break
#define wh(fqd) while(fqd--)
#define lowbit(x) (x&(-x))
#define bctz __builtin_ctz
#define bclz __builtin_clz
#define bppc __builtin_popcount
#define HH printf("\n")
#define umap unordered_map
#define uset unordered_set
#define eb emplace_back
using namespace std;
using namespace __gnu_pbds;
inline int read(){
	register int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*f;
}
inline void print(int x){
	if(!x) return;
	if(x<0) putchar('-'),x=-x;
	print(x/10);
	putchar(x%10+'0');
}
const int mod=998244353,maxn=1314635;
int qpow(int x,int y){
	x%=mod;
	int rt=1;
	for(;y;y>>=1){
		if(y&1) rt=(rt*x)%mod;
		x=(x*x)%mod;
	}
	return rt;
}
namespace number_theory{
	vector<int> p11;
	bool vis11[maxn];
	int phi[maxn],fc[maxn],inv[maxn];
	void init(){
		for(int i=2;i<maxn;i++){
			if(!vis11[i]){p11.push_back(i);phi[i]=i-1;} 
			for(int j=0;j<p11.size()&&i*p11[j]<maxn;j++){
				vis11[i*p11[j]]=1;
				if(i%p11[j]==0){phi[p11[j]*i]=phi[i]*p11[j];break;} 
				else phi[p11[j]*i]=phi[i]*(p11[j]-1);
			}
		}
		inv[0]=0;
		inv[1]=1;
		for(int i=2;i<maxn;i++) inv[i]=(mod-mod/i)*inv[mod%i]%mod;
		fc[0]=fc[1]=1;	
		for(int i=2;i<maxn;i++) fc[i]=(fc[i-1]*i)%mod;
	}
	bool isp(int x){
		return vis11[x]?0:1;
	}
	int cphi(int x){
		return phi[x];
	}
	int cinv(int x){
		return qpow(x,mod-2);
	}
	int cinv1(int x){
		return inv[x];
	}
	int C(int n,int m){
		return m>n?0:((fc[n]*cinv(fc[m]))%mod*cinv(fc[n-m]))%mod;
	}
	int A(int n,int m){
		return (C(n,m)*fc[m])%mod;
	}
	int modrn(int p,int q){
		return !q?-1:(p*cinv(q)%mod+mod)%mod;
	}
}
using namespace number_theory;
namespace bit{
	int bitc[maxn];
	int query(int x){int t=0;for(int i=x;i;i-=lowbit(i)) t+=bitc[i];return t;}
	void add(int x,int y,int n){for(int i=x;i<=n;i+=lowbit(i)) bitc[i]+=y;}
}
using namespace bit;
inline int popcnt(int x){
	int rt=0;
	for(;x;x>>=1) if(x&1) rt++;
	return rt;
}
void addmod(int &x,int y){
	x+=y;
	x%=mod;
	if(x<0) x+=mod;
}
void mulmod(int &x,int y){
	x*=y;
	x%=mod;
	if(x<0) x+=mod;
}
void ansmax(int &x,int y){
	x=max(x,y);
}
void ansmin(int &x,int y){
	x=min(x,y);
}
void solve(){
	int n=read(),a=read(),b=read();
    if(n==1&&a==b) return printf("1\n%lld:%lld",a,b),void();
    if(n==1) return printf("0\n%lld:%lld",a,b),void();
    if(a+b==n){
        puts("0");
        F(i,1,a) puts("1:0");
        F(i,1,b) puts("0:1");
        return;
    }
    if(a+b>n){
        puts("0");
        int k=min(a,n-1);
        if(!b) k=n;
        if(a){
            F(i,1,k-1) puts("1:0");
            printf("%lld:0\n",a-(k-1));
        }
        if(b){
            int cnt=0;
            F(i,k+1,n-1) puts("0:1"),cnt++;
            printf("0:%lld\n",b-cnt);
        }
        return;
    }
    printf("%lld\n",n-(a+b));
    F(i,1,a) puts("1:0");
    F(i,1,b) puts("0:1");
    F(i,1,n-a-b) puts("0:0");
}
signed main(){
	init();
	int lzm=1;
	wh(lzm) solve();
}
/*
简兮简兮，方将万舞。日之方中，在前上处。
硕人俣俣，公庭万舞。有力如虎，执辔如组。
左手执龠，右手秉翟。赫如渥赭，公言锡爵。
山有榛，隰有苓。云谁之思？西方美人。彼美人兮，西方之人兮。
*/