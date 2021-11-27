// Par Sylvain Lobry, pour le cours "IF05X040 Algorithmique avanc�e"
// de l'Universit� de Paris, 11/2020
package controller;

import model.Graph;

// Classe d�finissant un graphe pond�r�.
public class WeightedGraph {
    //Test de la classe.
      public static void main(String[] args) {
            int vertices = 6;
            Graph graph = new Graph();
            graph.addVertex(10);
            graph.addVertex(10);
            graph.addVertex(10);
            graph.addVertex(10);
            graph.addVertex(10);
            graph.addVertex(10);
            graph.addEgde(0, 1, 4);
            graph.addEgde(0, 2, 3);
            graph.addEgde(1, 3, 2);
            graph.addEgde(1, 2, 5);
            graph.addEgde(2, 3, 7);
            graph.addEgde(3, 4, 2);
            graph.addEgde(4, 0, 4);
            graph.addEgde(4, 1, 4);
            graph.addEgde(4, 5, 6);
            //graph.printGraph();
        }
}
