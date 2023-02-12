public class Signed_And_Unsigned_Datatypes {
    public static void main(String args[]) throws Exception {
        
        byte b = -10;

        int x = Byte.toUnsignedInt(b);

        System.out.println("Signed value in byte = " + b);
        System.out.println("Unsigned value in byte = " + x);

    }
}
