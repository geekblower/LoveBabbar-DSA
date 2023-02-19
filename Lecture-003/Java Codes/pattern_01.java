import java.util.Scanner;

public class pattern_01 {
    public static void main(String args[]) throws Exception {
        Scanner scn = new Scanner(System.in);

        System.out.print("Enter the value of n : ");
        int n = scn.nextInt();

        int i = 0;

        while(i < n) {
            int j = 0;

            while(j < n) {
                System.out.print("* ");
                j++;
            }

            System.out.print("\n");
            i++;
        }
    }
}
