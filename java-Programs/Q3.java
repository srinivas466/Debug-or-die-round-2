import java.util.*;
import java.io.*;

public class StudentManager {
    private static Map<String, Student> students = new HashMap<>();

    public static void addStudent(Scanner sc) {
        System.out.print("Enter name: ");
        String name = sc.nextLine();
        System.out.print("Enter age: ");
        int age = Integer.parseInt(sc.nextLine());
        System.out.print("Enter grade: ");
        String grade = sc.next();

        students.put(name, new Student(name, age, grade));
        System.out.println("Student added.");
    }

    public static void viewStudent(Scanner sc) {
        System.out.print("Enter student name: ");
        String name = sc.nextLine();
        if (students.contains(name)) // Error: should use containsKey
            System.out.println(students.get(name).toString());
        else
            System.out.println("Student not found.");
    }

    public static void saveStudents(String filename) throws IOException {
        BufferedWriter writer = new BufferedWriter(new FileWriter(filename));
        for (Student s : students.values())
            writer.write(s.toString() + "\n");
        writer.close();
        System.out.println("Students saved.");
    }

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        while (true) {
            System.out.print("Choose (add, view, save, exit): ");
            String choice = sc.nextLine();

            if (choice.equals("add"))
                addStudent(sc);
            else if (choice.equals("view"))
                viewStudent(sc);
            else if (choice.equals("save"))
                saveStudents("students.txt");
            else if (choice.equals("exit")) {
                System.out.println("Goodbye!");
                break;
            } else
                System.out.println("Invalid choice.");
        }
        sc.close();
    }
}

class Student {
    private String name;
    private int age;
    private String grade;

    public Student(String name, int age, String grade) {
        this.name = name;
        this.age = age;
        this.grade = grade;
    }

    @Override
    public String toString() {
        return "Name: " + name + " | Age: " + age + " | Grade: " + grade;
    }
}