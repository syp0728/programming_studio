package J063.model;

import J063.model.Todo;
import java.util.ArrayList;
import java.util.Scanner;

public class TodoCRUD {
    ArrayList<Todo> list;
    Scanner s;

    public TodoCRUD() {
        list = new ArrayList<Todo>();
    }


    public void addTodo(){
        String title, date, category, content;

        s = new Scanner(System.in);

        // 할 일
        System.out.print("Title > ");
        title = s.nextLine();

        // 날짜
        System.out.print("Date > ");
        date = s.nextLine();

        // 카테고리
        System.out.print("Category > ");
        category = s.nextLine();

        // 내용
        System.out.print("Content > ");
        content = s.nextLine();

        Todo new_todo = new Todo(title, date, category, content);
        list.add(new_todo);
    }

    // 할 일 수정
    public void editTodo(){
        listTodo();

        System.out.print("Number > ");
        int id = s.nextInt();
        s.nextLine(); // 버퍼 비우기

        if(id > 0 && id <= list.size()){
            System.out.print("New todo > ");
            String newTitle = s.nextLine();
            list.get(id - 1).setTitle(newTitle); // 해당 할 일의 제목 수정

            System.out.print("New date > ");
            String newDate = s.nextLine();
            list.get(id - 1).setDate(newDate); // 해당 할 일의 날짜 수정

            System.out.print("New content > ");
            String newContent = s.nextLine();
            list.get(id - 1).setContent(newContent); // 해당 할 일의 내용 수정
        } else {
            System.out.println("Invalid number");
        }
    }

    // 할 일 목록 출력
    public void listTodo(){
        for(int i=0; i<list.size(); i++){
            System.out.printf("%d - %s\n", i+1, list.get(i).toString());
        }
    }

    // 할 일 삭제
    public void deleteTodo(){
        listTodo();

        System.out.print("Number > ");
        int id = s.nextInt();

        if(id > 0 && id <=list.size()){
            list.remove(id - 1);  // 인덱서를 이용하여 리스트에서 삭제
            System.out.println("Delete");
        } else {
            System.out.println("Invalid number");
        }
    }
}