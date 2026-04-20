package J022;
import J022.model.Size;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        
        Size[] list = new Size[10];

        for (int i = 0; i < list.length; i++) {
            double m2 = s.nextDouble();
            list[i] = new Size(m2);
        }

        countAndPrint(list);
    }

    public static void countAndPrint(Size[] list) {
    int count1 = 0, count2 = 0, count3 = 0, count4 = 0;

    for (int i = 0; i < list.length; i++) {
        String category = list[i].getSizeCategory();

        if (category.equals("small")) {
            count1++;
        } else if (category.equals("normal")) {
            count2++;
        } else if (category.equals("large")) {
            count3++;
        } else if (category.equals("huge")) {
            count4++;
        }
    }

    System.out.printf("small - %d\n", count1);
    System.out.printf("normal - %d\n", count2);
    System.out.printf("large - %d\n", count3);
    System.out.printf("huge - %d\n", count4);
}
}