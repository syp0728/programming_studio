package J033;
import java.util.Scanner;

public class Main {

    private String longest = "";
    private String shortest = "";

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        Main main = new Main();

        int count = s.nextInt();
        s.nextLine();

        main.compareLength(s, count);

        System.out.printf("Longest: " + main.longest + "\n");
        System.out.printf("Shortest: " + main.shortest + "\n");

    }

    public void compareLength(Scanner s, int count) {
        String name;

        for(int i=0; i<count; i++){
            name = s.nextLine();

            if(i==0){
                this.longest = name;
                this.shortest = name;
            }else{
                if(name.length() >= longest.length()) longest = name;
                if(name.length() <= shortest.length()) shortest = name;
            }
        }
    }
}