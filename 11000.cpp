#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
using namespace std;

struct compare{
    bool operator()(pair<int,int> a, pair<int,int> b){
        if(a.first == b.first){
            return a.second > b.second;
        }
        return a.first > b.first;
    }
};

priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;

priority_queue<int, vector<int>, greater<int>> tq;

int n, s, t;

int main() {
    //ios_base :: sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);
	cin >> n;
    
    while(n--){
        cin >> s >> t;
        pq.push({s,t});
    }
    while(!pq.empty()){
        tie(s,t) = pq.top();pq.pop();
        if(tq.empty())
            tq.push(t);
        else{
            if(s >= tq.top()){
                tq.pop();
                tq.push(t);
            }
            else
                tq.push(t);
        }
    }
    cout << tq.size();
    return 0;
}
