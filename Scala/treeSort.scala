
object TreeSort {

  // A tree is either Empty or a Node with left and right trees, which may also be
  // empty or nodes.
  sealed trait Tree
  case class Node(var leftChild: Tree, var data: Int, var rightChild: Tree) extends Tree
  case class Empty() extends Tree

  // Recursively inserts an item into a tree, with mutation.
  private def insert(item: Int, tree: Tree): Tree = tree match {
    case Empty()          =>  Node(Empty(), item, Empty())
    case Node(_, data, _) => {
      // t is just the tree cast as a Node
      val t: Node = tree.asInstanceOf[Node]

      // If the item is the data in the node, just return the node
      if(item == data) return t

      // If the item is smaller than the data in the node,
      // Insert it into the left
      if (item < data) {
        t.leftChild = insert(item, t.leftChild)
        tree
      } else {
        // If the item is greater or equal to the data in the node,
        // Insert it into the right.
        t.rightChild = insert(item, t.rightChild)
        tree
      }
    }
  }

  // Builds a tree iteratively by calling insert on
  // an Empty tree.
  private def makeTree(items: List[Int]): Tree = {
    var tree: Tree = Empty()

    items.foreach(
      item => {
        tree = insert(item, tree)
      }
    )

    tree
  }

  // Walks the binary search tree recursively and
  // returns a list using naive recursion.
  private def getItems(tree: Tree): List[Int] = {
    tree match {
        // If the tree is empty, just return an empty list
      case Empty()                      => List()
        // If there is only one node in the tree, return a list of its
        // data
      case Node(Empty(), data, Empty()) => List(data)
        // In any other case:
        //  1. get a list of the items in the left side tree.
        //  2. get a list containing only the middle value(data).
        //  3. get a list of the right side of the tree.
        //  4. concatenate the three lists and return them.
      case Node(left, data, right)      => {
        val leftSide  = getItems(left)
        val rightSide = getItems(right)

        leftSide ++ List(data) ++ rightSide
      }
    }
  }

  // The final public interface which just composes getItems and makeTree and
  // returns the result.
  def treeSort(items:List[Int]):List[Int] = {
    getItems(makeTree(items))
  }
}

// Example usage from a main program:
//   TreeSort.treeSort(List(1, 100, 1000, 5, 50, 2, 502))

