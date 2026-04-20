package J027.model;

public class Person {
    private int height;
    private int weight;

    public Person(int height, int weight) {
        this.height = height;
        this.weight = weight;
    }

    public double getBMI() {
        return (weight * 10000.0) / (height * height);
    }
}