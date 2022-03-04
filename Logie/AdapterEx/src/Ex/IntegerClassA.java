package Ex;

public class IntegerClassA {
    private int value;

    public IntegerClassA(int value) {
        this.value = value;
    }

    public int sommeWithB(IntegerClassB b){
        return this.value + b.getValue();
    }
}
