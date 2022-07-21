#include <bits/stdc++.h>
using namespace std;
map <string, int> person;
string all[15];
int main(){
    int n;
    cin >> n;
    string who;
    for (int i = 1; i <= n; i++){
        cin >> who;
        all[i] = who;
        person[who] = 0;
    }
    int m, num;
    string get_person, give_person;
    for (int i = 1; i <= n; i++){
        cin >> give_person;
        cin >> m >> num;
        if (num == 0) continue;
        int x = m / num;
        person[give_person] -= num * x;
        for (int j = 1; j <= num; j++){
            cin >> get_person;
            person[get_person] += x;
        }
    }
    for (int i = 1; i <= n; i++){
        cout << all[i] << ' ' << person[all[i]] << endl;
    }
    system("pause");
    return 0;
}