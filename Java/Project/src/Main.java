package src;

import java.util.Scanner;

import src.model.ServiceItem;
import src.model.ServiceCRUD;
import src.model.iCRUD;


public class Main {
    public static void main(String[] args) {
        Main main = new Main();
        main.run();
    }

    // 사용 가능한 명령어 안내 출력
    public void displayHelp() {
        System.out.println("Usage of commands");
        System.out.println("1. Add a new item ( add )");
        System.out.println("2. Delete an existing item ( del )");
        System.out.println("3. Update an item ( edit )");
        System.out.println("4. List all items ( ls )");
        System.out.println("5. sort the list by name ( ls name )");
        System.out.println("6. sort the list by name descending ( ls name desc )");
        System.out.println("7. sort the list by date ( ls date )");
        System.out.println("8. sort the list by date descending ( ls date desc )");
        System.out.println("9. show commands guidelines ( ? )");
        System.out.println("10. quit program ( exit )");
    }

    public void run() {
        Scanner s = new Scanner(System.in);
        ServiceCRUD manager = new ServiceCRUD();
        boolean quit = false;

        do {
            System.out.print("> ");
            String line = s.nextLine().trim(); // 입력 문자열 앞뒤 공백 제거
            String[] parts = line.split("\\s+"); // 공백 기준으로 문자열 분리
            String choice = parts[0]; // 분리된 첫 번째 단어를 명령어로 선택

            switch (choice) {
                case "add":
                    manager.addItem(); // 항목 추가
                    break;

                case "del":
                    manager.deleteItem(); // 항목 삭제
                    break;

                case "edit":
                    manager.updateItem(); // 항목 수정
                    break;

                case "ls":
                    // 명령어 뒤에 인자가 더 있는지 확인 (예: ls video, ls music)
                    if (parts.length > 1 && !parts[1].equals("name") && !parts[1].equals("date")) {
                        // ls 뒤에 정렬 키워드가 아닌 단어가 오면 카테고리 검색으로 간주
                        manager.printAll(parts[1]);
                    } else {
                        // 기존 정렬 로직
                        if (line.contains("name")) manager.sortByName();
                        if (line.contains("date")) manager.sortByDate();
                        if (line.contains("desc")) manager.reverseList();

                        manager.printAll(); // 전체 출력
                    }
                    break;

                case "?":
                    displayHelp(); // 도움말 메뉴
                    break;

                case "exit":
                    quit = true; // 프로그램 종료
                    break;

                default:
                    System.out.println("? for help."); // 잘못된 명령어 입력 시 안내
                    break;
            }
        }
        while (!quit);
    }
}