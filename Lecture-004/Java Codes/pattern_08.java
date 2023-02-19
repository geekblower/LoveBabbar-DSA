import java.util.Scanner;

public class pattern_08 {
    public static void main(String args[]) throws Exception {
        Scanner scn = new Scanner(System.in);

        System.out.print("Enter the value of n : ");
        int n = scn.nextInt();

        int i = 1;

        while(i <= n) {
            int j = i;

            while(j > 0) {
                System.out.print(j + " ");
                j--;
            }

            System.out.print("\n");
            i++;
        }
    }
}
