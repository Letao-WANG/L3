import java.io.IOException;

public class GraphTest {
    public static void main(String[] args) throws IOException {
        GraphGenerate graphGenerate = new GraphGenerate();
        graphGenerate.createGraph();
        graphGenerate.givenAdaptedGraph_whenWriteBufferedImage_thenFileShouldExist();
    }
}
