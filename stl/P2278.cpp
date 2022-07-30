#include <bits/stdc++.h>
#define int long long
using namespace std;
struct Node{
    int priority_level, num, start, lasts;
    bool operator < (const Node T) const{
        if (T.priority_level == priority_level) return T.num < num;
        return T.priority_level > priority_level;
    }
};
priority_queue<Node> q;
signed main(){
    Node now, nt;
    cin >> now.num >> now.start >> now.lasts >> now.priority_level;
    q.push(now);
    int nowtime = now.start;
    while(cin >> now.num){
        cin >> now.start >> now.lasts >> now.priority_level;
        // scanf("%lld %lld %lld", &now.start, &now.lasts, &now.priority_level);
        nt = q.top(); q.pop();
        int x = now.start - nowtime;
        while (nt.lasts <= x){
            cout << nt.num << ' ' << nowtime + nt.lasts << endl;
            nowtime += nt.lasts;
            nt.lasts = 0;
            if (q.empty()) break;
            nt = q.top(); q.pop();
            x = now.start - nowtime;
        }
        if (nt.lasts != 0){
            nt.lasts -= x;
            q.push(nt);
        }
        nowtime = now.start;
        q.push(now);
    }
    while(!q.empty()){
        nt = q.top(); q.pop();
        cout << nt.num << ' ' << nowtime + nt.lasts << endl;
        nowtime += nt.lasts;
    }
    system("Pause");
    return 0;
}