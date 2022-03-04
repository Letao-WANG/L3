package Ex;

public class TestAdapter {
    public static void main(String[] args) {
        IntegerClassA integerClassA = new IntegerClassA(10);
        StringClass stringClassC = new StringClass("20");
        StringClassAdapter classAdapter = new StringClassAdapter(stringClassC);
        System.out.println(integerClassA.sommeWithB(classAdapter));
    }
}
