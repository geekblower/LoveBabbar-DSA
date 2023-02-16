public class pattern_15 {
    public static void main(String args[]) throws Exception {
        int n = 4;

        // System.out.println("Enter the the value of n : ");
        // Input n

        int i = 0;

        while(i < n) {
            int j = 0;
            char count = 'A';
            count += i;

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
