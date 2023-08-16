#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e6;
set <int> pet;
set <int>::iterator it_pet;
set <int> person;
set <int>::iterator it_person;
signed main(){
    int cnt_pet = 0, cnt_person = 0;
    int n;
    cin >> n;
    int x, y;
    long long ans = 0;
    person.insert((int)(-1e9));
    person.insert((int)(1e9));
    pet.insert((int)(-1e9));
    pet.insert((int)(1e9));
    while(n--){
        cin >> x >> y;
        if (x == 0){
            if(cnt_pet >= cnt_person){
                pet.insert(y);
                cnt_pet++;
            }
            else{
                int num = 1e9, id;
                it_person = person.lower_bound(y);
                if ((*it_person) == y){
                    num = 0;
                    id = (*it_person);
                }
                else if (it_person != person.begin()){
                    it_person --;
                    if (y - (*it_person) < num){
                        num = y - (*it_person);
                        // cout << (*it_person) << ' ' << num << endl;
                        id = (*it_person);
                    }
                }
                it_person = person.upper_bound(y);
                if ((*it_person) - y < num){
                    num = (*it_person) - y;
                    // cout << (*it_person) << ' ' << num << endl;
                    id = (*it_person);
                }
                ans += num;
                ans %= mod;
                person.erase(id);
                cnt_person --;
            }
        }
        if (x == 1){
            if(cnt_person >= cnt_pet){
                person.insert(y);
                cnt_person++;
            }
            else{
                int num = 1e9, id;
                it_pet = pet.lower_bound(y);
                if ((*it_pet) == y){
                    num = 0;
                    id = (*it_pet);
                }
                else if (it_pet != pet.begin()){
                    it_pet --;
                    if (y - (*it_pet) < num){
                        num = y - (*it_pet);
                        // cout << (*it_pet) << ' ' << num << endl;
                        id = (*it_pet);
                    }
                }
                it_pet = pet.upper_bound(y);
                if ((*it_pet) - y < num){
                    num = (*it_pet) - y;
                    // cout << (*it_pet) << ' ' << num << endl;
                    id = (*it_pet);
                }
                ans += num;
                ans %= mod;
                pet.erase(id);
                cnt_pet --;
            }
        }
    }
    cout << ans;
    system("Pause");
    return 0;
}