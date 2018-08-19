import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
public class Main {
        static int[] arr;
        static int[] dp;
        static int[] sum;
        static final int mod = 20091101;
        public static void main(String[] args) throws IOException {
                BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
                int T = Integer.parseInt(br.readLine());

                for(int t=0;t<T;t++){
                        StringTokenizer stk = new StringTokenizer(br.readLine());
                        int n = Integer.parseInt(stk.nextToken());
                        int k = Integer.parseInt(stk.nextToken());
                        arr = new int[n+1];
                        sum = new int[n+1];
                        dp = new int[n+1];
                        stk = new StringTokenizer(br.readLine());
                        for(int i=1;i<=n;i++){
                                arr[i] = Integer.parseInt(stk.nextToken());
                                sum[i] += sum[i-1] + arr[i];
                                sum[i] %= k;
                        }
                        System.out.println(first(n,k)+" "+second(n,k));
                }
        }
        public static long first(int n,int k){
                long ret = 0 ;
                long[] cnt = new long[k];
                for(int i=0;i<=n;i++){
                       cnt[sum[i]] ++;
                }
                for(int i=0;i<k;i++){
                        if(cnt[i]>=2){
                                ret = (ret + (cnt[i] * (cnt[i]-1))/2)%mod;
                        }
                }
                return ret;
        }
        public static int second(int n,int k){
                int[] prev = new int[k];
                Arrays.fill(prev,-1);
                int ans = 0 ;
                for(int i=0;i<=n;i++){
                        if(i>0)
                                dp[i] = dp[i-1];
                        else
                                dp[i] = 0;
                        if( prev[sum[i]]!= -1 ){
                                dp[i] = Math.max(dp[i],dp[prev[sum[i]]]+1);
                        }
                        prev[sum[i]] = i;
                }
                return dp[n];
        }
}
