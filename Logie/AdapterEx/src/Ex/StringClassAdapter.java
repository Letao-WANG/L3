package Ex;

public class StringClassAdapter extends IntegerClassB{
    private StringClass stringClassC;

    public StringClassAdapter(StringClass stringClassC) {
        super();
        this.stringClassC = stringClassC;
    }

    @Override
    public int getValue(){
        return Integer.parseInt(stringClassC.getValue());
    }
}
