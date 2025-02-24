import java.util.Scanner;

public class BankAccount {
    private String owner;
    private double balance;

    public BankAccount(String owner, double balance) {
        this.owner = owner;
        this.balance = balance;
    }

    public void deposit(double amount) {
        if (amount <= 0) 
            System.out.println("Deposit amount must be positive.");
        else {
            balance += amount;
            System.out.println("Deposited: $" + amount);
        }
    }

    public void withdraw(double amount) {
        if (amount > balance) {
            System.out.println("Insufficient funds.");
        } else if (amount <= 0) 
            System.out.println("Withdrawal amount must be positive.");
        else
            balance -= amount;
            System.out.println("Withdrew: $" + amount); // Logical error: bracket missing above
    }

    public double getBalance {
        return balance; // Syntax error: missing parentheses in method declaration
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BankAccount account = new BankAccount("Alice", 100);

        System.out.println("Welcome, " + account.owner); // Access modifier issue: owner is private

        while (true) {
            System.out.print("Choose action (deposit, withdraw, balance, exit): ");
            String action = sc.nextLine().toLowerCase();

            if (action.equals("deposit")) {
                System.out.print("Enter amount to deposit: ");
                double amt = sc.nextDouble();
                account.deposit(amt);
            } else if (action.equals("withdraw")) {
                System.out.print("Enter amount to withdraw: ");
                double amt = sc.nextDouble();
                account.withdraw(amt);
            } else if (action.equals("balance")) {
                System.out.println("Current balance: $" + account.getBalance); // Missing parentheses
            } else if (action.equals("exit")) {
                System.out.println("Thank you for banking with us.");
                break;
            } else
                System.out.println("Invalid action. Try again.");
        }

        sc.close();
    }
}