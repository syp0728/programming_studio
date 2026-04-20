package J031.model;

public class User {
    private String userid;
    private String password;
    private String name;

    public User(String userid, String password, String name) {
        this.userid = userid;
        this.password = password;
        this.name = name;
    }

    public String getMaskedPassword() {
        String secret = this.password.substring(0, 2);
        for (int i = 2; i < this.password.length(); i++) {
            secret += "*";
        }
        return secret;
    }

    public boolean isPasswordValid() {
        return this.password.length() >= 3;
    }

    public String getUserid() { return userid; }
    public String getName() { return name; }
}