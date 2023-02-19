import java.util.Scanner;

public class Sum_Of_Even_Numbers_1_to_N {
    public static void main(String args[]) throws Exception {
        Scanner scn = new Scanner(System.in);

        System.out.print("Enter the value of n : ");
        int n = scn.nextInt();

        int i = 1;
        int sum = 0;
        while(i<=n) {
            sum += i;
            i++;
        }

        System.out.print("Sum of first n numbers : " + sum);
    }
}
