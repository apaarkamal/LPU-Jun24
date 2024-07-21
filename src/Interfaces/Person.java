package Interfaces;

// implements and extends?/
public class Person implements Student, User, Comparable<Person> {
    String name;
    String email;
    Person(String name, String email){
        this.name = name;
        this.email=email;
    }
    @Override
    public String getName() {
        return name;
    }

    @Override
    public String getEmail() {
        return email;
    }

    @Override
    public void where() {
        Student.super.where();
        User.super.where();
    }

    @Override
    public String toString() {
        return "Person{" +
                "name='" + name + '\'' +
                ", email='" + email + '\'' +
                '}';
    }

    public void updateName(String name){
        this.name = name;
    }

    @Override
    public int compareTo(Person o) {
        return name.compareTo(o.name);
    }
}
