public class pattern_11 {
    public static void main(String args[]) throws Exception {
        int n = 3;

        // System.out.println("Enter the the value of n : ");
        // Input n

        int i = 1;
        char count = 'A';

        while(i <= n) {
            int j = 1;

            while(j <= n) {
                System.out.print(count + " ");
                count++;
                j++;
            }

            System.out.print("\n");
            i++;
        }
    }
}
