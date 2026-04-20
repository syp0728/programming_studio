package J062;

import J062.model.BookCRUD;
import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        // Main 객체 생성
        Main main = new Main();
        main.run();
    }

    public void run(){
        int menu, quit=0;
        Scanner s = new Scanner(System.in);
        BookCRUD manager = new BookCRUD();

        // 종료(0)를 누르기 전까지 반복
        while(true){
            System.out.println("Menu> 1 Add 2 Edit 3 List 4 Delete 0 Exit");
            menu = s.nextInt(); // 사용자 메뉴 선택

            switch(menu){
                case 1: manager.addBook(); break;       // 도서 추가
                case 2: manager.editBook(); break;      // 도서 정보 수정
                case 3: manager.listBook(); break;      // 도서 목록 출력
                case 4: manager.deleteBook(); break;    // 도서 삭제
                default: quit = 1;
            }

            if(quit == 1) break;
        }
    }
}
