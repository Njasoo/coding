public class Employee {
  String name;
  int age;
  String designation;
  double salary;

  public Employee(String name) {
    this.name = name;
  }
  public void set_age(int age) {
    this.age = age;
  }
  public void set_designation(String designation) {
    this.designation = designation;
  }
  public void set_salary(double salary) {
    this.salary = salary;
  }
  public void print_information() {
    System.out.println("name: " + this.name);
    System.out.println("age: " + this.age);
    System.out.println("designation: " + this.designation);
    System.out.println("salary: " + this.salary);            
  }
}