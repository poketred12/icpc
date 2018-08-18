import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
public class Main {
        public static void main(String[] args) throws IOException {
                BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
                int T = Integer.parseInt(br.readLine());

                for(int t=0;t<T;t++){
                        StringTokenizer stk = new StringTokenizer(br.readLine());
                        int n = Integer.parseInt(stk.nextToken());
                        int k = Integer.parseInt(stk.nextToken());
                        int m = Integer.parseInt(stk.nextToken());
                        int l = Integer.parseInt(stk.nextToken());
                        int[] selector = new int[n+1];
                        int[][] dp = new int[m+1][(1<<n)+1];
                        for(int i=0;i<=m;i++){
                                Arrays.fill(dp[i],1000000000);
                        }
                        ArrayList<ArrayList<Integer>> arr = new ArrayList<ArrayList<Integer>>();
                        for(int i=0;i<n;i++){
                                stk = new StringTokenizer(br.readLine().trim());
                                int cc = Integer.parseInt(stk.nextToken());
                                for(int j=0;j<cc;j++){
                                       selector[i] |= 1 << (Integer.parseInt(stk.nextToken()));
                                }
                        }
                        int [] semester = new int[m+1];
                        int [][] list = new int[m+1][];
                        int max = 1<<n;
                        ArrayList<ArrayList<Integer>> arr2 = new ArrayList<ArrayList<Integer>>();
                        arr2.add(new ArrayList<Integer>());
                        ArrayList<ArrayList<Integer>> arr3 = new ArrayList<ArrayList<Integer>>();
                        arr3.add(new ArrayList<Integer>());

                        for(int i=1;i<=m;i++){
                                ArrayList<Integer> newA = new ArrayList<Integer>();
                                arr2.add(newA);
                                ArrayList<Integer> newB = new ArrayList<Integer>();
                                arr3.add(newB);
                                stk = new StringTokenizer(br.readLine().trim());
                                int c = Integer.parseInt(stk.nextToken());
                                list[i] = new int[c];
                                for(int j=0;j<c;j++){
                                        int v = (Integer.parseInt(stk.nextToken()));
                                        semester[i] |= 1<< v;
                                        list[i][j] = v;
                                }
                                for(int p=1;p<=max;p++) {
                                        int value = 0;
                                        if ((semester[i] & p) == p && getCount(p) <= l) {
                                                for(int j=0;j<n;j++){
                                                        if((p & (1<<j))== (1<<j)){
                                                                value |= selector[j];
                                                        }
                                                }
                                                newA.add(p);
                                                newB.add(value);
                                        }
                                }
                                //System.out.println(semester[i]);
                        }
                        int ans = 1000000000;
                        dp[0][0] = 0;
                        for(int i=1;i<=m;i++){
                                int value = semester[i];

                                for(int j=0; j<=max;j++){
                                        dp[i][j] = dp[i-1][j];
                                }
                                for(int j=0;j<=max;j++){
                                        for(int p =0 ; p <  arr2.get(i).size();p++){
                                                             //          System.out.println(i+" "+j+" "+selector[q]+" "+q+" "+p);
                                                        if((j & arr3.get(i).get(p))== arr3.get(i).get(p) &&  dp[i-1][j] != 1000000000){
                                                                dp[i][j|arr2.get(i).get(p)] = Math.min(dp[i][j|arr2.get(i).get(p)],dp[i-1][j]+1);
                                                        }
                                        }
                                        if(getCount(j)>=k){
                                                ans = Math.min(ans,dp[i][j]);
                                        }
                                }
                        }
                        if(ans!=1000000000){
                                System.out.println(ans);
                        }
                        else
                                System.out.println("IMPOSSIBLE");

                }
        }
        public static int getCount(int value){
                int cnt = 0 ;
                while(value>0){
                        cnt += value%2;
                        value/=2;
                }
                return cnt;
        }
}
