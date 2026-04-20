package J029; 
import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);

        int[][] jumsu = new int[5][3];
        int[] sum_student = new int[5];
        double[] average_student = new double[5];
        char[] grade = new char[5];
        int[] sum_class = new int[3];
        double[] average_class = new double[3];


        for(int i=0; i<5; i++){
            for(int j=0; j<3; j++){
                jumsu[i][j] = s.nextInt();
                sum_student[i] += jumsu[i][j];
            }
            average_student[i] = (double)sum_student[i] / 3.0;
            if(average_student[i] >= 90.0){
                grade[i] = 'A';
            }else if(average_student[i] >= 80.0){
                grade[i] = 'B';
            }else if(average_student[i] >= 70.0){
                grade[i] = 'C';
            }else if(average_student[i] >= 60.0){
                grade[i] = 'D';
            }else{
                grade[i] = 'F';
            }

        }


        for(int i=0; i<3; i++){
            for(int j=0; j<5; j++){
                sum_class[i] += jumsu[j][i];
            }
            average_class[i] = (double)sum_class[i] / 5.0;
        }


        System.out.printf("Korean - Sum %d, Average %.1f\n", sum_class[0], average_class[0]);
        System.out.printf("English - Sum %d, Average %.1f\n", sum_class[1], average_class[1]);
        System.out.printf("Math - Sum %d, Average %.1f\n", sum_class[2], average_class[2]);


        for(int i=0; i<5; i++){
            System.out.printf("#%d Student - Sum %d, Average %.1f, Grade %c\n", i+1, sum_student[i], average_student[i], grade[i]);
        }
    }
}