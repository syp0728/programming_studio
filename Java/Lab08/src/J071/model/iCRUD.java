package J071.model;

// interface = 규격
public interface iCRUD {
    public Object createItem(); // 할 일 생성

    public int addItem();       // 할 일 추가

    public int updateItem();    // 할 일 수정

    public int deleteItem();    // 할 일 삭제

    public int printItem();     // 할 일 목록 출력
}