import java.util.Scanner;

public class pattern_09 {
    public static void main(String args[]) throws Exception {
        Scanner scn = new Scanner(System.in);

        System.out.print("Enter the value of n : ");
        int n = scn.nextInt();

        int i = 1;
        char ch = 'A';

        while(i <= n) {
            int j = 1;

            while(j <= n) {
                System.out.print(ch + " ");
                j++;
            }

            System.out.print("\n");
            i++;
            ch++;
        }
    }
}
