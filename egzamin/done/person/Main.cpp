#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <iterator>


class Person {
public:
    std::string last_name;
    std::string first_name;

    Person(const std::string& last_name, const std::string& first_name)
        : last_name(last_name), first_name(first_name) {}

    bool operator<(const Person& other) const {
        if (last_name != other.last_name)
            return last_name < other.last_name;
        return first_name < other.first_name;
    }
};

std::ostream& operator<<(std::ostream& os, const Person& person) {
    os << person.last_name << " " << person.first_name;
    return os;
}


int main (){
    typedef std::set<Person> kontener_typ;
    kontener_typ c;
    c.insert(Person("Nowak","Jan"));
    c.insert(Person("Nowak","Adam"));
    c.insert(Person("Kowalski","Jan"));
    c.insert(Person("Nowak","Adam"));
    c.insert(Person("Iksinski","Adam"));
    std::copy (c.begin(), c.end(), std::ostream_iterator<Person>(std::cout, ", "));
}
// Wynika działania:
// Iksinski Adam, Kowalski Jan, Nowak Adam, Nowak Jan,