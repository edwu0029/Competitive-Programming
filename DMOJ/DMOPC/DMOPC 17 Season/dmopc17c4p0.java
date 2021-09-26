/*
Catch
DMOPC '17 Contest 4 P0
https://dmoj.ca/problem/dmopc17c4p0
*/

import java.util.Scanner;

public class dmopc17c4p0 {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

        int x1 = sc.nextInt();
        int y1 = sc.nextInt();
        
        int x2 = sc.nextInt();
        int y2 = sc.nextInt();
        
        int x3 = sc.nextInt();
        int y3 = sc.nextInt();
        
        double dis1 = ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        double dis2 = ((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
        double dis3 = ((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
        
        int minim = (int)Math.min(dis1, dis2);
        int minim2 = (int)Math.min(minim, dis3);
        System.out.println(minim2);
    }
}