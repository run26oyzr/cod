#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
template<typename T> inline void read(T &x) {
	x = 0;
	char c = getchar();
	for (;!isdigit(c); c = getchar());
	for (;isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
}
struct Node{
    int idx, val;
    bool operator < (const Node T)const{
        return val < T.val;
    }
}cnt2[30];
int cnt[30], unappear[30];
int pos[30][maxn];
int appear_cnt[30];
signed main(){
    int T;
    read(T);
    while(T--){
        int n;
        read(n);
        string s;
        cin >> s;
        for (int i = 1; i <= 26; i++){
            cnt[i] = 0;
            appear_cnt[i] = 0;
            unappear[i] = 0;
            cnt2[i].idx = 0; cnt2[i].val = 0;
        }
        for (int i = 0; i < n; i++){
            cnt[s[i] - 'a' + 1]++;
            pos[s[i] - 'a' + 1][++appear_cnt[s[i] - 'a' + 1]] = i;
        }
        int appear_num = 0;
        int change_num = 0;
        int require_num = 0;
        int tot = 0;
        for (int i = 1; i <= 26; i++){
            cnt2[i].val = cnt[i];
            cnt2[i].idx = i;
            if (cnt[i]) appear_num++;
            else{
                unappear[++tot] = i;
                cnt2[i].val = 1e9;
            }
        }
        sort(cnt2 + 1, cnt2 + 26 + 1);
        int minnum = 1e9, minval = 0;
        for (int i = 1; i <= n; i++){
            if (n % i != 0) continue;
            change_num = 0;
            require_num = n / i;
            if (appear_num < require_num){
                for (int j = appear_num - (require_num - appear_num) + 1; j <= appear_num; j++){
                    // cout << j << endl;
                    change_num += abs(cnt2[j].val - i);
                }
            }else{
                for (int j = 1; j <= appear_num - require_num; j++){
                    // cout << j << ' ' << cnt2[j] << endl;
                    change_num += cnt2[j].val;
                }
            }
            if (change_num < minnum){
                minnum = change_num;
                minval = i;
            }
        }
        cout << minnum << endl;
        require_num = n / minval;
        if (appear_num < require_num){
            int which = 1;
            for (int j = appear_num - (require_num - appear_num) + 1; j <= appear_num; j++){
                int now = 0;
                while(cnt[cnt2[j].idx] > minval){
                    cnt[cnt2[j].idx]--;
                    s[pos[cnt2[j].idx][++now]] = unappear[which] + 'a' - 1;
                    cnt[unappear[which]]++;
                    if (cnt[unappear[which]] >= minval) which++;
                }
            }
        }else{
            int which = appear_num - require_num + 1;
            for (int j = 1; j <= appear_num - require_num; j++){
                int now = 0;
                while(cnt[cnt2[j].idx] > 0){
                    cnt[cnt2[j].idx]--;
                    s[pos[cnt2[j].idx][++now]] = cnt2[which].idx + 'a' - 1;
                    cnt[cnt2[which].idx]++;
                    if (cnt[cnt2[which].idx] >= minval) which++;
                }
            }
        }
        cout << s << endl;
    }
    return 0;
}