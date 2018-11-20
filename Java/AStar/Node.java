package com.stane.astar;

public class Node {

    private int g; //distance from start
    private int h; //distance from end
    private int rowIndex;
    private int colIndex;
    private Node previousNode;
    private boolean isObstacle;

    public Node(int rowIndex, int colIndex){
        this.rowIndex = rowIndex;
        this.colIndex = colIndex;
    }

    public boolean getObstacle(){
        return this.isObstacle;
    }

    public void setObstacle(boolean isObstacle){
        this.isObstacle = isObstacle;
    }

    public int getRowIndex(){
        return this.rowIndex;
    }

    public void setRowIndex(int rowIndex){
        this.rowIndex = rowIndex;
    }

    public int getColIndex(){
        return this.colIndex;
    }

    public void setColIndex(int colIndex){
        this.colIndex = colIndex;
    }

    public int getG(){
        return this.g;
    }

    public void setG(int g){
        this.g = g;
    }

    public int getH(){
        return this.h;
    }

    public void setH(int h){
        this.h = h;
    }

    public int getF(){
        return this.g + this.h;
    }

    public Node getPreviousNode(){
        return this.previousNode;
    }

    public void setPreviousNode(Node previousNode){
        this.previousNode = previousNode;
    }

    @Override
    public boolean equals(Object node){
        Node node2 = (Node)node;
        return ((this.rowIndex == node2.getRowIndex()) && (this.colIndex == node2.getColIndex()));
    }

    @Override
    public String toString(){
        return "Node (" + this.rowIndex + "," + this.colIndex + ") - h: " + this.h + ", g: " + this.g + ", f: " + this.getF();
    }

}
