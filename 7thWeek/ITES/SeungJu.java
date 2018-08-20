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
                        int k = Integer.parseInt(stk.nextToken());
                        int n = Integer.parseInt(stk.nextToken());
                        long max = 1l << 32;
                        int ans = 0 ;
                        long sum = 0 ;
                        Queue<Long> q = new LinkedList<Long>();
                        long prev = 1983;
                        long prev2 = 0;
                        for(int i=1;i<=n;i++){
                                long signal = prev % 10000 + 1;
                                prev = (prev*214013 + 2531011) % max;

                                if(signal+ sum < k ){
                                        sum += signal;
                                        q.add(signal);
                                }
                                else{
                                        sum += signal;
                                        q.add(signal);
                                        while(!q.isEmpty() && sum>= k) {
                                                if(sum == k){
                                                        ans++;
                                                }
                                                sum -= q.poll();
                                        }
                                }
                        }
                        System.out.println(ans);
                }
        }
}
