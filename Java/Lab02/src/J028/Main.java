package J028;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int[][] jumsu = new int[5][3];            
        int[] sum_student = new int[5];           
        double[] average_student = new double[5]; 
        char[] grade = new char[5];               
        int[] sum_class = new int[3];            
        double[] average_class = new double[3];   

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 3; j++) {
                jumsu[i][j] = s.nextInt();
                sum_student[i] += jumsu[i][j];    
                sum_class[j] += jumsu[i][j];     
            }
            average_student[i] = sum_student[i] / 3.0; 

            if (average_student[i] >= 90) grade[i] = 'A';
            else if (average_student[i] >= 80) grade[i] = 'B';
            else if (average_student[i] >= 70) grade[i] = 'C';
            else if (average_student[i] >= 60) grade[i] = 'D';
            else grade[i] = 'F';
        }

        for (int j = 0; j < 3; j++) {
            average_class[j] = sum_class[j] / 5.0;
        }

        String[] class_names = {"Korean", "English", "Math"};
        
        for (int j = 0; j < 3; j++) {
            System.out.printf("%s - Sum %d, Average %.1f\n", 
                class_names[j], sum_class[j], average_class[j]);
        }

        for (int i = 0; i < 5; i++) {
            System.out.printf("#%d Student - Sum %d, Average %.1f, Grade %c\n", 
                (i + 1), sum_student[i], average_student[i], grade[i]);
        }
        
        s.close();
    }
}