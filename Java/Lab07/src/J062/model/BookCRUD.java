package J062.model;

import J062.model.Book;
import java.util.ArrayList;
import java.util.Scanner;

public class BookCRUD {
    ArrayList<Book> list;
    Scanner s;

    public BookCRUD(){
        list = new ArrayList<Book>();
    }


    // 책 추가
    public void addBook(){
        String title, author, category;
        int price, year;

        s = new Scanner(System.in);

        // 도서명
        System.out.print("Title > ");
        title = s.nextLine();

        // 저자
        System.out.print("Author > ");
        author = s.nextLine();

        // 카테고리
        System.out.print("Category > ");
        category = s.nextLine();

        // 가격
        System.out.print("Price > ");
        price = s.nextInt();

        // 출판년도
        System.out.print("Year > ");
        year = s.nextInt();

        Book new_book = new Book(title, author, category, price, year);
        list.add(new_book);
    }

    // 책 정보 수정
    public void editBook(){
        listBook();

        System.out.print("Index number > ");
        int id = s.nextInt();
        s.nextLine(); // 버퍼 비우기

        if (id > 0 && id <= list.size()) {
            System.out.print("New title > ");
            String newTitle = s.nextLine();
            list.get(id - 1).setTitle(newTitle); // 해당 책의 제목 수정
        } else {
            System.out.println("Invalid number");
        }
    }

    // 책 목록 출력
    public void listBook(){
        for(int i=0; i<list.size(); i++){
            System.out.printf("%d - %s\n", i+1, list.get(i).toString());
        }
    }


    // 책 삭제
    public void deleteBook(){
        listBook();

        System.out.print("Number > ");
        int id = s.nextInt();

        if (id > 0 && id <= list.size()) {
            list.remove(id - 1); // 인덱스를 이용하여 리스트에서 삭제
            System.out.println("Delete");
        } else {
            System.out.println("Invalid number");
        }
    }
}
