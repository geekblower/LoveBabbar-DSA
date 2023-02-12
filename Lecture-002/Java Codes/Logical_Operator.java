public class Logical_Operator {
    public static void main(String args[]) throws Exception {
        boolean flag1 = true;
        boolean flag2 = false;

        // Logical NOT
        System.out.println(!flag1);

        // Short-Circuit AND - OR
        System.out.println(flag1 && flag2);
        System.out.println(flag1 || flag2);

        // Logical AND - OR
        System.out.println(flag1 & flag2);
        System.out.println(flag1 | flag2);

        // Logical XOR
        System.out.println(flag1 ^ flag2);
        
        // Logical Assignment
        System.out.println(flag1 &= flag2);
        System.out.println(flag1 |= flag2);
        System.out.println(flag1 ^= flag2);

    }
}
