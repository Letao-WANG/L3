package model;

import java.util.LinkedList;

public class Vertex {
    private double indivTime;
    private double timeFromSource;
    private double heuristic;
    private Vertex prev;
    private LinkedList<Edge> adjacencylist;
    private int num;

    public Vertex(int num) {
        this.indivTime = Double.POSITIVE_INFINITY;
        this.timeFromSource = Double.POSITIVE_INFINITY;
        this.heuristic = -1;
        this.prev = null;
        this.adjacencylist = new LinkedList<Edge>();
        this.num = num;
    }

    public void addNeighbor(Edge e) {
        this.adjacencylist.addFirst(e);
    }

    public double getIndivTime() {
        return indivTime;
    }

    public void setIndivTime(double indivTime) {
        this.indivTime = indivTime;
    }

    public double getTimeFromSource() {
        return timeFromSource;
    }

    public void setTimeFromSource(double timeFromSource) {
        this.timeFromSource = timeFromSource;
    }

    public double getHeuristic() {
        return heuristic;
    }

    public void setHeuristic(double heuristic) {
        this.heuristic = heuristic;
    }

    public Vertex getPrev() {
        return prev;
    }

    public void setPrev(Vertex prev) {
        this.prev = prev;
    }

    public LinkedList<Edge> getAdjacencylist() {
        return adjacencylist;
    }

    public void setAdjacencylist(LinkedList<Edge> adjacencylist) {
        this.adjacencylist = adjacencylist;
    }

    public int getNum() {
        return num;
    }

    public void setNum(int num) {
        this.num = num;
    }
}