package com.stane.astar;

import java.util.Comparator;

public class NodeComparator implements Comparator<Node> {

    @Override
    public int compare(Node nodeA, Node nodeB) {
        if(nodeA.getF() == nodeB.getF()) return 0;
        return (nodeA.getF() < nodeB.getF()) ? -1 : +1;
    }

}
