public class pattern_12 {
    public static void main(String args[]) throws Exception {
        int n = 3;

        // System.out.println("Enter the the value of n : ");
        // Input n

        int i = 1;

        while(i <= n) {
            int j = 1;
            char count = 64;
            count += i;

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
