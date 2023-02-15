public class pattern_10 {
    public static void main(String args[]) throws Exception {
        int n = 4;

        // System.out.println("Enter the value of n : ");
        // Input n

        int i = 1;

        while(i <= n) {
            int j = 1;
            char ch = 'A';

            while(j <= n) {
                System.out.print(ch + " ");
                j++;
                ch++;
            }

            System.out.print("\n");
            i++;
        }
    }
}
