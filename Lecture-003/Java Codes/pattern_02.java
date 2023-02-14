public class pattern_02 {
    public static void main(String args[]) throws Exception {
        int n = 4;

        // System.out.println("Enter the value of n : ");
        // Input n

        int i = 1;

        while(i <= n) {
            int j = 0;

            while(j < n) {
                System.out.print(i + " ");
                j++;
            }

            System.out.print("\n");
            i++;
        }
    }
}
