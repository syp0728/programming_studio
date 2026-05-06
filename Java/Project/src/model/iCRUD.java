package src.model;

// interface = 규격
public interface iCRUD {
    public Object createItem(); // Service 생성

    public int addItem();       // Service 추가

    public int updateItem();    // Service 수정

    public int deleteItem();    // Service 삭제

    public int printItem();     // Service 목록 출력
}