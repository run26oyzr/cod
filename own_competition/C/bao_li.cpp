#include<bits/stdc++.h>
#define int long long
#define F(i,a,b) for(int i=a;i<=b;i++)
#define ls s[o][0]
#define rs s[o][1]
using namespace std;
inline int read(){
	register int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*f;
}const int maxn=109125;
int a[maxn];
signed main(){
	int n=read(),m=read();
	F(i,1,n) a[i]=i;
	F(i,1,m){
		int op=read(),l=read(),r=read();
		if(op==1) reverse(a+l,a+r+1);
		else{
			int x=read();
			F(i,l,r) a[i]+=(i-l+1)*x;
		}
	}
	F(i,1,n) printf("%lld ",a[i]);
	// system("pause");
}