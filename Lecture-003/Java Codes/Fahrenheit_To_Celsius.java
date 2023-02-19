import java.util.Scanner;

public class Fahrenheit_To_Celsius {
    public static void main(String args[]) throws Exception {
        Scanner scn = new Scanner(System.in);

        System.out.print("Enter the temperature in fahrenheit : ");
        float f = scn.nextFloat();

        float c = ((f-32) * 5) / 9;
        System.out.println("Temperature in celsius : " + c);
    }
}
