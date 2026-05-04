package designPatterns.creational;

public class Singleton {
    private static Singleton instance;

    private Singleton() {
        System.out.println("New Singleton created");
    }

    public static Singleton getInstance(){
        if (instance == null){
            instance = new Singleton();
        }

        return instance;
    }

    public void sayHello(){
        System.out.println("Hello!");
    }
}
