public class pattern_08 {
    public static void main(String args[]) throws Exception {
        int n = 4;

        // System.out.println("Enter the value of n : ");
        // Input n

        int i = 1;

        while(i <= n) {
            int j = i;

            while(j > 0) {
                System.out.print(j + " ");
                j--;
            }

            System.out.print("\n");
            i++;
        }
    }
}
