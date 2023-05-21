#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	register int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*f;
}
const int maxn=114514;
struct edge{
	int u;
	double v;
	bool operator <(const edge &a)const{
		return v>a.v;
	}
};
int vis[maxn];
double d[maxn],ans=1e18,b;
vector<edge> g[maxn];
priority_queue<edge> q;
void addedge(int u,int v,double w){
	edge t; t.u=v; t.v=w;
	g[u].push_back(t);
}
void dijkstra(int p){
	memset(d,0x3f3f3f3f,sizeof(d));
	memset(vis,0,sizeof(vis));
	d[p]=0;
	edge tmp;tmp.u=p;tmp.v=0;
	q.push(tmp);
	while(!q.empty()){
		int x=q.top().u;
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=0;i<g[x].size();i++){
			int u=g[x][i].u,v=g[x][i].v;
			if(d[x]+v<d[u]){
				d[u]=d[x]+v;
				edge tmp;tmp.u=u;tmp.v=d[u];
				q.push(tmp);
			}
		}
	}
}
signed main(){
	int n=read(),m=read(),s=read(),t=read(),k=read(),b=read();
	while(m--){
		int u=read(),v=read(),w=read();
		addedge(u,v,w);
		addedge(v,u,w);
		for(int i=0;i<=k;i++) addedge(i*n+u,i*n+v,w),addedge(i*n+v,i*n+u,w);
		for(int i=0;i<=k;i++) addedge(i*n+u,(i+1)*n+v,w*b),addedge(i*n+v,(i+1)*n+u,w*b);
	}
	dijkstra(s);
	for(int i=0;i<=k;i++) ans=min(ans,d[i*n+t]);
	printf("%.2lf",ans);
}