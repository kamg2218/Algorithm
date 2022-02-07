//array
#include <iostream>
#include <string>
#include <cstring>
using namespace std;


int     main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int         n, m;
    string      cmd = "";
    bool    s[21] = {0, };

    cin >> m;
    for (int i = 0; i < m; i++){
        cin >> cmd;
        if (cmd == "all"){
            memset(s, true, 21);
            continue;
        }
        else if (cmd == "empty"){
            memset(s, false, 21);
            continue;
        }
        cin >> n;
        if (cmd == "add"){
            s[n] = true;
        } else if (cmd == "remove"){
            s[n] = false;
        } else if (cmd == "check"){
            if (s[n])
                cout << "1\n";
            else
                cout << "0\n";
        } else if (cmd == "toggle"){
            s[n] = !s[n];
        }
    }
    return 0;
}