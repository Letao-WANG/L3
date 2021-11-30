package controller;// Par Sylvain Lobry, pour le cours "IF05X040 Algorithmique avanc�e"
// de l'Universit� de Paris, 11/2020

import model.Graph;
import model.Vertex;
import view.Board;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

import javax.swing.JFrame;

//Classe principale. C'est ici que vous devez faire les modifications
public class App {
    //Initialise l'affichage
    public static void drawBoard(Board board, int nlines, int ncols, int pixelSize) {
        JFrame window = new JFrame("Plus court chemin");
        window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        window.setBounds(50, 50, ncols * pixelSize + 20, nlines * pixelSize + 40);
        window.getContentPane().add(board);
        window.setVisible(true);
    }

    //M�thode A*
    //graph: le graphe repr�sentant la carte
    //start: un entier repr�sentant la case de d�part
    //       (entier unique correspondant � la case obtenue dans le sens de la lecture)
    //end: un entier repr�sentant la case d'arriv�e
    //       (entier unique correspondant � la case obtenue dans le sens de la lecture)
    //ncols: le nombre de colonnes dans la carte
    //numberV: le nombre de cases dans la carte
    //board: l'affichage
    //retourne une liste d'entiers correspondant au chemin.
    public static LinkedList<Integer> AStar(Graph graph, int start, int end, int ncols, int numberV, Board board) {
        graph.getVertexlist().get(start).setTimeFromSource(0);
        int number_tries = 0;

        //mettre tous les noeuds du graphe dans la liste des noeuds � visiter:
        HashSet<Integer> to_visit = new HashSet<Integer>();
        for(Vertex v : graph.getVertexlist()){
            to_visit.add(v.getNum());
        }
        // Remplir l'attribut graph.vertexlist.get(v).heuristic pour tous les noeuds v du graphe:
        int lineEnd = end/ncols;
        int colEnd = end%ncols;
        for(Vertex v : graph.getVertexlist()){
            int lineV = v.getNum()/ncols;
            int colV = v.getNum()%ncols;
            v.setHeuristic(Util.getEuclideanDistance(lineEnd, lineV, colEnd, colV)*0.5);
        }

        while (to_visit.contains(end)) {
            // trouver le noeud min_v parmis tous les noeuds v ayant la distance temporaire
            //      (graph.vertexlist.get(v).timeFromSource + heuristic) minimale.

            //On l'enl�ve des noeuds � visiter
            ////////////////////////// TO CHANGE !!!!
            int min_v = start;
            double fmin = Double.POSITIVE_INFINITY;
            for(Vertex v : graph.getVertexlist()){
                if(v.getTimeFromSource() + v.getHeuristic() < fmin && to_visit.contains(v.getNum())) {
                    fmin = v.getTimeFromSource() + v.getHeuristic();
                    min_v = v.getNum();
                }
            }
            to_visit.remove(min_v);
            number_tries += 1;

            //pour tous ses voisins, on v�rifie si on est plus rapide en passant par ce noeud.
            for (int i = 0; i < graph.getVertexlist().get(min_v).getAdjacencylist().size(); i++) {
                int to_try = graph.getVertexlist().get(min_v).getAdjacencylist().get(i).getDestination();
                // to_try node timeFromSource += weight
                if(to_visit.contains(to_try)){
                    double newTimeFromSource = graph.getVertexlist().get(min_v).getTimeFromSource()
                            + graph.getVertexlist().get(min_v).getAdjacencylist().get(i).getWeight();

                    if (newTimeFromSource < graph.getVertexlist().get(to_try).getTimeFromSource()) {
                        graph.getVertexlist().get(to_try).setTimeFromSource(newTimeFromSource);
                        graph.getVertexlist().get(to_try).setPrev(graph.getVertexlist().get(min_v));
                    }
                }
            }
            //On met � jour l'affichage
            try {
                board.update(graph, min_v);
                Thread.sleep(1);
            } catch (InterruptedException e) {
                System.out.println("stop");
            }

        }

        System.out.println("Done! Using A*:");
        System.out.println("	Number of nodes explored: " + number_tries);
        System.out.println("	Total time of the path: " + graph.getVertexlist().get(end).getTimeFromSource());
        LinkedList<Integer> path = new LinkedList<Integer>();
        path.addFirst(end);
        //TODO: remplir la liste path avec le chemin

        board.addPath(graph, path);
        return path;
    }

    //M�thode Dijkstra
    //graph: le graphe repr�sentant la carte
    //start: un entier repr�sentant la case de d�part
    //       (entier unique correspondant � la case obtenue dans le sens de la lecture)
    //end: un entier repr�sentant la case d'arriv�e
    //       (entier unique correspondant � la case obtenue dans le sens de la lecture)
    //numberV: le nombre de cases dans la carte
    //board: l'affichage
    //retourne une liste d'entiers correspondant au chemin.
    public static LinkedList<Integer> Dijkstra(Graph graph, int start, int end, int numberV, Board board) {
        graph.getVertexlist().get(start).setTimeFromSource(0);
        int number_tries = 0;

        //mettre tous les noeuds du graphe dans la liste des noeuds � visiter:
        HashSet<Integer> to_visit = new HashSet<Integer>();
        for(Vertex v : graph.getVertexlist()){
            to_visit.add(v.getNum());
        }
        int min_v = start;
        while (to_visit.contains(end)) {
            //trouver le noeud min_v parmis tous les noeuds v ayant la distance temporaire
            //      graph.vertexlist.get(v).timeFromSource minimale.

            //On l'enleve des noeuds a visiter
            //get vertex with min dist
            double minTimeDist = Double.POSITIVE_INFINITY;
            for(Vertex v : graph.getVertexlist()){
                if(v.getTimeFromSource() < minTimeDist && to_visit.contains(v.getNum())) {
                    minTimeDist = v.getTimeFromSource();
                    min_v = v.getNum();
                }
            }
            to_visit.remove(min_v);
            number_tries += 1;

            //pour tous ses voisins, on verifie si on est plus rapide en passant par ce noeud.
            for (int i = 0; i < graph.getVertexlist().get(min_v).getAdjacencylist().size(); i++) {
                int to_try = graph.getVertexlist().get(min_v).getAdjacencylist().get(i).getDestination();
                // to_try node timeFromSource += weight
                if(to_visit.contains(to_try)){
                    double newTimeFromSource = graph.getVertexlist().get(min_v).getTimeFromSource()
                            + graph.getVertexlist().get(min_v).getAdjacencylist().get(i).getWeight();

                    if (newTimeFromSource < graph.getVertexlist().get(to_try).getTimeFromSource()) {
                        graph.getVertexlist().get(to_try).setTimeFromSource(newTimeFromSource);
                        graph.getVertexlist().get(to_try).setPrev(graph.getVertexlist().get(min_v));
                    }
                }
            }
            //On met � jour l'affichage
            try {
                board.update(graph, min_v);
                Thread.sleep(10);
            } catch (InterruptedException e) {
                System.out.println("stop");
            }
        }

        System.out.println("Done! Using Dijkstra:");
        System.out.println("	Number of nodes explored: " + number_tries);
        System.out.println("	Total time of the path: " + graph.getVertexlist().get(end).getTimeFromSource());
        LinkedList<Integer> path = new LinkedList<Integer>();
        //remplir la liste path avec le chemin
        Vertex node = graph.getVertexlist().get(end);
        while(node.getNum() != 0){
            path.addFirst(node.getNum());
            node = node.getPrev();
        }
        board.addPath(graph, path);
        return path;
    }

}
