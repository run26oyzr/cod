#include <bits/stdc++.h>
using namespace std;
// template<typename T> inline void read(T &x) {
// 	x = 0;
// 	char c = getchar();
// 	for (;!isdigit(c); c = getchar());
// 	for (;isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
// }
inline int read()
{
    register int x = 0,f = 1;
    char c = getchar();
    while(c < '0' || c > '9')
    {
        if(c == '-') f = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9') 
    {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}
int main(){

    system("pause");
    return 0;
}