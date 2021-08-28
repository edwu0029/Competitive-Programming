//Problem: https://dmoj.ca/problem/dwite07c2p5

import java.io.*;
import java.util.*;

public class dwite07c2p5 {
    static int[][]DP;
    static LinkedList<Integer>vis;
    static int ind;
    static int max;
    static int[]parent;
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        for(int g = 0;g<5;g++){
            int N = sc.nextInt();
            int M = sc.nextInt();
            int[][]F = new int[N][N];
            parent = new int[N];
            int x, y;
            for(int i = 0;i<M;i++){
                x = sc.nextInt()-1;
                y = sc.nextInt()-1;
                F[x][y] = 1;
                F[y][x] = 1;
            }
            int total = 0;
            boolean flag = false;
            for(int i = 0;i<N;i++){
                for(int d = 0;d<N;d++){
                    if(F[i][d]==1){
                        flag = false;
                        F[i][d]=0;
                        F[d][i]=0;
                        parent = new int[N];
                        parent[0]=-1;
                        parenting(F,0,N);
                        for(int k = 0;k<N;k++){
                            if(parent[k]==0){
                                flag = true;
                                break;
                            }
                        }
                        if(flag) total++;
                        F[i][d]=1;
                        F[d][i]=1;
                    }
                }
            }
            System.out.println(total/2);
        }
    }
    public static void parenting(int[][]F,int start,int N){
        for(int i = 0;i<N;i++){
            if(F[start][i]==1&&parent[i]!=-1){
                parent[i]=-1;
                parenting(F,i,N);
            }
        }
    }
}