import java.util.Scanner;

public class Lowercase_Uppercase_Number {
    public static void main(String args[]) throws Exception {
        Scanner scn = new Scanner(System.in);
        
        System.out.print("Enter the value of n : ");
        char ch = scn.next().charAt(0);

        if(ch>='A' && ch<='Z') {
            System.out.println("Uppercase Character!");
        } else if(ch>='a' && ch<='z') {
            System.out.println("Lowercase Character!");
        } else if(ch>='0' && ch<='9') {
            System.out.println("Number!");
        } else {
            System.out.println("Special character!");
        }
    }
}
