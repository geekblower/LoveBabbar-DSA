public class pattern_09 {
    public static void main(String args[]) throws Exception {
        int n = 3;

        // System.out.println("Enter the value of n : ");
        // Input n

        int i = 1;
        char ch = 'A';

        while(i <= n) {
            int j = 1;

            while(j <= n) {
                System.out.print(ch + " ");
                j++;
            }

            System.out.print("\n");
            i++;
            ch++;
        }
    }
}
