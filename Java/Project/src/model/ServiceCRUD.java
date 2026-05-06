package src.model;

import java.util.*;
import java.io.*;

// iCRUD 인터페이스를 구현하여 할 일 관리 기능을 제공하는 클래스
public class ServiceCRUD implements iCRUD {
    Scanner s = new Scanner(System.in);

    // 데이터를 저장할 동적 리스트
    private ArrayList<ServiceItem> list;

    // 파일 이름 변수
    private final String fileName = "services.txt";

    public ServiceCRUD() {
        this.list = new ArrayList<ServiceItem>();
        loadFromFile(); // 생성자에서 파일 불러오기
    }

    @Override
    public Object createItem() {
        return null;
    }

    // 새로운 Service 항목을 리스트에 추가
    @Override
    public int addItem() {
        String name, date, category;
        int price, person;

        System.out.print("Add a Service item\n" + "Enter the name of Service: ");
        name = s.nextLine().trim();

        // 이름 중복 여부 확인
        if (isDuplicated(name)) {
            System.out.println("This name can't be duplicated.");
            return 1;
        }

        System.out.print("Enter your monthly payment amount: ");
        price = s.nextInt();
        s.nextLine();

        System.out.print("Enter the next payment date: ");
        date = s.nextLine();

        System.out.print("Enter the number of people: ");
        person = s.nextInt();
        s.nextLine();

        System.out.print("Please enter a category(video/music/books): ");
        category = s.nextLine().trim();


        ServiceItem o = new ServiceItem(name, price, date, person, category);
        this.list.add(o); // 리스트에 새 항목 삽입

        // 데이터 추가 후 저장
        saveToFile();
        System.out.println("item added. ");
        return 0;
    }


    // 입력받은 제목을 찾아 해당 항목의 상세 내용을 수정
    @Override
    public int updateItem() {
        printAll(); // 목록 먼저 출력
        if (list.isEmpty()) return 1;

        System.out.print("Update Service item\n" + "Enter the name of the item to edit: ");

        String targetName = s.nextLine().trim();

        // 리스트 순회하며 제목 일치 확인
        for (int i = 0; i < list.size(); i++) {
            ServiceItem item = list.get(i);
            if (item.getName().equals(targetName)) {
                System.out.println(item.toString()); // 현재 정보 한 번 보여주기
                System.out.print("Enter the new name: ");
                String newName = s.nextLine().trim();
                item.setName(newName);

                System.out.print("Enter the new price: ");
                int newPrice = s.nextInt();
                s.nextLine();
                item.setPrice(newPrice);

                System.out.print("Enter the new date: ");
                String newDate = s.nextLine();
                item.setDate(newDate);

                System.out.print("Enter the new person number: ");
                int newPerson = s.nextInt();
                s.nextLine();
                item.setPerson(newPerson);

                System.out.print("Enter the new category: ");
                String newCategory = s.nextLine();
                item.setCategory(newCategory);

                // 데이터 수정 후 저장
                saveToFile();
                System.out.println("item updated.");
                return 0;
            }
        }
        System.out.println("Not found."); // 일치하는 이름이 없을 경우
        return 1;
    }


    // 입력받은 이름을 찾아 해당 항목을 리스트에서 제거
    @Override
    public int deleteItem() {
        if (list.isEmpty()) return 1;

        System.out.print("Delte a Service item\n" + "Enter the name of the item to remove: ");

        String targetName = s.nextLine().trim();

        for (int i = 0; i < list.size(); i++) {
            if (list.get(i).getName().equals(targetName)) {
                System.out.println(list.get(i).toString()); // 삭제할 정보 보여주기
                list.remove(i); // 리스트에서 삭제

                // 데이터 삭제 후 저장
                saveToFile();
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


    // 이름 중복을 체크하는 헬퍼 메소드
    boolean isDuplicated(String name) {
        for (ServiceItem item : this.list) {
            if (name.equals(item.getName())) {
                return true;
            }
        }
        return false;
    }


    public int printAll() {
        return printAll(null);
    }

    // StringBuilder를 활용한 method overloading
    public int printAll(String category) {
        int count = 0;
        StringBuilder sb = new StringBuilder(); // 데이터를 모을 바구니 생성

        // 헤더 정보를 StringBuilder에 담기
        sb.append("Name         | Price      | Date         | Person   | Category\n");

        // 조건에 맞는 데이터를 StringBuilder에 추가
        for (ServiceItem item : this.list) {
            if (category == null || item.getCategory().equalsIgnoreCase(category)) {
                sb.append(item.toString()).append("\n");
                count++;
            }
        }

        // 결과 정보 요약
        if (category != null) {
            sb.append("Found ").append(count).append(" items in '").append(category).append("' category.\n");
        } else {
            sb.append("Total ").append(count).append(" items\n");
        }

        // 쌓아둔 모든 내용을 단 한 번의 호출로 콘솔에 출력
        System.out.print(sb.toString());

        return 0;
    }

    // 이름 순서대로 정렬
    public void sortByName() {
        Collections.sort(this.list, new ServiceitemNameComparator());
    }

    // 날짜 순서대로 정렬
    public void sortByDate() {
        Collections.sort(this.list, new ServiceItemDateComparator());
    }

    // 거꾸로 정렬
    public void reverseList() {
        Collections.reverse(this.list);
    }


    // 파일 저장하기 (services.txt에 저장)
    public void saveToFile() {
        try (PrintWriter writer = new PrintWriter(new FileWriter(fileName))) {
            // 파일 최상단에 제목줄 저장
            writer.println("Name         | Price      | Date         | Person   | Category");

            // 데이터 저장
            for (ServiceItem item : list) {
                writer.println(item.toString());
            }
        } catch (IOException e) {
            System.out.println("Error : " + e.getMessage());
        }
    }

    // 파일 불러오기 : Scanner 활용
    public void loadFromFile() {
        File file = new File(fileName);
        if (!file.exists()) return;

        try (Scanner fileScanner = new Scanner(file)) {
            // 첫 번째 줄은 데이터가 아닌 제목이므로 건너뜀
            if (fileScanner.hasNextLine()) fileScanner.nextLine();

            while (fileScanner.hasNextLine()) {
                String line = fileScanner.nextLine();
                // " | " (공백 포함 구분자)를 기준으로 자르고 앞뒤 공백 제거(trim)
                String[] data = line.split("\\|");

                if (data.length == 5) {
                    ServiceItem item = new ServiceItem(
                            data[0].trim(),
                            Integer.parseInt(data[1].trim()),
                            data[2].trim(),
                            Integer.parseInt(data[3].trim()),
                            data[4].trim()
                    );
                    this.list.add(item);
                }
            }
        } catch (Exception e) {
            // 파일 읽기 오류 방지
        }
    }
}


// 제목 기준 오름차순 정렬을 위한 비교
class ServiceitemNameComparator implements Comparator<ServiceItem> {

    @Override
    public int compare(ServiceItem o1, ServiceItem o2) {
        return o1.getName().compareTo(o2.getName());
    }
}


// 등록 날짜 기준 오름차순 정렬을 위한 비교
class ServiceItemDateComparator implements Comparator<ServiceItem> {

    @Override
    public int compare(ServiceItem o1, ServiceItem o2) {
        return o1.getDate().compareTo(o2.getDate());
    }
}
