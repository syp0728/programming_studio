package J061;
import J061.model.WordCRUD;

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
        WordCRUD manager = new WordCRUD();

        // 종료(0)를 누르기 전까지 반복
        while(true){
            System.out.println("Menu> 1 Add 2 Edit 3 List 4 Delete 0 Exit");
            menu = s.nextInt(); // 사용자 메뉴 선택
            switch(menu){
                case 1: manager.addWord(); break;       // 단어 추가
                case 2: manager.editWord(); break;      // 단어의 한글 뜻 수정
                case 3: manager.listWord(); break;      // 단어 목록 출력
                case 4: manager.deleteWord(); break;    // 단어 삭제
                default: quit = 1;
            }
            if(quit == 1) break;
        }
    }
}
