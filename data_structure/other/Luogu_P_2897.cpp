#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
stack <int> s1, s2;
int L[maxn], R[maxn], h[maxn], w[maxn], ans[maxn];
signed main(){
    int n;
    cin >> n;
    h[0] = h[n + 1] = 1e9;
    int x;
    int t = 0;
    for (int i = 1; i <= n; i++){
        cin >> x >> h[i];
        w[i] = w[i - 1] + x;
    }
    s1.push(0);
    for (int i = 1; i <= n + 1; i++){
        while (!s1.empty() && h[s1.top()] <= h[i]){
            if (s1.top() == 0) break;
            int y = s1.top();
            s1.pop();
            int leftnum = L[y];
            int rightnum = i;
            // cout << y << ' ' << leftnum << ' ' << rightnum  << ' ' << w[rightnum - 1] - w[leftnum] << endl;
            ans[y] = t + w[rightnum - 1] - w[leftnum];
            t += (w[rightnum - 1] - w[leftnum]) * (min(h[leftnum], h[rightnum]) - h[y]);
        }
        L[i] = s1.top();
        s1.push(i);
    }
    for (int i = 1; i <= n; i++){
        cout << ans[i] << endl;
    }
    // system("pause");
    return 0;
}