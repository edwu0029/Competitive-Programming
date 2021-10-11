/*
Swiss-System Tournament
AtCoder Beginner Contest 222, Problem C
https://atcoder.jp/contests/abc222/tasks/abc222_c
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
const int MAXN = 105;
int N, M, wins[MAXN];
char A[MAXN][MAXN];
bool cmp(int a, int b){
    if(wins[a]==wins[b]) return a<b;
    else return wins[a]>wins[b];
}
int check_win(char a, char b){
    if(a==b) return 0; //Draw
    else if((a=='G'&&b=='C')||(a=='C'&&b=='P')||(a=='P'&&b=='G')){
        return 1;
    }else return -1;
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 0;i<2*N;i++){
        string t; cin >> t;
        for(int j = 0;j<M;j++){
            A[i][j] = t[j];
        }
    }
    vector<int>rank(2*N);
    for(int i = 1;i<=2*N;i++) rank[i-1] = i;
    for(int i = 0;i<M;i++){
        for(int j = 1;j<=N;j++){
            int r1 = 2*j-1, r2 = 2*j;
            int t = check_win(A[rank[r1-1]-1][i], A[rank[r2-1]-1][i]);
            if(t==1) wins[rank[r1-1]]++;
            else if(t==-1) wins[rank[r2-1]]++;
        }
        sort(rank.begin(), rank.end(), cmp);
    }
    for(int i = 0;i<2*N;i++){
        cout << rank[i] << nl;
    }
    return 0;
}