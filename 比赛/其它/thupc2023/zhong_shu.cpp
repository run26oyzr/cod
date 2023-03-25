#include <bits/stdc++.h>
using namespace std;
const int maxn= 1e5 + 5;
template<typename T> inline void read(T &x) {
	x = 0;
	char c = getchar();
	for (;!isdigit(c); c = getchar());
	for (;isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
}
struct Node{
    int val;
    int cnt;
    bool operator < (const Node T)const{
        if (cnt == 0) return true;
        if (T.cnt == 0) return false;
        return val > T.val;
    }
};
Node t[maxn];
int main(){
    int n;
    read(n);
    for (int i = 1; i <= n; i++){
        read(t[i].val);
        t[i].cnt = i;
    }
    while(){
        
    }
    return 0;
}