package org.example;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        new Main().run();
    }

    public void run() {
        Scanner sc = new Scanner(System.in);
        GenAICRUD manager = new GenAICRUD(sc);
        int datano;
        boolean quit = false;

        do {
            System.out.print("1. Add 2. List 3. Update 4. Delete 5. Sort by AIName 6. Sort by Price 7. Compare Price 0. Quit > ");
            int menu = sc.nextInt();

            switch (menu) {
                case 1:
                    manager.addData();
                    break;
                case 2:
                    manager.printData();
                    break;
                case 3:
                    manager.printData();
                    System.out.print("Select data no > ");
                    datano = sc.nextInt();
                    manager.updateData(datano);
                    break;
                case 4:
                    manager.printData();
                    System.out.print("Select data no > ");
                    datano = sc.nextInt();
                    manager.deleteData(datano);
                    break;
                case 5:
                    manager.sortByAIName();
                    break;
                case 6:
                    manager.sortByPrice();
                    break;
                case 7:
                    manager.comparePrice();
                    break;
                case 0:
                    quit = true;
            }
        } while (!quit);
    }
}
