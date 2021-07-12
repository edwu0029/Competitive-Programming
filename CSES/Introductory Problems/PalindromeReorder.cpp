//Problem: https://cses.fi/problemset/task/1755/

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
const int MAXN = 2e5+5;
string org;
int freq[26];
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> org;
    for(int i = 0;i<org.size();i++){
        freq[org[i]-'A']++;
    }
    deque<char>l, r, mid;
    for(int i = 0;i<26;i++){
        char cur = i+'A';
        if(freq[i]%2==1){
            if(mid.size()!=0){
                cout << "NO SOLUTION" << nl;
                return 0;
            }
            mid.push_back(cur);
            freq[i]--;
        }
        for(int j = 0;j<freq[i]/2;j++){
            l.push_back(cur);
            r.push_front(cur);
        }
    }
    for(auto i:l){
        cout << i;
    }
    for(auto i:mid){
        cout << i;
    }
    for(auto i:r){
        cout << i;
    }
    cout << nl;
    return 0;
}