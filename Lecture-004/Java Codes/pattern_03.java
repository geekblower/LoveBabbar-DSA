public class pattern_03 {
    public static void main(String args[]) throws Exception {
        int n = 3;

        // System.out.println("Enter the value of n : ");
        // Input n

        int i = 1;
        int count = 1;

        while(i <= n) {
            int j = 1;

            while(j <= n) {
                System.out.print(count + " ");
                j++;
                count++;
            }

            System.out.print("\n");
            i++;
        }
    }
}
