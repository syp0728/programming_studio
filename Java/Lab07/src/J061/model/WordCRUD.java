package J061.model;

import java.util.ArrayList;
import java.util.Scanner;

public class WordCRUD {
    ArrayList<Word> list;
    Scanner s;

    public WordCRUD(){
        // ArrrayList로 입력받기
        list = new ArrayList<Word>();
    }


    // 단어 추가
    public void addWord(){
        String english, korean;
        int level;

        s = new Scanner(System.in);

        // 영어 단어
        System.out.print("English > ");
        english = s.nextLine();

        // 한글 뜻
        System.out.print("Korean > ");
        korean = s.nextLine();

        // 단어 수준
        System.out.print("Level(1~3) > ");
        level = s.nextInt();

        Word new_word = new Word(english, korean, level);
        list.add(new_word);
    }


    // 단어 뜻 수정
    public void editWord(){

        System.out.print("Number > ");
        int id = s.nextInt(); // 인덱스로 수정하고 싶은 단어 번호 찾기
        s.nextLine(); // 버퍼 비우기

        if (id > 0 && id <= list.size()) {
            System.out.print("New meaning > ");
            String newKorean = s.nextLine();
            list.get(id - 1).setKorean(newKorean); // 해당 객체의 한글 뜻 수정
        } else {
            System.out.println("Invalid number");
        }
    }


    // 단어 목록 출력
    public void listWord(){
        for(int i=0; i<list.size(); i++){
            System.out.printf("%d - %s\n", i+1, list.get(i).toString());
        }
    }


    // 단어 삭제
    public void deleteWord(){
        listWord();

        System.out.print("Number > ");
        int id = s.nextInt(); // 삭제할 번호 입력

        if (id > 0 && id <= list.size()) {
            list.remove(id - 1); // 해당 인덱스 삭제
            System.out.println("Delete.");
        } else {
            System.out.println("Invalid number");
        }
    }
}
