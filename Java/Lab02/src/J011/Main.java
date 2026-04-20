package J011;
import J011.model.Person;
import java.util.Scanner; 

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        
        int height = s.nextInt();
        int weight = s.nextInt();
        
        Person p = new Person(height, weight);
        
        if (p.getBMI() >= 25) { 
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
        
    }
}