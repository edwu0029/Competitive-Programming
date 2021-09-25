/*
Livestock Lineup
USACO 2019 December Contest, Bronze, Problem 3
http://usaco.org/index.php?page=viewproblem2&cpid=965
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
pair<string, string>F[8];
vector<string>cows;
int get_idx(string t){
    for(int i = 0;i<8;i++){
        if(t==cows[i]) return i;
    }
    return 0;
}
int main(){
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for(int i = 0;i<N;i++){
        cin >> F[i].first;
        string t;
        for(int j = 0;j<4;j++) cin >> t;
        cin >> F[i].second;
    }
    cows.push_back("Beatrice");
    cows.push_back("Belinda");
    cows.push_back("Bella");
    cows.push_back("Bessie");
    cows.push_back("Betsy");
    cows.push_back("Blue");
    cows.push_back("Buttercup");
    cows.push_back("Sue");
    do{
        bool check = true;
        for(int i = 0;i<N;i++){
            if(abs(get_idx(F[i].first)-get_idx(F[i].second))!=1){
                check = false;
                break;
            }
        }
        if(check){
            for(int i = 0;i<8;i++) cout << cows[i] << nl;
            return 0;
        }
    }while(next_permutation(cows.begin(), cows.end()));
    return 0;
}