package controller;

import java.util.ArrayList;

public class Util {
    /**
     * For getting all max to 8 neighbors('s num) of this vertex
     * @param line line of source
     * @param col col of source
     * @param nlines number of lines
     * @param ncols number of cols
     * @return list of neighbors vertex
     */
    public static ArrayList<Integer> getNeighborDest(int line, int col, int nlines, int ncols) {
        ArrayList<Integer> listNeighbor = new ArrayList<>();

        // line col
        // top left
        if(line == 0 && col == 0 ){
            listNeighbor.add((line) * ncols + col+1);
            listNeighbor.add((line+1) * ncols + col);
            listNeighbor.add((line+1) * ncols + col+1);
        }
        // top middle
        else if(line == 0 && col != 0 && col != ncols-1){
            listNeighbor.add((line) * ncols + col-1);
            listNeighbor.add((line) * ncols + col+1);

            listNeighbor.add((line+1) * ncols + col-1);
            listNeighbor.add((line+1) * ncols + col);
            listNeighbor.add((line+1) * ncols + col+1);
        }
        // top right
        else if(line == 0 && col == ncols-1 ){
            listNeighbor.add((line) * ncols + col-1);
            listNeighbor.add((line+1) * ncols + col);
            listNeighbor.add((line+1) * ncols + col-1);
        }

        // middle left
        else if(line != 0 && line != nlines-1 && col == 0 ){
            listNeighbor.add((line-1) * ncols + col);
            listNeighbor.add((line+1) * ncols + col);

            listNeighbor.add((line-1) * ncols + col+1);
            listNeighbor.add((line) * ncols + col+1);
            listNeighbor.add((line+1) * ncols + col+1);
        }

        // middle middle
        else if(line != 0 && line != nlines-1 && col != 0 && col != ncols-1){
            for (int i = -1; i < 2; i++) {
                for (int j = -1; j < 2; j++) {
                    if(i == 0 && j == 0) continue;
                    listNeighbor.add((line + i) * ncols + col + j);
                }
            }
        }

        // middle right
        else if(line != 0 && line != nlines-1 && col == ncols-1 ){
            listNeighbor.add((line-1) * ncols + col);
            listNeighbor.add((line+1) * ncols + col);

            listNeighbor.add((line-1) * ncols + col-1);
            listNeighbor.add((line) * ncols + col-1);
            listNeighbor.add((line+1) * ncols + col-1);
        }

        // bottom left
        else if(line == nlines-1 && col == 0 ){
            listNeighbor.add((line-1) * ncols + col);
            listNeighbor.add((line-1) * ncols + col+1);
            listNeighbor.add((line) * ncols + col+1);
        }

        // bottom middle
        else if(line == nlines-1 && col != 0 && col != ncols-1){
            listNeighbor.add((line) * ncols + col-1);
            listNeighbor.add((line) * ncols + col+1);

            listNeighbor.add((line-1) * ncols + col-1);
            listNeighbor.add((line-1) * ncols + col);
            listNeighbor.add((line-1) * ncols + col+1);
        }

        // bottom right
        else if(line == nlines-1 && col == ncols-1 ){
            listNeighbor.add((line-1) * ncols + col);
            listNeighbor.add((line-1) * ncols + col-1);
            listNeighbor.add((line) * ncols + col-1);
        }

        return listNeighbor;
    }
}
