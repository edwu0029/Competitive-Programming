//Problem: https://dmoj.ca/problem/ccc06j5

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
char st;
int N, m[9][9]; //white = 0, black = 1
void init_config(char state){
    if(state=='a'){
        m[4][4] = m[5][5] = 0;
        m[4][5] = m[5][4] = 1;
    }else if(state=='b'){
        for(int i = 1;i<=8;i++){
            m[i][i] = 1;
            m[i][8-i+1] = 0;
        }
    }else{
        for(int i = 1;i<=8;i++){
            m[i][3] = m[i][4] = 1;
            m[i][5] = m[i][6] = 0;
        }
    }
}
void move(int r, int c, int w){
    m[r][c] = w;
    for(int i = r+1;i<=8;i++){
        if(m[i][c]==inf) break;
        if(m[i][c]==w){
            for(int j = r+1;j<=i;j++) m[j][c] = w;
            break;
        }
    }
    for(int i = r-1;i>=1;i--){
        if(m[i][c]==inf) break;
        if(m[i][c]==w){
            for(int j = r-1;j>=i;j--) m[j][c] = w;
            break;
        }
    }
    for(int i = c+1;i<=8;i++){
        if(m[r][i]==inf) break;
        if(m[r][i]==w){
            for(int j = c+1;j<=i;j++) m[r][j] = w;
            break;
        }
    }
    for(int i = c-1;i>=1;i--){
        if(m[r][i]==inf) break;
        if(m[r][i]==w){
            for(int j = c-1;j>=i;j--) m[r][j] = w;
            break;
        }
    }
    for(int i = 1;r+i<=8&&c+i<=8;i++){
        if(m[r+i][c+i]==inf) break;
        if(m[r+i][c+i]==w){
            for(int j = 1;j<=i;j++) m[r+j][c+j] = w;
            break;
        }
    }
    for(int i = 1;r-i>=1&&c-i>=1;i++){
        if(m[r-i][c-i]==inf) break;
        if(m[r-i][c-i]==w){
            for(int j = 1;j<=i;j++) m[r-j][c-j] = w;
            break;
        }
    }
    for(int i = 1;r+i<=8&&c-i>=1;i++){
        if(m[r+i][c-i]==inf) break;
        if(m[r+i][c-i]==w){
            for(int j = 1;j<=i;j++) m[r+j][c-j] = w;
            break;
        }
    }
    for(int i = 1;r-i>=1&&c+i<=8;i++){
        if(m[r-i][c+i]==inf) break;
        if(m[r-i][c+i]==w){
            for(int j = 1;j<=i;j++) m[r-j][c+j] = w;
            break;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    memset(m, 0x3f, sizeof(m));
    cin >> st;
    init_config(st);
    cin >> N;
    for(int i = 1, r, c;i<=N;i++){
        cin >> r >> c;
        move(r, c, i%2);
    }
    int white = 0, black = 0;
    for(int i = 1;i<=8;i++){
        for(int j = 1;j<=8;j++){
            if(m[i][j]==0) white++;
            else if(m[i][j]==1) black++;
        }
    }
    cout << black << sp << white << nl;
    return 0;
}