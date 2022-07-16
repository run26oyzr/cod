#include <bits/stdc++.h>
using namespace std;
struct Node{
    int id, val, start;
    bool operator < (const Node T) const{
        if (T.id == id) return T.start < start;
        return T.id > id;
    }
};
priority_queue<Node> q;
int main(){
    
    system("Pause");
    return 0;
}