package J063;

import J063.model.TodoCRUD;
import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        // Main 객체 생성
        Main main = new Main();
        main.run();
    }

    public void run(){
        int menu, quit = 0;
        Scanner s = new Scanner(System.in);
        TodoCRUD manager = new TodoCRUD();

        // 종료(0)를 누르기 전까지 반복
        while(true){
            System.out.println("Menu> 1 Add 2 Edit 3 List 4 Delete 0 Exit");
            menu = s.nextInt(); // 사용자 메뉴 선택

            switch(menu){
                case 1: manager.addTodo(); break;       // 할 일 추가
                case 2: manager.editTodo(); break;      // 할 일 수정
                case 3: manager.listTodo(); break;      // 할 일 목록 출력
                case 4: manager.deleteTodo(); break;   // 할 일 삭제
                default: quit = 1;
            }

            if(quit == 1) break;
        }
    }
}