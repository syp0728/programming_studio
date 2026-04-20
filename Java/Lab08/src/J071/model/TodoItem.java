package J071.model;

import java.text.SimpleDateFormat;
import java.util.Date;

public class TodoItem {
    // 멤버 변수
    private String title;
    private String detail;
    private Date reg_date;

    // 모든 Todo 정보를 포함하여 생성한 생성자
    public TodoItem(String title, String detail) {
        this.title = title;
        this.detail = detail;
        this.reg_date = new Date();
    }

    // Getter & Setter
    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getDetail() {
        return detail;
    }

    public void setDetail(String detail) {
        this.detail = detail;
    }

    public Date getReg_date() {
        return reg_date;
    }

    public void setReg_date(Date reg_date) {
        this.reg_date = reg_date;
    }


    @Override
    public String toString() {
        return "[" + title + "]" + detail + "-" + new SimpleDateFormat("yyyy/MM/dd").format(reg_date);
    }
}