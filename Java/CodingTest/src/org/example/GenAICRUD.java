package org.example;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class GenAICRUD implements ICRUD {
    private ArrayList<GenAI> list = new ArrayList<>();
    private Scanner sc;

    public GenAICRUD(Scanner sc){
        this.sc = sc;
    }

    @Override
    public int addData() {
        sc.nextLine(); // 버퍼 비우기

        System.out.print("Enter the name: ");
        String name = sc.nextLine();

        System.out.print("Enter the company: ");
        String company = sc.nextLine();

        System.out.print("Enter the year: ");
        int year = sc.nextInt();

        System.out.print("Enter the category(Chatbot: B, Coding: C, Image: I, Research: R, Slide: S): ");
        char category = sc.next().toUpperCase().charAt(0);

        System.out.print("Enter the price: ");
        double price = sc.nextDouble();
        sc.nextLine(); // 버퍼 비우기

        System.out.print("Enter the createYear: ");
        String createYear = sc.nextLine();

        GenAI g = new GenAI(name, company, year, category, price, createYear);
        this.list.add(g); // 리스트에 새 항목 삽입
        System.out.println("GenAI added.");
        return 0;
    }

    @Override
    public void updateData(int no) {
        printData();

        System.out.print("Update a GenAI \n" + "Enter the number of the item to edit: ");
        no = sc.nextInt();
        sc.nextLine();

        if(no > 0 && no <= list.size()){
            System.out.print("New name > ");
            String newName = sc.nextLine();
            list.get(no - 1).setName(newName);

            System.out.print("New company > ");
            String newCompany = sc.nextLine();
            list.get(no - 1).setCompany(newCompany);

            System.out.print("New year > ");
            int newYear = sc.nextInt();
            list.get(no - 1).setYear(newYear);

            System.out.print("New category > ");
            char newCategory = sc.next().toUpperCase().charAt(0);
            list.get(no - 1).setCategory(newCategory);

            System.out.print("New price > ");
            double newPrice = sc.nextDouble();
            list.get(no - 1).setPrice(newPrice);
            sc.nextLine(); // 버퍼 비우기

            System.out.print("New createYear > ");
            String newCreateYear = sc.nextLine();
            list.get(no - 1).setCreateYear(newCreateYear);

        } else {
            System.out.println("Invalid number");
        }
    }

    @Override
    public void deleteData(int no){

        System.out.print("Number > ");
        no = sc.nextInt();

        if(no > 0 && no <=list.size()){
            list.remove(no - 1);  // 인덱서를 이용하여 리스트에서 삭제
            System.out.println("Delete");
        } else {
            System.out.println("Invalid number");
        }
    }

    @Override
    public void printData() {
        // TODO:
        // 1. 전체 데이터 개수를 출력한다.
        // 2. 컬럼 제목(No, AI Name, Company, Year, Agent Type, Price, Created Date)을 출력한다.
        // 3. 리스트에 저장된 모든 GenAI 객체를 순차적으로 출력한다.
        // 4. 번호는 1번부터 시작하여 출력한다.
        System.out.println("Total: " + list.size());

        System.out.printf("No\tAI_Name\tCompany\tYear\tAgent_Type\tPrice\tCreated_Date\n");

        int count = 1;
        for (GenAI ai : this.list) {
            System.out.print(count++ + "\t");
            System.out.println(ai.toString());
        }

    }

    // 추가 기능
    // 정렬 기능 구현
    public void sortByAIName() {
        list.sort(Comparator.comparing(GenAI::getName));
        System.out.println("Sorted by Name.");
        printData();
    }

    public void sortByPrice() {
        list.sort(Comparator.comparingDouble(GenAI::getPrice));
        System.out.println("Sorted by Price.");
        printData();
    }

    public void comparePrice() {
        printData();
        System.out.print("Select two numbers to compare (ex: 1 2) > ");
        int n1 = sc.nextInt();
        int n2 = sc.nextInt();

        if (n1 > 0 && n1 <= list.size() && n2 > 0 && n2 <= list.size()) {
            GenAI g1 = list.get(n1 - 1);
            GenAI g2 = list.get(n2 - 1);

            if (g1.getPrice() < g2.getPrice()) {
                System.out.println(g1.getName() + " is cheaper.");
            } else if (g1.getPrice() > g2.getPrice()) {
                System.out.println(g2.getName() + " is cheaper.");
            } else {
                System.out.println("Both have the same price.");
            }
        }
    }
}
