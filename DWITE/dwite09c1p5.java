//Problem: https://dmoj.ca/problem/dwite09c1p5

import java.util.Scanner;

public class dwite09c1p5 {
    public static int[]vis;
    public static int[][]adj;
    public static int[]dis;
    public static int loop;
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

        for(int gh = 0;gh<5;gh++){
            int N = sc.nextInt();
            vis = new int[101];
            adj = new int[101][101];
            dis = new int[101];
            loop = 0;
            int x = 0; int y = 0;
            for(int i = 0;i<N;i++){
                x = sc.nextInt(); y = sc.nextInt();
                adj[x][y] = 1;
            }
            dfs(1);
            System.out.println(loop);
        }
    }
    public static void dfs(int u){
        vis[u] = 1;
        for(int i = 0;i<100;i++){
            if(adj[u][i]==0) continue;
            
            if(vis[i]==1){
                loop = Math.max(loop, dis[u]-dis[i]+1);
                return;
            }else if(vis[i]==0){
                dis[i]=dis[u]+1;
                dfs(i);
            }
        }
        vis[u]=2;
    }
}