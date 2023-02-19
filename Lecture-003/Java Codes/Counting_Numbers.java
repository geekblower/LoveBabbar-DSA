import java.util.Scanner;

public class Counting_Numbers {
    public static void main(String args[]) throws Exception {
        Scanner scn = new Scanner(System.in);

        System.out.print("Enter the value of n : ");
        int n = scn.nextInt();

        int i = 1;
        while(i <= n) {
            System.out.printf(i + " ");
            i++;
        }
    }
}
