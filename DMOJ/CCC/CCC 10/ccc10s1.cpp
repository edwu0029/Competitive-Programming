/*
Computer Purchase
Canadian Computing Competition: 2010 Stage 1, Senior #1
https://dmoj.ca/problem/ccc10s1
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
int N;
struct E{
    int val;
    string name;
    friend bool operator<(const E &a, const E &b){
        if(a.val==b.val){
            return a.name<b.name;
        }else{
            return a.val>b.val;
        }
    }
};
vector<E>v;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for(int i = 0;i<N;i++){
        string name;
        int R, S, D;
        cin >> name >> R >> S >> D;
        v.push_back({2*R+3*S+D, name});
    }
    sort(v.begin(), v.end());
    for(int i = 0;i<2&&i<N;i++){
        cout << v[i].name << nl;
    }
    return 0;
}