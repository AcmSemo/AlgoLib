import scala.annotation.tailrec

object List {

  sealed trait LinkedList[T]
  case class Nil[T]()                              extends LinkedList[T]
  case class Node[T](data: T, next: LinkedList[T]) extends LinkedList[T]


  def prepend[T](data: T, next: LinkedList[T]): LinkedList[T] = Node(data, next)

  def rest[T](lst: LinkedList[T]): Option[LinkedList[T]] = lst match {
    case Nil()          => None
    case Node(_, rest) => Some(rest)
  }

  def first[T](lst: LinkedList[T]): Option[T] = lst match {
    case Nil()          => None
    case Node(first, _) => Some(first)
  }

  def length[T](lst: LinkedList[T]): Int = {
    @tailrec
    def inner(lst: LinkedList[T], acc: Int): Int = lst match {
      case Nil()         => acc
      case Node(_, rest) => inner(rest, acc + 1)
    }

    inner(lst, 0)
  }

  def reverse[T](lst: LinkedList[T]): LinkedList[T] = {
    @scala.annotation.tailrec
    def inner(lst: LinkedList[T], acc: LinkedList[T]): LinkedList[T] = lst match {
      case Nil()       => acc
      case Node(x, xs) => inner(xs, prepend(x, acc))
    }

    inner(lst, Nil())
  }

  def find[T](item: T, lst: LinkedList[T]): Option[Int] = {
    @scala.annotation.tailrec
    def inner(lst: LinkedList[T], acc: Int): Option[Int] = lst match {
      case Nil()                                      => None
      case Node(x: T, xs: LinkedList[T]) if x == item => Some(acc)
      case Node(_, xs)                                => inner(xs, acc + 1)
    }

    inner(lst, 0)
  }

  def last[T](lst: LinkedList[T]): Option[T] = lst match {
    case Nil()          => None
    case Node(x, Nil()) => Some(x)
    case Node(x, xs)    => last(xs)
  }

  def list[T](items: T*): LinkedList[T] = {
    var lst: LinkedList[T] = Nil()

    for (item <- items) {
      lst = prepend(item, lst)
    }

    reverse(lst)
  }

  def filter[T](lst: LinkedList[T], fn: T => Boolean): LinkedList[T] = {
    @scala.annotation.tailrec
    def inner(lst: LinkedList[T], acc: LinkedList[T]): LinkedList[T] = lst match {
      case Nil()       => reverse(acc)
      case Node(x, xs) =>
        if (fn(x)) inner(xs, prepend(x, acc))
        else       inner(xs, acc)

    }

    inner(lst, Nil())
  }


  def map[T, U](lst: LinkedList[T], fn: T => U): LinkedList[U] = {
    @scala.annotation.tailrec
    def inner(lst: LinkedList[T], acc: LinkedList[U]): LinkedList[U] = lst match {
      case Nil()       => reverse(acc)
      case Node(x, xs) => inner(xs, prepend(fn(x), acc))
    }

    inner(lst, Nil())
  }
}
