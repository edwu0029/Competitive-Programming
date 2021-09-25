/*
Returning Home
Canadian Computing Competition: 2005 Stage 1, Junior #3
https://dmoj.ca/problem/ccc05j3
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define nl '\n'
#define sp ' '
#define mp(a, b) make_pair(a, b)
#define EPS 1e-9
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ll MODll = 4000004479;
vector<string>route = {"HOME"};
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    while(true){
        string s; cin >> s;
        if(s=="SCHOOL") break;
        route.push_back(s);
    }
    reverse(route.begin(), route.end());
    for(int i = 0;i<route.size();i+=2){
        string p = "";
        if(route[i]=="R"){
            if(route[i+1]=="HOME"){
                cout << "Turn LEFT into your HOME." << nl;
            }else{
                cout << "Turn LEFT onto " << route[i+1] << " street." << nl;
            }
        }else{
            if(route[i+1]=="HOME"){
                cout << "Turn RIGHT into your HOME." << nl;
            }else{
                cout << "Turn RIGHT onto " << route[i+1] << " street." << nl;
            }
        }
    }
    return 0;
}