#include <bits/stdc++.h>
using namespace std;
const int maxn = 5 * 1e4 + 5;
map <string, string> fa;
string getfather(string x){
    if (fa[x] == x) return x;
    return fa[x] = getfather(fa[x]);
}
int main(){
    char c, d;
    string son, father;
    cin >> c;
    int x, y, z;
    int num = 0;
    while(c != '$'){
        if (c == '#'){
            cin >> father;
            if (fa[father] == "") fa[father] = father;
        }
        else if (c == '+'){
            cin >> son;
            fa[son] = father;
        }
        else{
            cin >> son;
            // cout << getfather(son) << endl;
            cout << son << ' ' << getfather(son) << endl;
        }
        cin >> c;
    }
    system("Pause");
    return 0;
}