#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	register int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*f;
}
const int maxn=300005;
int a[maxn],b[maxn];
void solve(){
	//do something
	int n=read();
	bool fl=1;
	map<int,int>m;
	for(int i=1;i<=n;i++){
		a[i]=read();
		int k=a[i];
		while(k%3==0) k/=3;
		m[k]++;
	} 
	for(int i=1;i<=n;i++){
		b[i]=read();
		bool ok=0;
		while(b[i]){
			if(m[b[i]]){
				m[b[i]]--;
				ok=1;
				break;
			}
			b[i]/=3;
		}
		if(!ok) fl=0;
	} 
	if(!fl) puts("NO");
	else puts("YES");
}
signed main(){
	solve();
	system("pause");
}