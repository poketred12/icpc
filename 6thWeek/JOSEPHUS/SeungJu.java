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
            Queue<Integer> q = new LinkedList<>();
            for(int i=0;i<n;i++){
                ((LinkedList<Integer>) q).add(i+1);
            }
            q.poll();
            while(q.size()>2){
                for(int i=0;i<k-1;i++){
                    ((LinkedList<Integer>) q).add(q.poll());
                }
                q.poll();
            }
            int a1 = q.poll();
            int b1 = q.poll();
            System.out.println(Math.min(a1,b1)+" "+Math.max(a1,b1));
        }
    }
}
