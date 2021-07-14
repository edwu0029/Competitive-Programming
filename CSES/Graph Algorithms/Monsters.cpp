//Problem: https://cses.fi/problemset/task/1194/

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
const int MAXN = 1005;
int N, M, monster_dis[MAXN][MAXN], dis[MAXN][MAXN];
pii moves[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char moves_ch[4] = {'R', 'L', 'D', 'U'}, pre[MAXN][MAXN];
char m[MAXN][MAXN];
bool bounds(int r, int c){
    return 1<=r&&r<=N&&1<=c&&c<=M;
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> M;
    int str, stc;
    memset(dis, 0x3f, sizeof(dis));
    memset(monster_dis, 0x3f, sizeof(monster_dis));
    queue<pii>monsters, q;
    for(int i = 1;i<=N;i++){
        string s; cin >> s;
        for(int j = 1;j<=M;j++){
            m[i][j] = s[j-1];
            if(m[i][j]=='A'){
                str = i, stc = j;
                dis[i][j] = 0;
                q.push(mp(i, j));
            }else if(m[i][j]=='M'){
                monster_dis[i][j] = 0;
                monsters.push(mp(i, j));
            }
        }
    }
    while(!monsters.empty()){
        pii cur = monsters.front();
        int r = cur.first, c = cur.second;
        monsters.pop();
        for(int i = 0;i<4;i++){
            int newR = r+moves[i].first, newC = c+moves[i].second;
            if(bounds(newR, newC)&&m[newR][newC]!='#'&&monster_dis[newR][newC]>monster_dis[r][c]+1){
                monster_dis[newR][newC] = monster_dis[r][c]+1;
                monsters.push(mp(newR, newC));
            }
        }
    }
    while(!q.empty()){
        pii cur = q.front();
        int r = cur.first, c = cur.second;
        q.pop();
        for(int i = 0;i<4;i++){
            int newR = r+moves[i].first, newC = c+moves[i].second;
            if(bounds(newR, newC)&&m[newR][newC]!='#'
                &&dis[newR][newC]>dis[r][c]+1&&monster_dis[newR][newC]>dis[r][c]+1){
                pre[newR][newC] = moves_ch[i];
                dis[newR][newC] = dis[r][c]+1;
                q.push(mp(newR, newC));
            }
        }
    }
    bool possible = false;
    int edr, edc;
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=M;j++){
            if(i!=1&&i!=N&&j!=1&&j!=M) continue;
            if(dis[i][j]==inf) continue;
            possible = true;
            edr = i, edc = j;
            break;
        }
    }
    if(!possible){
        cout << "NO" << nl;
    }else{
        cout << "YES" << nl;
        cout << dis[edr][edc] << nl;
        vector<char>ans;
        while(edr!=str||edc!=stc){
            ans.push_back(pre[edr][edc]);
            if(pre[edr][edc]=='L') edc++;
            else if(pre[edr][edc]=='R') edc--;
            else if(pre[edr][edc]=='U') edr++;
            else edr--;
        }
        reverse(ans.begin(), ans.end());
        for(auto i:ans){
            cout << i;
        }
    }
    return 0;
}