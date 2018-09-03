import java.util.*;
import java.io.*;
public class Main{
        static int[] preOrder;
        static int[] midOrder;
        static int[] tree;
        static int pre = 1;
        public static void main(String[] args) throws  IOException {
                BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
                int T = Integer.parseInt(br.readLine());
                for(int t=1;t<=T;t++) {
                        int n = Integer.parseInt(br.readLine());
                        preOrder = new int[n+1];
                        midOrder = new int[n+1];
                        tree = new int[10000];
                        pre = 1;
                        Arrays.fill(tree,-1);
                        StringTokenizer stk = new StringTokenizer(br.readLine());
                        for(int i=1;i<=n;i++){
                                preOrder[i] = Integer.parseInt(stk.nextToken());
                        }
                        stk = new StringTokenizer(br.readLine());
                        for(int i=1;i<=n;i++){
                                midOrder[i] = Integer.parseInt(stk.nextToken());
                        }
                        tree[1] = preOrder[1];
                        go(1,1,n,n);
                        System.out.println();
                }
        }
        public static void go(int rootNumber,int left,int right,int n){
                int index = 0;
                if(left>right) return;
                if(left <=0 || right <=0) return;
                if(right>n || left >n)return;
                if(pre > n ) return;
                int temp = pre;
                pre++;
              //  System.out.println(left+" "+right+" "+pre);
                for(int i=1;i<=n;i++){
                        if(preOrder[temp] == midOrder[i]){
                                index = i;
                                break;
                        }
                }

                go(rootNumber,left,index-1,n);
                go(rootNumber,index+1,right,n);
                System.out.print(preOrder[temp]+" ");
        }
}
