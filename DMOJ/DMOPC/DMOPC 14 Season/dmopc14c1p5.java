/*
Surprise Teleport
DMOPC '14 Contest 1 P5
https://dmoj.ca/problem/dmopc14c1p5
*/

import java.util.*;
import java.io.*;

public class dmopc14c1p5 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static char[][]cage;
    public static int[][]room;
    public static void main(String args[]) throws IOException{
        int R = readInt(); int C = readInt();
        int str = readInt(); int stc = readInt();
        int mainr = readInt(); int mainc = readInt();

        char[][]F = new char[R][C];
        String temp = "";
        for(int i =0;i<R;i++){
            temp = br.readLine();
            for(int d = 0;d<C;d++){
                F[i][d]=temp.charAt(d);
            }
        }
        LinkedList<Integer>lr = new LinkedList<Integer>(); LinkedList<Integer>lc = new LinkedList<Integer>();
        int[][]dis = new int[R][C];
        for(int i = 0;i<R;i++){
            for(int d = 0;d<C;d++){
                dis[i][d]=Integer.MAX_VALUE;
            }
        }
        dis[str][stc]=0;
        lr.add(str); lc.add(stc);
        int curR = 0, curC = 0;
        while(!lr.isEmpty()){
            curR = lr.poll(); curC = lc.poll();
            if(curR==mainr&&curC==mainc){
                break;
            }
            if(curR+1<R&&dis[curR+1][curC]==Integer.MAX_VALUE&&F[curR+1][curC]!='X'){
                lr.add(curR+1); lc.add(curC);
                dis[curR+1][curC] = dis[curR][curC]+1;
            }
            if(curR-1>=0&&dis[curR-1][curC]==Integer.MAX_VALUE&&F[curR-1][curC]!='X'){
                lr.add(curR-1); lc.add(curC);
                dis[curR-1][curC] = dis[curR][curC]+1;
            }
            if(curC+1<C&&dis[curR][curC+1]==Integer.MAX_VALUE&&F[curR][curC+1]!='X'){
                lr.add(curR); lc.add(curC+1);
                dis[curR][curC+1] = dis[curR][curC]+1;
            }
            if(curC-1>=0&&dis[curR][curC-1]==Integer.MAX_VALUE&&F[curR][curC-1]!='X'){
                lr.add(curR); lc.add(curC-1);
                dis[curR][curC-1] = dis[curR][curC]+1;
            }
        }
        int T = readInt();
        int min = Integer.MAX_VALUE,tempr,tempc;
        for(int i = 0;i<T;i++){
            tempr = readInt(); tempc = readInt();
            if(dis[tempr][tempc]<min)
                min = dis[tempr][tempc];
        }
        System.out.println(dis[mainr][mainc]-min);
         
    }
    public static void roomgroup(int startx, int starty, int temp, int R, int C){
        room[startx][starty]=temp;
        if(startx+1<R&&room[startx+1][starty]==0&&cage[startx+1][starty]!='#'){
            roomgroup(startx+1,starty,temp,R,C);
        }
        if(startx-1>=0&&room[startx-1][starty]==0&&cage[startx-1][starty]!='#'){
            roomgroup(startx-1,starty,temp,R,C);
        }
        if(starty+1<C&&room[startx][starty+1]==0&&cage[startx][starty+1]!='#'){
            roomgroup(startx,starty+1,temp,R,C);
        }
        if(starty-1>=0&&room[startx][starty-1]==0&&cage[startx][starty-1]!='#'){
            roomgroup(startx,starty-1,temp,R,C);
        }
    }
    static String next () throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static int readInt () throws IOException {
        return Integer.parseInt(next());
    }
}