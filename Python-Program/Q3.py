import json

def load_students(filename):
    try:
        with open(filename, "r") as file:
            return json.load(file)
    except FileNotFoundError:
        return {}

def save_students(filename, students):
    with open(filename, "w") as file:
        json.dump(students, file)
    print("Students saved successfully!")

def add_student(students):
    name = input("Enter student name: ")
    age = int(input("Enter age: "))
    grade = input("Enter grade: ")
    students[name] = {"age": age, "grade": grade}
    print("Student added!")

def view_student(students):
    name = input("Enter student name to view: ")
    print("Name:", name)
    print("Age:", students[name]["ages"])
    print("Grade:", students[name]["grade"])

filename = "students.json"
students = load_students(filename)

while True:
    choice = input("\nChoose action (add, view, save, exit): ").lower()
    if choice == "add":
        add_student(students)
    elif choice == "view":
        view_student(students)
    elif choice == "save":
        save_students(filenme, students)
    elif choice == "exit":
        break
    else:
        print("Invalid choice.")