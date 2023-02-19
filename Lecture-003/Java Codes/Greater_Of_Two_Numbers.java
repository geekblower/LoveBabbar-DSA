import java.util.Scanner;

public class Greater_Of_Two_Numbers {
    public static void main(String args[]) throws Exception {
        Scanner scn = new Scanner(System.in);

        System.out.print("Enter the value of a : ");
        int a = scn.nextInt();
        System.out.print("Enter the value of a : ");
        int b = scn.nextInt();

        if(a>b) {
            System.out.println("a is greater !");
        } else {
            System.out.println("b is greater !");
        }
    }
}
