#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
#define key_down(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
int rand(int l, int r){
    return rand() % (r - l + 1) + l;
}
int main()
{   
    srand(time(0));
    int tot;
    while (1) //一直循环，直到找到不一样的数据
    {
        Sleep(1000);
        // system(".\\own_competition\\C\\data.exe > .\\own_competition\\C\\C.in");
        // if (!system("fc .\\own_competition\\C\\C.in .\\own_competition\\C\\C_copy.in")) continue;
        // system("copy .\\own_competition\\C\\C.in .\\own_competition\\C\\C_copy.in");
        system(".\\own_competition\\C\\bao_li.exe < .\\own_competition\\C\\C.in > .\\own_competition\\C\\bao_li.out");
        system(".\\own_competition\\C\\std.exe < .\\own_competition\\C\\C.in > .\\own_competition\\C\\std.out");
        if (system("fc .\\own_competition\\C\\std.out .\\own_competition\\C\\bao_li.out")){ //当 fc 返回1时，说明这时数据不一样
            cout << "error";
            break;                          //不一样就跳出循环
        }
        tot++;
        cout << tot << endl;
    }
    // system("cls");
    cout << tot;
    system("pause");
    return 0;
}
