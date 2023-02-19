import java.util.Scanner;

public class Check_Positive_Negative_Zero {
    public static void main(String args[]) throws Exception {
        Scanner scn = new Scanner(System.in);

        System.out.print("Enter the value of n : ");
        int n = scn.nextInt();

        if(n>0) {
            System.out.println("Positive Number!");
        } else if(n<0) {
            System.out.println("Negative Number!");
        } else {
            System.out.println("Zero!");
        }
    }
}