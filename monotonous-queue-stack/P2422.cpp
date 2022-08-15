#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
struct node{
    int id, val;
};
int sum[maxn];
node q1[maxn], q2[maxn];
int fron[maxn], back[maxn];
int t[maxn];
signed main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> t[i];
        sum[i] = sum[i - 1] + t[i];
    }
    int front = 1, rear = 1;
    for (int i = 1; i <= n; i++){
        while(front < rear && q1[rear - 1].val >= t[i]){back[q1[rear - 1].id] = i; rear--;}
        q1[rear].id = i, q1[rear].val = t[i]; rear++;
    }
    front = 1, rear = 1;
    for (int i = n; i >= 1; i--){
        // cout << front << ' ' << rear << endl;
        // cout << q2[rear - 1].val << ' ' << t[i] << endl;
        // cout << endl;
        while(front < rear && q2[rear - 1].val >= t[i]){fron[q2[rear - 1].id] = i; rear--;}
        q2[rear].id = i, q2[rear].val = t[i]; rear++;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++){
        // cout << sum[back[i] - 1] - sum[fron[i]] << endl;
        ans = max(ans, (sum[back[i] - 1] - sum[fron[i]]) * t[i]);
    }
    cout << ans;
    system("pause");
    return 0;
}