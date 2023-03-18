#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
priority_queue<int, vector<int>, less<int> > q;
int a[maxn], b[maxn];
int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++){
        for (int j = 1; (i - 1) * (j - 1) <= n && j <= n; j++){
            int sum = a[i] + b[j];
            if (n > q.size()) q.push(sum);
            else {
                if (sum < q.top()){
                    q.pop();
                    q.push(sum);
                }
            }
        }
    }
    int ans[maxn];
    for(int i = n; i >= 1; i--){
        ans[i] = q.top();
        q.pop();
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    system("Pause");
    return 0;
}