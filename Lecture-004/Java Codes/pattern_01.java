public class pattern_01 {
    public static void main(String args[]) throws Exception {
        int n = 4;

        // System.out.println("Enter the value of n : ");
        // Input n

        int i = 1;

        while(i <= n) {
            int j = 1;

            while(j <= n) {
                System.out.print(j + " ");
                j++;
            }

            System.out.print("\n");
            i++;
        }
    }
}
