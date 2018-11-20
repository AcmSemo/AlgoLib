package com.udemy.iddfs;

public class App {
	
	public static void main(String[] args){
		Node vertex0 = new Node("A");
		Node vertex1 = new Node("B");
		Node vertex2 = new Node("C");
		Node vertex3 = new Node("D");
		Node vertex4 = new Node("E");
		
		vertex0.addNeighbour(vertex1);
		vertex0.addNeighbour(vertex2);
		vertex1.addNeighbour(vertex3);
		vertex3.addNeighbour(vertex4);
		
		Algorithm algorithm = new Algorithm(vertex4);
		algorithm.runDeepeningSearch(vertex0);
		
	}
	
}