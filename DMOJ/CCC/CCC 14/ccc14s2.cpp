//Problem: https://dmoj.ca/problem/ccc14s2

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
int N;
vector<string>p1, p2;
map<string, int>m1, m2;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for(int i = 0;i<N;i++){
        string t; cin >> t;
        m1[t] = i;
        p1.push_back(t);
    }
    for(int i = 0;i<N;i++){
        string t; cin >> t;
        m2[t] = i;
        p2.push_back(t);
    }
    bool ans = true;
    for(int i = 0;i<N;i++){
        if(m1[p2[i]]!=m2[p1[i]] || p1[i]==p2[i]){
            ans = false;
        }
    }
    if(ans){
        cout << "good" << nl;
    }else{
        cout << "bad" << nl;
    }
    return 0;
}