package J034.model;

public class User {
    private String username;
    private String password;

    public User(String username, String password) {
        this.username = username;
        this.password = password;
    }

    public boolean matchId(String inputId) {
        return this.username.equals(inputId);
    }

    public boolean matchPassword(String inputPw) {
        return this.password.equals(inputPw);
    }
}