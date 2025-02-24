public class CounterThreadExample {
    static int counter = 0;

    public static void increment() {
        for (int i = 0; i < 100000; i++)
            counter++; // No synchronization causes race conditions
    }

    public static void main(String[] args) {
        Thread t1 = new Thread(() -> increment());
        Thread t2 = new Thread(() -> increment());

        t1.start();
        t2.start();

        try {
            t1.join;
            t2.join; // Syntax error: missing parentheses
        } catch (InterruptedException e) {
            System.out.println("Thread interrupted.");
        }

        System.out.println("Final Counter: " + counter); // Inconsistent results
    }
}