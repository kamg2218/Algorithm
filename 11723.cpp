//set
#include <iostream>
#include <string>
#include <set>
using namespace std;


int     main(){
    int         n, m;
    string      cmd = "";
    set<int>    s;

    cin >> m;
    for (int i = 0; i < m; i++){
        cin >> cmd;
        if (cmd != "all" && cmd != "empty"){
            cin >> n;
        }
        if (cmd == "add"){
            s.insert(n);
        } else if (cmd == "remove"){
            s.erase(n);
        } else if (cmd == "check"){
            if (s.find(n) != s.end())
                cout << 1 << endl;
            else
                cout << 0 << endl;
        } else if (cmd == "toggle"){
            if (s.find(n) != s.end())
                s.erase(n);
            else
                s.insert(n);
        } else if (cmd == "all"){
            s.clear();
            for (int j = 1; j <= 20; j++){
                s.insert(j);
            }
        } else if (cmd == "empty"){
            s.clear();
        }
    }
    return 0;
}