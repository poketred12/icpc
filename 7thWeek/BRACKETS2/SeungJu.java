import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
public class Main {
        static char[] map = new char[255];
        public static void main(String[] args) throws IOException {
                BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
                int T = Integer.parseInt(br.readLine());
                map[')'] = '(';
                map[']'] = '[';
                map['}'] = '{';
                for(int t=0;t<T;t++){
                        if(checkString(br.readLine())){
                                System.out.println("YES");
                        }
                        else
                                System.out.println("NO");
                }
        }
        public static boolean checkString(String a){
                Stack<Character> stack = new Stack<Character>();
                int len = a.length();
                for(int i=0;i<len;i++){
                        char c = a.charAt(i);
                        if(c == ')' || c==']' || c=='}'){
                                if(stack.isEmpty()) return false;
                                if(stack.peek()==map[c]){
                                        stack.pop();
                                }
                        }
                        else{
                                stack.push(c);
                        }
                }
                if(stack.size()==0) return true;
                else return false;
        }
}
