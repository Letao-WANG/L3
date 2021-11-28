package controller;

import model.Graph;
import view.Board;

import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Scanner;

import static controller.App.Dijkstra;
import static controller.App.drawBoard;

public class Execute {
    public static void main(String[] args) {
        //Lecture de la carte et cr�ation du graphe
        try {
            //TODO: obtenir le fichier qui d�crit la carte
            File myObj = new File("src/data/graph.txt");
            Scanner myReader = new Scanner(myObj);
            String data = "";
            //On ignore les deux premi�res lignes
            for (int i = 0; i < 3; i++)
                data = myReader.nextLine();

            //Lecture du nombre de lignes
            int nlines = Integer.parseInt(data.split("=")[1]);
            //Et du nombre de colonnes
            data = myReader.nextLine();
            int ncols = Integer.parseInt(data.split("=")[1]);

            //Initialisation du graphe
            Graph graph = new Graph();

            HashMap<String, Integer> groundTypes = new HashMap<String, Integer>();
            HashMap<Integer, String> groundColor = new HashMap<Integer, String>();
            data = myReader.nextLine();
            data = myReader.nextLine();
            //Lire les diff�rents types de cases
            while (!data.equals("==Graph==")) {
                String name = data.split("=")[0]; //G
                int time = Integer.parseInt(data.split("=")[1]); //1
                data = myReader.nextLine();
                String color = data; //green
                groundTypes.put(name, time);
                groundColor.put(time, color);
                data = myReader.nextLine();
            }

            //On ajoute les sommets dans le graphe (avec le bon type)
            for (int line = 0; line < nlines; line++) {
                data = myReader.nextLine();
                for (int col = 0; col < ncols; col++) {
                    graph.addVertex(groundTypes.get(String.valueOf(data.charAt(col))));
                }
            }

            // ajouter les arretes
            for (int line = 0; line < nlines; line++) {
                for (int col = 0; col < ncols; col++) {
                    int source = line * ncols + col;
                    double weight = -1;
                    ArrayList<Integer> listNeighborDest = Util.getNeighborDest(line, col, nlines, ncols);
                    for(int dest : listNeighborDest){
                        double timeDest = graph.getVertexlist().get(dest).getIndivTime();
                        double timeSrc = graph.getVertexlist().get(source).getIndivTime();

//                        double timeSrcTop = graph.getVertexlist().get(source-ncols).getIndivTime();
//                        double timeSrcRight = graph.getVertexlist().get(source+1).getIndivTime();
//                        double timeSrcLeft = graph.getVertexlist().get(source-1).getIndivTime();
//                        double timeSrcBottom = graph.getVertexlist().get(source+ncols).getIndivTime();

                        // direction horizontally or vertically
                        if(Math.abs(source-dest) == 1 || Math.abs(source-dest) == ncols){
                            weight = (timeDest + timeSrc)/2;
                        }
                        // direction  diagonal
                        // direction right top
//                        else if(dest - source == -ncols+1){
//                            double weight1 = Math.sqrt(Math.pow(graph.getVertexlist().get(source-ncols).getIndivTime(),2)
//                                    +Math.pow(,2));
//                        }
                        if(weight != -1){
                            graph.addEgde(source, dest, weight);
                        }
                    }
                }
            }

            //On obtient les noeuds de d�part et d'arriv�
            data = myReader.nextLine();
            data = myReader.nextLine();
            int startV = Integer.parseInt(data.split("=")[1].split(",")[0]) * ncols + Integer.parseInt(data.split("=")[1].split(",")[1]);
            data = myReader.nextLine();
            int endV = Integer.parseInt(data.split("=")[1].split(",")[0]) * ncols + Integer.parseInt(data.split("=")[1].split(",")[1]);

            myReader.close();

            //A changer pour avoir un affichage plus ou moins grand
            int pixelSize = 10;
            Board board = new Board(graph, pixelSize, ncols, nlines, groundColor, startV, endV);
            drawBoard(board, nlines, ncols, pixelSize);
            board.repaint();

            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                System.out.println("stop");
            }

            //On appelle Dijkstra
            LinkedList<Integer> path = Dijkstra(graph, startV, endV, nlines * ncols, board);
            //TODO: laisser le choix entre Dijkstra et A*

            //�criture du chemin dans un fichier de sortie
            try {
                File file = new File("out.txt");
                if (!file.exists()) {
                    file.createNewFile();
                }
                FileWriter fw = new FileWriter(file.getAbsoluteFile());
                BufferedWriter bw = new BufferedWriter(fw);

                for (int i : path) {
                    bw.write(String.valueOf(i));
                    bw.write('\n');
                }
                bw.close();

            } catch (IOException e) {
                e.printStackTrace();
            }
        } catch (FileNotFoundException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }
}
