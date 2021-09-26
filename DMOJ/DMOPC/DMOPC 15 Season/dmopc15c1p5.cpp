/*
Lelei and Dragon Scales
DMOPC '15 Contest 1 P5
https://dmoj.ca/problem/dmopc15c1p5
*/

#include <bits/stdc++.h>
using namespace std;
int W, H, N, ans, tmp, F[300][300], pre[300][300];
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> W >> H >> N;
    for (int i=1;i<=H;i++){
        for (int j=1;j<=W;j++) cin >> F[j][i];
    }
    for (int i=1;i<=W; i++){
        for (int j=1;j<=H;j++){
            pre[i][j]=F[i][j] + pre[i -1][j]+pre[i][j-1]-pre[i-1][j-1];
        }
    }
    for (int n = 1;n<=N;n++){
        for (int i=1;i<=W;i++){
            for (int j=1;j<= H;j++){
                int x=n, y=N/n;
                if (i+x-1<=W&&j+y-1<=H){
                    tmp = pre[i+x-1][j+y-1]-pre[i-1][j+y-1]-pre[i+x-1][j-1]+pre[i-1][j-1];
                    ans = max(ans, tmp);
                }else break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}