//Problem: https://dmoj.ca/problem/ccc13s3

#include <iostream>
#include <vector>
#include <limits>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <complex>
#include <iomanip>
#include <cassert>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <stack>
#include <cstring>
#include <climits>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define nl '\n'
#define sp ' '
#define f first
#define s second
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define EPS 1e-9
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ll MODll = 4000004479;
const int MAXN = 2e5+2;
int T, G, ans;
void rec(int num, vector<vector<bool>>games, vector<int>scores){
    if(num==6){
        bool check = true;
        for(int i = 1;i<=4;i++){
            if(i==T) continue;
            if(scores[i]>=scores[T]) check = false;
        }
        if(check) ans++;
        return;
    }
    for(int i = 1;i<=4;i++){
        for(int j = i+1;j<=4;j++){
            if(games[i][j]) continue;
            games[i][j] = true;
            //Team i wins
            scores[i]+=3; rec(num+1, games, scores); scores[i]-=3;
            //Team j wins
            scores[j]+=3; rec(num+1, games, scores); scores[j]-=3;
            //Tie
            scores[i]++; scores[j]++; rec(num+1, games, scores); scores[i]--; scores[j]--;
            return;
        }
    }
}
int main(){
    scanf("%d", &T);
    scanf("%d", &G);
    vector<vector<bool>>games(5, vector<bool>(5, false));
    vector<int>scores(5, 0);
    for(int i = 1, a, b, sa, sb;i<=G;i++){
        scanf("%d%d%d%d", &a, &b, &sa, &sb);
        games[a][b] = games[b][a] = true;
        if(sa==sb){
            scores[a]++; scores[b]++;
        }else if(sa>sb){
            scores[a]+=3;
        }else{
            scores[b]+=3;
        }
    }
    rec(G, games, scores);
    printf("%d\n", ans);
    return 0;
}