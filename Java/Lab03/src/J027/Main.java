package J027;
import J027.model.Person;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int n = s.nextInt();
        Person[] people = new Person[n];

        for (int i = 0; i < n; i++) {
            int h = s.nextInt();
            int w = s.nextInt();
            people[i] = new Person(h, w);
        }

        Result(people);
        
        s.close();
    }

    public static void Result(Person[] people) {
        int count = 0;
        String names = "";

        for (int i = 0; i < people.length; i++) {
            if (people[i].getBMI() >= 25.0) {
                count++;
                names += (i + 1) + " "; 
            }
        }

        System.out.println("Overweight person - " + names.trim());
        System.out.println("Total - " + count);
    }
}