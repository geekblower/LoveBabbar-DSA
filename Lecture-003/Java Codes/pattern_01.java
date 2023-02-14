public class pattern_01 {
    public static void main(String args[]) throws Exception {
        int n = 4;

        // System.out.println("Enter the value of n : ");
        // Input n

        int i = 0;

        while(i < n) {
            int j = 0;

            while(j < n) {
                System.out.print("* ");
                j++;
            }

            System.out.print("\n");
            i++;
        }
    }
}
