package J071.model;

import java.util.*;

// iCRUD 인터페이스를 구현하여 할 일 관리 기능을 제공하는 클래스
public class TodoCRUD implements iCRUD {
    Scanner s = new Scanner(System.in);

    // 데이터를 저장할 동적 리스트
    private ArrayList<TodoItem> list;

    public TodoCRUD() {
        this.list = new ArrayList<TodoItem>();
    }

    @Override
    public Object createItem() {
        return null;
    }

    // 새로운 할 일 항목을 리스트에 추가
    @Override
    public int addItem() {
        String title, desc;

        System.out.print("Add a Todo item\n" + "Enter the title: ");

        title = s.nextLine().trim();

        // 제목 중복 여부 확인
        if (isDuplicated(title)) {
            System.out.println("Title can't be duplicated.");
            return 1;
        }

        System.out.print("Enter the detail: ");
        desc = s.nextLine().trim();
        ;

        TodoItem t = new TodoItem(title, desc);
        this.list.add(t); // 리스트에 새 항목 삽입
        System.out.println("item added.");
        return 0;
    }


    // 입력받은 제목을 찾아 해당 항목의 상세 내용을 수정
    @Override
    public int updateItem() {
        printAll(); // 목록 먼저 출력
        if (list.isEmpty()) return 1;

        System.out.print("Update a Todo item\n" + "Enter the title of the item to edit: ");

        String targetTitle = s.nextLine().trim();

        // 리스트 순회하며 제목 일치 확인
        for (int i = 0; i < list.size(); i++) {
            TodoItem item = list.get(i);
            if (item.getTitle().equals(targetTitle)) {
                System.out.println(item.toString()); // 현재 정보 한 번 보여주기
                System.out.print("Enter the detail: ");
                String newDetail = s.nextLine().trim();

                item.setDetail(newDetail);
                System.out.println("item updated.");
                return 0;
            }
        }
        System.out.println("Not found."); // 일치하는 제목이 없을 경우
        return 1;


    }



    // 입력받은 제목을 찾아 해당 항목을 리스트에서 제거
    @Override
    public int deleteItem() {
        if (list.isEmpty()) return 1;

        System.out.print("Delte a Todo item\n" + "Enter the title of the item to remove: ");

        String targetTitle = s.nextLine().trim();

        for (int i = 0; i < list.size(); i++) {
            if (list.get(i).getTitle().equals(targetTitle)) {
                System.out.println(list.get(i).toString()); // 삭제할 정보 보여주기
                list.remove(i); // 리스트에서 삭제
                System.out.println("item deleted.");
                return 0; // 삭제 성공 후 종료
            }
        }

        System.out.println("Not found.");
        return 1;

    }

    @Override
    public int printItem() {
        return printAll();
    }


    // 제목 중복을 체크하는 헬퍼 메소드
    boolean isDuplicated(String title) {
        for (TodoItem item : this.list) {
            if (title.equals(item.getTitle())) {
                return true;
            }
        }
        return false;
    }


    // 현재 리스트의 모든 항목을 출력
    public int printAll() {

        System.out.println("Total" + this.list.size() + " items");
        for (TodoItem item : this.list) {
            System.out.println(item.toString());
        }
        return 0;
    }


    // 이름 순서대로 정렬
    public void sortByName() {
        Collections.sort(this.list, new TodoitemNameComparator());
    }

    // 날짜 순서대로 정렬
    public void sortByDate() {
        Collections.sort(this.list, new TodoItemDateComparator());
    }

    // 거꾸로 정렬
    public void reverseList() {
        Collections.reverse(this.list);
    }
}


// 제목 기준 오름차순 정렬을 위한 비교
class TodoitemNameComparator implements Comparator<TodoItem> {

    @Override
    public int compare(TodoItem o1, TodoItem o2) {
        return o1.getTitle().compareTo(o2.getTitle());
    }
}


// 등록 날짜 기준 오름차순 정렬을 위한 비교
class TodoItemDateComparator implements Comparator<TodoItem> {

    @Override
    public int compare(TodoItem o1, TodoItem o2) {
        return o1.getReg_date().compareTo(o2.getReg_date());
    }
}
