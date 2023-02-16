public class pattern_13 {
    public static void main(String args[]) throws Exception {
        int n = 3;

        // System.out.println("Enter the the value of n : ");
        // Input n

        int i = 0;

        while(i < n) {
            int j = 0;
            char count = 'A';
            count += i;

            while(j <= i) {
                System.out.print(count + " ");
                j++;
            }

            System.out.print("\n");
            i++;
        }
    }
}
