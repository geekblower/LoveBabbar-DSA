import java.util.Scanner;

public class pattern_06 {
    public static void main(String args[]) throws Exception {
        Scanner scn = new Scanner(System.in);

        System.out.print("Enter the value of n : ");
        int n = scn.nextInt();

        int i = 1;
        int count = 1;

        while(i <= n) {
            int j = 1;

            while(j <= i) {
                System.out.print(count + " ");
                j++;
                count++;
            }

            System.out.print("\n");
            i++;
        }
    }
}
