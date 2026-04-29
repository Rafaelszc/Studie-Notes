package dataStructures.tree;

public class BinarySearchTree<T extends Comparable<T>> {
    private Node<T> root;

    public BinarySearchTree(T value) {
        this.root = new Node<>(value);
    }

    public int size() {
        return size(this.root);

    }

    private int size(Node<T> node) {
        if (node.isNil()) return 0;

        return 1 + size(node.getLeft()) + size(node.getRight());
    }

    public void insert(T value) {
        Node<T> aux = this.root;

        while (!aux.isNil()) {
            if (aux.getValue().compareTo(value) < 0) aux = aux.getRight();
            else aux = aux.getLeft();
        }
        aux.setValue(value);
    }

    public boolean find(T value) {
        Node<T> aux = this.root;

        while (aux.getValue() != value && !aux.isNil()) {
            if (aux.getValue().compareTo(value) < 0) aux = aux.getRight();
            else aux = aux.getLeft();
        }

        return aux.getValue() == value;
    }
}
