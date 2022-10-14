#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2145140;
inline int read(){
	register int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*f;
}
signed main(){
	int n=read(),ans=0;
	for(int i=1;i<=n;i++) ans+=(n/i);
	printf("%lld",ans);	
}