/**
 * some notes.
 * if we want to referencing a class externally, we don't have to import it. 
 * We just have to put the test file and class file in the same directory.
**/
public class EmployeeTest {
  public static void main(String[] args) {
    Employee emp_0 = new Employee("Jason");
    Employee emp_1 = new Employee("Tommy");
    emp_0.set_age(20);
    emp_0.set_designation("Senior Programmer");
    emp_0.set_salary(19198.10);
    emp_1.set_age(22);
    emp_1.set_designation("Junior Programmer");
    emp_1.set_salary(114.514);
    emp_0.print_information();
    System.out.println("");
    emp_1.print_information();
  }
}