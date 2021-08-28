//Problem: https://dmoj.ca/problem/ccc07j4

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
string p1, p2;
int freq[26], freq2[26];
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    getline(cin, p1);
    getline(cin, p2);
    for(int i = 0;i<p1.size();i++){
        if(p1[i]!=' ') freq[p1[i]-'A']++;
    }
    for(int i = 0;i<p2.size();i++){
        if(p2[i]!=' ') freq2[p2[i]-'A']++;
    }
    bool ans = true;
    for(int i = 0;i<26;i++){
        if(freq[i]!=freq2[i]) ans = false;
    }
    if(ans) cout << "Is an anagram." << nl;
    else cout << "Is not an anagram." << nl;
    return 0;
}