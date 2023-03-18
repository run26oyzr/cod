#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
template<typename T> inline void read(T &x) {
	x = 0;
	char c = getchar();
	for (;!isdigit(c); c = getchar());
	for (;isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
}
int a[maxn];
char s[maxn];
int main(){
    int n;
    read(n);
    char c;
    int cntG = 0, cntH = 0;
    int firstG = 0, firstH = 0;
    int lastG = 0, lastH = 0;
    for (int i = 1; i <= n; i++){
        cin >> c;
        if (c == 'G'){
            if (!cntG) firstG = i;
            cntG++;
            lastG = i;
        }else{
            if (!cntH) firstH = i;
            cntH++;
            lastH = i;
        }
        s[i] = c;
    }
    for (int i = 1; i <= n; i++) read(a[i]);
    if (a[firstG] < lastG) firstG = 0;
    if (a[firstH] < lastH) firstH = 0;
    int ans = 0;
    if (firstG < firstH){
        for (int i = 1; i < firstH; i++){
            if (s[i] == 'G' && a[i] >= firstH) ans++;
        }
        if (firstG != 0 && a[firstG] < firstH) ans++;
    }else{
        for (int i = 1; i < firstG; i++){
            if (s[i] == 'H' && a[i] >= firstG) ans++;
        }
        if (firstH != 0 && a[firstH] < firstG) ans++;
    }
    cout << ans;
    return 0;
}