/*
English or French?
Canadian Computing Competition: 2011 Stage 1, Senior #1
https://dmoj.ca/problem/ccc11s1
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
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    //Read new line from input of N
    string nll; getline(cin, nll);
    int t = 0, s = 0;
    for(int i = 0;i<N;i++){
        string S; getline(cin, S);
        for(int j = 0;j<S.size();j++){
            if(S[j]=='t'||S[j]=='T') t++;
            else if(S[j]=='s'||S[j]=='S') s++;
        }
    }
    if(s>=t){
        cout << "French" << nl;
    }else{
        cout << "English" << nl;
    }
    return 0;
}