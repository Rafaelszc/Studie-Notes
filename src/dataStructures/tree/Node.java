package dataStructures.tree;

public class Node<T extends Comparable<T>> {
    private T value;
    private boolean isNil;
    private Node<T> left;
    private Node<T> right;

    public Node(T value) {
        this.value = value;
        this.isNil = false;
        this.left = new Node<>();
        this.right = new Node<>();
    }
    public Node() {
        this.isNil = true;
    }

    public T getValue() {
        return value;
    }

    public boolean isNil() {
        return isNil;
    }

    public Node<T> getLeft() {
        return left;
    }

    public Node<T> getRight() {
        return right;
    }

    public void setLeft(Node<T> left) {
        this.left = left;
    }

    public void setRight(Node<T> right) {
        this.right = right;
    }

    public void setValue(T value) {
        this.value = value;
        this.isNil = false;
        this.left = new Node<>();
        this.right = new Node<>();
    }
}
