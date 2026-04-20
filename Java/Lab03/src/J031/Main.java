package J031;

import J031.model.User;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        String userid = s.nextLine();
        String password = s.nextLine();
        String name = s.nextLine();

        User user = new User(userid, password, name);

        if (!user.isPasswordValid()) {
            System.out.println("Error! password is too short.");
            return;
        }

        System.out.println("User Id: " + user.getUserid());
        System.out.println("Password: " + user.getMaskedPassword());
        System.out.println("User Name: " + user.getName());
    }
}