package J021;
import J021.model.Person;
import java.util.Scanner; 

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int num = s.nextInt();
        
        Person[] list = new Person[num];

        for (int i = 0; i < list.length; i++) {
            list[i] = new Person(s.nextInt(), s.nextInt());
        }

        System.out.println(Count(list));
    }

    public static int Count(Person[] list) {
        int count = 0;
        for (Person p : list) {
            if (p.BMI() >= 25.0) count++;
        }
        return count;
    }
}