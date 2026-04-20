package J034;

import J034.model.User;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        String[] usernames = {"kim", "lee", "park", "hong", "choi"};
        String[] passwords = {"1111", "1234", "3456", "3535", "7777"};

        User[] users = new User[5];
        for (int i = 0; i < 5; i++) {
            users[i] = new User(usernames[i], passwords[i]);
        }

        String inputname = s.nextLine();
        String inputps = s.nextLine();

        String message = "No user!\n";

        for (int i = 0; i < 5; i++) {
            if (users[i].matchId(inputname)) {
                if (users[i].matchPassword(inputps)) {
                    message = "Login OK!\n";
                } else {
                    message = "Incorrect password!\n";
                }
                break;
            }
        }
        System.out.printf(message);
    }
}