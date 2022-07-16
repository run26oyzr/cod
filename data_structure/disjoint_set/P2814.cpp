#include <bits/stdc++.h>
using namespace std;
map <string, int> mp;
const int maxn = 5 * 1e4 + 5;
int fa[maxn];
int getfather(int x){
    if (fa[x] == x) return x;
    return fa[x] = getfather(fa[x]);
}
bool merge(string x, string y, int mod = 0){
    int fx = getfather(x);
    int fy = getfather(y);
    if (fx == fy) return false;
    if (mod) fa[fy] = fx;
    return true;
}
int main(){
    for (int i = 1; i <= maxn - 5; i++){
        fa[i] = i;
    }
    string s1, s2;
    char c1, c2;
    while(1){
        cin >> c1; if(c1 == '?') break; cin >> s1;
        cin >> c2; cin >> s2;
        merge(s1, s2, 1);
    }
    while(1){
        cin >> s1;
        getfather(s1);

    }
    system("Pause");
    return 0;
}