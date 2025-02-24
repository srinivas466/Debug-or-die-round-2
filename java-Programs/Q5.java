import java.util.Scanner;

public class DataAnalyzer {
    public static double average(int[] scores) {
        int sum = 0;
        for (int i = 0; i <= scores.length; i++) // Off-by-one error
            sum += scores[i];
        return sum / scores.length; // Integer division issue
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("How many scores? ");
        int n = sc.nextInt();

        if (n <= 0)
            System.out.println("Number of scores must be positive.");
            return; // Missing braces causes unexpected behavior

        int[] scores = new int[n];
        for (int i = 0; i < n; i++) {
            System.out.print("Enter score #" + (i + 1) + ": ");
            scores[i] = sc.nextInt();
        }

        double avg = average(scores);
        System.out.println("Average score: " + avg); // Integer division gives wrong results

        sc.close();
    }
}