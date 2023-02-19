import java.util.Scanner;

public class pattern_14 {
    public static void main(String args[]) throws Exception {
        Scanner scn = new Scanner(System.in);

        System.out.print("Enter the value of n : ");
        int n = scn.nextInt();

        int i = 0;
        char count = 'A';

        while(i < n) {
            int j = 0;

            while(j <= i) {
                System.out.print(count + " ");
                count++;
                j++;
            }

            System.out.print("\n");
            i++;
        }
    }
}
