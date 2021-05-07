#include <iostream>
using namespace std;

/**
 * Access Modifier => Public, Private,Protected
 * Private =>Cannot be directly modified from outside It can only be modified using function in class
 * Encapsulation
 * 
*/

class Employee
{
private:
    string Name;
    string Company;
    int Age;
    // protected:
    //     string Name;
    //     string Company;
    //     int Age;
    // public:
    //     string Name;
    //     string Company;
    //     int Age;

public:
    //Calling Constructor
    Employee(string name, string company, int age)
    {
        Name = name;
        Company = company;
        Age = age;
    }

    void Introduce()
    {
        cout << "Name : " << Name << endl;
        cout << "Company: " << Company << endl;
        cout << "Age : " << Age << endl
             << endl;
    }
};

int main()
{
    Employee employee1("Anish", "Infosys", 23);
    Employee employee2("Anagh", "Google", 22);
    employee1.Introduce();
    employee2.Introduce();

    // employee1.Name = "Anish";
    // cout << employee1.Name;

    return 0;
}