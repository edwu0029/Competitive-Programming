/*
Carnival Phantasm
DMOPC '16 Contest 4 P3
https://dmoj.ca/problem/dmopc16c4p3
*/

#include <bits/stdc++.h>
using namespace std;
set<pair<int, int>> apples[100001];
int dis[100001];
int N, S, Q;
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> S;
    for(int i = 1;i<=N;i++){
        int tmp; cin >> tmp;
        dis[i] = tmp;
    }
    for(int i = 0;i<S;i++){
        int si, ai; cin >> si >> ai;
        apples[ai].insert(make_pair(dis[si], si));
    }
    cin >> Q;
    for(int i = 0;i<Q;i++){
        char k; cin >> k;
        if(k=='Q'){
            int x; cin >> x;
            if(apples[x].size()==0){cout << -1 << '\n';}
            else cout << apples[x].begin()->second << '\n';
            continue;
        }
        int x, y; cin >> x >> y;
        if(k=='A'){
            apples[y].insert(make_pair(dis[x], x));
        }else if(k=='S'){
            apples[y].erase(make_pair(dis[x], x));
        }else if(k=='E'){
            pair<int, int>tmp = make_pair(dis[x], x);
            dis[x]=y;
            for(int i = 0;i<101;i++)
                apples[i].erase(tmp);
        }
    }
}