package graph;

/*
*This program reads in an n X n adjency graph matrix and outputs the number of
*edges, pendant vertices, the largest degree present, and whether or not it has
*an Euler Path.
*/
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Graph {

    private final ArrayList<Integer> numArray = new ArrayList<>();//ArrayList that holds all current investments
    
    public void graph() {
        String fileName = "ass4-graphs.txt";
        int graphSize, currentDegree = 0, largestDegree = 0, graphNumber = 1;
        int numEdges = 0, numPendants = 0, totalDegree = 0, oddDegreeVertices = 0;
        String hasEuler;

        BufferedReader reader;
        try {//Try catch for opening file
            File f = new File(fileName);
            reader = new BufferedReader(new FileReader(fileName));
            String line = reader.readLine();//Read in first line of file
            while (line != null) {//Reads until end of file
                graphSize = Integer.parseInt(line);//Get size of graph
                for (int i = 0; i < graphSize; i++) {//for x adjacency matrix
                    String graphLine = reader.readLine();
                    for (int j = 0; j < graphLine.length(); j++) {
                        if (graphLine.charAt(j) == '1') {
                            currentDegree++;
                        }
                    }
                    if (currentDegree == 1)//if only one '1'
                        numPendants++;//increment pendant vertice
                    if (currentDegree > largestDegree) 
                        largestDegree = currentDegree;//Set new largest degree 
                    if (currentDegree % 2 == 1) //if degree count is odd
                        oddDegreeVertices++;
                    totalDegree += currentDegree;//add to total degree
                    currentDegree = 0;
                }
               
                //Check if the graph has a Euler Path
                if (oddDegreeVertices == 2 || oddDegreeVertices == 0) {
                    hasEuler = "HAS";
                } else {
                    hasEuler = "NO";
                }
                numEdges = totalDegree / 2;
               
                System.out.println("Graph " + graphNumber + ":   " + numEdges + " edges, " + numPendants
                        + " pendant vertices, largest degree " + largestDegree + ", " + hasEuler + " Euler path.");
                
                graphNumber++;
                numEdges = 0;
                numPendants = 0;
                largestDegree = 0;
                totalDegree = 0;
                currentDegree = 0;
                oddDegreeVertices = 0;
                line = reader.readLine();

            }
            reader.close();
        } catch (IOException e) {
            System.out.println("Exception\n");
        }
    }

    public static void main(String[] args) {
        Graph g = new Graph();
        g.graph();
    }
}
