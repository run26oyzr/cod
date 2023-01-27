/*
#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;
int a[maxn];
int main(){
    int T;
    cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        int x;
        for (int i = 1; i <= m; i++){
            cin >> x;
            sort(a + 1, a + n + 1);
            a[1] = x;
        }
        long long ans = 0;  
        for (int i = 1; i <= n; i++){
            ans += a[i];
        }
        cout << ans << endl;
    }
    return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b){
    return a>=b;
}

#define MAXNM 105
int n,m;
long long a[2*MAXNM];
long long ans=0;
void run(){
    scanf("%d %d",&n,&m);
    ans=0;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(int j=1;j<m;j++){
        scanf("%lld",&a[n+j]);
    }
    scanf("%lld",&a[0]);
    sort(a+1,a+n+m,cmp);
    for(int i=0;i<n;i++){
        ans+=a[i];
    }
    printf("%lld\n",ans);

    return;
}

int T;
int main(){
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        run();
    }

    return 0;
}