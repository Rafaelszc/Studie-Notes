package dataStructures.tree;

import java.util.ArrayList;
import java.util.List;

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

    public List<T> inOrder() {
        return inOrder(new ArrayList<>(), this.root);
    }

    private List<T> inOrder(List<T> list, Node<T> node) {
        if (node.isNil()) return list;

        inOrder(list, node.getLeft());
        list.add(node.getValue());
        inOrder(list, node.getRight());

        return list;
    }

    public List<T> preOrder() {
        return preOrder(new ArrayList<>(), this.root);
    }

    private List<T> preOrder(List<T> list, Node<T> node) {
        if (node.isNil()) return list;

        list.add(node.getValue());
        preOrder(list, node.getLeft());
        preOrder(list, node.getRight());

        return list;
    }

    public List<T> postOrder() {
        return postOrder(new ArrayList<>(), this.root);
    }

    private List<T> postOrder(List<T> list, Node<T> node) {
        if (node.isNil()) return list;

        postOrder(list, node.getLeft());
        postOrder(list, node.getRight());
        list.add(node.getValue());

        return list;
    }
}
