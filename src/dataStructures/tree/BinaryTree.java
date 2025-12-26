package dataStructures.tree;

import java.util.ArrayList;

public class BinaryTree<T> {
    private BinaryTree<T> left;
    private BinaryTree<T> right;
    private T value;

    public BinaryTree(T value, BinaryTree<T> left, BinaryTree<T> right) {
        this.left = left;
        this.right = right;
        this.value = value;
    }

    public BinaryTree(T value, BinaryTree<T> left) {
        this.value = value;
        this.left = left;
    }

    public BinaryTree(T value) {
        this.value = value;
    }

    public ArrayList<T> preOrder() {
        return preOrder(new ArrayList<T>());
    }

    private ArrayList<T> preOrder(ArrayList<T> list){
        list.add(this.value);

        if (this.left != null) {
            this.left.preOrder(list);
        }
        if (this.right != null) {
            this.right.preOrder(list);
        }

        return list;
    }

    public ArrayList<T> postOrder() {
        ArrayList<T> list = postOrder(new ArrayList<>());
        list.add(this.value);
        return list;
    }

    private ArrayList<T> postOrder(ArrayList<T> list) {
        if (this.left != null) {
            this.left.postOrder(list);
            list.add(this.left.value);
        }

        if (this.right != null) {
            this.right.postOrder(list);
            list.add(this.right.value);
        }

        return list;
    }

    public ArrayList<T> inOrder() {
        return inOrder(new ArrayList<T>());
    }

    private ArrayList<T> inOrder(ArrayList<T> list) {
        if (this.left != null) {
            this.left.inOrder(list);
        }
        list.add(this.value);

        if (this.right != null) {
            this.right.inOrder(list);
        }

        return list;
    }
}
