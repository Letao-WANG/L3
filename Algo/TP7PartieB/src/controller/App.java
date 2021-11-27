package controller;// Par Sylvain Lobry, pour le cours "IF05X040 Algorithmique avanc�e"
// de l'Universit� de Paris, 11/2020

import model.Graph;
import view.Board;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.HashSet;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

import javax.swing.JFrame;

//Classe principale. C'est ici que vous devez faire les modifications
public class App {
	
	//Initialise l'affichage
	private static void drawBoard(Board board, int nlines, int ncols, int pixelSize)
	{
	    JFrame window = new JFrame("Plus court chemin");
	    window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	    window.setBounds(0, 0, ncols*pixelSize+20, nlines*pixelSize+40);
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
	private static LinkedList<Integer> AStar(Graph graph, int start, int end, int ncols, int numberV, Board board)
	{
		graph.getVertexlist().get(start).setTimeFromSource(0);
		int number_tries = 0;
		
		//TODO: mettre tous les noeuds du graphe dans la liste des noeuds � visiter:
		HashSet<Integer> to_visit = new HashSet<Integer>();
		
		//TODO: Remplir l'attribut graph.vertexlist.get(v).heuristic pour tous les noeuds v du graphe:
		
		
		while (to_visit.contains(end))
		{
			//TODO: trouver le noeud min_v parmis tous les noeuds v ayant la distance temporaire
			//      (graph.vertexlist.get(v).timeFromSource + heuristic) minimale.
			
			//On l'enl�ve des noeuds � visiter
			////////////////////////// TO CHANGE !!!!
			int min_v = 0;
			to_visit.remove(min_v);
			number_tries += 1;
			
			//TODO: pour tous ses voisins, on v�rifie si on est plus rapide en passant par ce noeud.
			for (int i = 0; i < graph.getVertexlist().get(min_v).getAdjacencylist().size(); i++)
			{
				int to_try = graph.getVertexlist().get(min_v).getAdjacencylist().get(i).getDestination();
				//A completer
			}
			//On met � jour l'affichage
			try {
	    	    board.update(graph, min_v);
	    	    Thread.sleep(10);
	    	} catch(InterruptedException e) {
	    	    System.out.println("stop");
	    	}
	            
		}
		
		System.out.println("Done! Using A*:");
		System.out.println("	Number of nodes explored: " + number_tries);
		System.out.println("	Total time of the path: " + graph.getVertexlist().get(end).getTimeFromSource());
		LinkedList<Integer> path=new LinkedList<Integer>();
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
	private static LinkedList<Integer> Dijkstra(Graph graph, int start, int end, int numberV, Board board)
	{
		graph.getVertexlist().get(start).setTimeFromSource(0);
		int number_tries = 0;
		
		//TODO: mettre tous les noeuds du graphe dans la liste des noeuds � visiter:
		HashSet<Integer> to_visit = new HashSet<Integer>();
		
		while (to_visit.contains(end))
		{
			//TODO: trouver le noeud min_v parmis tous les noeuds v ayant la distance temporaire
			//      graph.vertexlist.get(v).timeFromSource minimale.
			
			//On l'enl�ve des noeuds � visiter
			//get vertex with min dist
			////////////////////////// TO CHANGE !!!!
			int min_v = 0;
			to_visit.remove(min_v);
			number_tries += 1;
			
			//TODO: pour tous ses voisins, on v�rifie si on est plus rapide en passant par ce noeud.
			for (int i = 0; i < graph.getVertexlist().get(min_v).getAdjacencylist().size(); i++)
			{
				int to_try = graph.getVertexlist().get(min_v).getAdjacencylist().get(i).getDestination();
				//A completer
			}
			//On met � jour l'affichage
			try {
	    	    board.update(graph, min_v);
	    	    Thread.sleep(10);
	    	} catch(InterruptedException e) {
	    	    System.out.println("stop");
	    	}
	            
		}
		
		System.out.println("Done! Using Dijkstra:");
		System.out.println("	Number of nodes explored: " + number_tries);
		System.out.println("	Total time of the path: " + graph.getVertexlist().get(end).getTimeFromSource());
		LinkedList<Integer> path=new LinkedList<Integer>();
		path.addFirst(end);
		//TODO: remplir la liste path avec le chemin
		
		board.addPath(graph, path);
		return path;
	}
	
	//M�thode principale
	public static void main(String[] args) {
		//Lecture de la carte et cr�ation du graphe
		try {
			//TODO: obtenir le fichier qui d�crit la carte
		      File myObj = new File("??.txt");
		      Scanner myReader = new Scanner(myObj);
		      String data = "";
		      //On ignore les deux premi�res lignes
		      for (int i=0; i < 3; i++)
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
		      while (!data.equals("==Graph=="))
		      {
		    	  String name = data.split("=")[0];
		    	  int time = Integer.parseInt(data.split("=")[1]);
		    	  data = myReader.nextLine();
		    	  String color = data;
		    	  groundTypes.put(name, time);
		    	  groundColor.put(time, color);
		    	  data = myReader.nextLine();
		      }
		      
		      //On ajoute les sommets dans le graphe (avec le bon type)
		      for (int line=0; line < nlines; line++)
		      {
		    	  data = myReader.nextLine();
		    	  for (int col=0; col < ncols; col++)
		    	  {
		    		  graph.addVertex(groundTypes.get(String.valueOf(data.charAt(col))));
		    	  }
		      }
		      
		      //TODO: ajouter les arr�tes
		      for (int line=0; line < nlines; line++)
		      {
		    	  for (int col=0; col < ncols; col++)
		    	  {
		    		  int source = line*ncols+col;
		    		  int dest;
		    		  double weight;
		    		  //On donne la premi�re arr�te
		    		  if (line > 0)
		    		  {
		    			  if (col > 0)
		    			  {
		    				  dest = (line - 1)*ncols+col - 1;
		    				  ////////////////////////// TO CHANGE !!!!
		    				  weight = 0;
		    				  graph.addEgde(source, dest, weight);
		    			  }
		    			  //A completer
		    				  
		    		  }
		    		  //A completer
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
		    	} catch(InterruptedException e) {
		    	    System.out.println("stop");
		    	}
		      
		      //On appelle Dijkstra
		      LinkedList<Integer> path = Dijkstra(graph, startV, endV, nlines*ncols, board);
		      //TODO: laisser le choix entre Dijkstra et A*
		      
		      //�criture du chemin dans un fichier de sortie
		      try {
			      File file = new File("out.txt");
			      if (!file.exists()) {
			    	  file.createNewFile();
			      } 
			      FileWriter fw = new FileWriter(file.getAbsoluteFile());
			      BufferedWriter bw = new BufferedWriter(fw);
			      
			      for (int i: path)
			      {
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
