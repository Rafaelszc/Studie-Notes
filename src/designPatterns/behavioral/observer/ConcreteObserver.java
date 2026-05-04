package designPatterns.behavioral.observer;

public class ConcreteObserver implements Observer {
    public ConcreteObserver() {}

    @Override
    public void update() {
        System.out.println("Do something" +
                "\nclass: "+ hashCode());
    }
}
