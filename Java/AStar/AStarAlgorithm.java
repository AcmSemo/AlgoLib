package com.stane.astar;

/*
    f(x) = Node cost
    g(x) = known distance from start node to current node
    h(x) = heuristic estimate of distance from x to the goal
    f(x) = g(x) + h(x)
    uses manhattan distance
*/

public class AStarAlgorithm {
    private Node[][] searchGrid;
    private Node start;
    private Node end; // our goal
    private List<Node> closedSet; // have been evaluated
    private Queue<Node> openSet; // to be evaluated

    public AStarAlgorithm(){
        this.searchGrid = new Node[Constants.ROWS][Constants.COLS];
        this.openSet = new PriorityQueue<>(new NodeComparator());
        this.closedSet = new ArrayList<>();
        initSearchGrid();
    }

    private void initSearchGrid(){
        for(int rowIndex = 0; rowIndex < Constants.ROWS; rowIndex++){
            for(int colIndex = 0; colIndex < Constants.COLS; colIndex++){
                Node node = new Node(rowIndex, colIndex);
                this.searchGrid[rowIndex][colIndex] = node;
            }
        }

        this.searchGrid[1][7].setObstacle(true);
        this.searchGrid[2][3].setObstacle(true);
        this.searchGrid[2][4].setObstacle(true);
        this.searchGrid[2][5].setObstacle(true);
        this.searchGrid[2][6].setObstacle(true);
        this.searchGrid[2][7].setObstacle(true);

        this.start = this.searchGrid[3][3];
        this.end = this.searchGrid[1][6];
    }

    public void search(){
        start.setH(manhattanHeuristic(start, end));
        openSet.add(start);

        while(!openSet.Empty()){
            Node currentNode = openSet.poll(); //returns node with smallest f value
            System.out.println(currentNode + "Previous: " + currentNode.getPreviousNode());

            if(currentNode.equals(end)) return;

            openSet.remove(currentNode);
            closedSet.add(currentNode);

            for(Node neighbor : getAllNeighbors(currentNode)){
                if(closedSet.contains(neighbor)) continue;
                if(!openSet.contains(neighbor)) openSet.add(neighbor);
                neighbor.setPreviousNode(currentNode);
            }
        }
    }

    private List<Node> getAllNeighbors(Node node){
        List<Node> neighbors = new ArrayList<>();
        int row = node.getRowIndex();
        int col = node.getColIndex();

        // top
        if(row-1 >= 0 && !this.searchGrid[row-1][col].getObstacle()){
            searchGrid[row-1][col].setG(node.getG() + Constants.FLAT_COST);
            searchGrid[row-1][col].setH(manhattanHeuristic(searchGrid[row-1][col], end));
            neighbors.add(this.searchGrid[row-1][col]);
        }
        // bottom
        if(row+1 < Constants.ROWS && !this.searchGrid[row-1][col].getObstacle()){
            searchGrid[row+1][col].setG(node.getG() + Constants.FLAT_COST);
            searchGrid[row+1][col].setH(manhattanHeuristic(searchGrid[row+1][col], end));
            neighbors.add(this.searchGrid[row+1][col]);
        }
        // left
        if(col-1 >= 0 && !this.searchGrid[row][col-1].getObstacle()){
            searchGrid[row][col-1].setH(manhattanHeuristic(searchGrid[row][col-1], end));
            searchGrid[row][col-1].setG(node.getG() + Constants.FLAT_COST);
            neighbors.add(this.searchGrid[row][col-1]);
        }
        // right
        if(col+1 < Constants.COLS && !this.searchGrid[row][col-1].getObstacle()){
            searchGrid[row][col+1].setH(manhattanHeuristic(searchGrid[row][col+1], end));
            searchGrid[row][col+1].setG(node.getG() + Constants.FLAT_COST);
            neighbors.add(this.searchGrid[row][col+1]);
        }

        return neighbors;
    }

    public int manhattanHeuristic(Node nodeA, Node nodeB){
        int c = Math.abs(nodeA.getColIndex() - nodeB.getColIndex());
        int r = nodeA.getRowIndex() - nodeB.getRowIndex();
        return Math.abs(r + c) * 10;
    }

    public void showPath(){
        System.out.println("Shortest path: ");
        Node node = this.end;

        while(node != null){
            System.out.println(node);
            node = node.getPreviousNode();
        }
    }

}
