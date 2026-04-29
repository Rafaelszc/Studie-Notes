package dataStructures.hash;

import dataStructures.interfaces.Identifiable;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class HashTable<T extends Identifiable> {
    private final int BUCKET_SIZE = 23;
    private final List<LinkedList<T>> buckets = new ArrayList<>(BUCKET_SIZE);

    public HashTable() {
        for (int i=0; i<BUCKET_SIZE; i++) {
            buckets.add(new LinkedList<>());
        }
    }

    public int hash(T item) {
        return hash(item.getId());
    }

    public int hash(long id) {
        return (int) id%BUCKET_SIZE;
    }

    public void insert(T item) {
        int itemHash = hash(item);
        LinkedList<T> bucket = buckets.get(itemHash);
        bucket.add(item);
    }

    public void remove(long id) {
        int itemHash = hash(id);
        LinkedList<T> bucket = buckets.get(itemHash);

        bucket.removeIf(item -> item.getId() == id);
    }

    public T getById(long id) {
        int itemHash = hash(id);
        LinkedList<T> bucket = buckets.get(itemHash);

        return bucket
                .stream()
                .filter(item -> item.getId() == id)
                .findFirst()
                .orElse(null);
    }
}
