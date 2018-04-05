#include <iostream>
#include <string>

using namespace std;

class Person
  {
	protected:
	string name;
	int birthYear;
	public:
	  Person(string name, int birthYear):name(name),birthYear(birthYear){}
	void Print(){cout << name << ' ' << birthYear << endl;}
	void SetBirthYear(int birthYear){this->birthYear = birthYear; }
  };

class Employee: public Person
  {
	int employmentYear;
	public:
	Employee(string name, int birthYear, int employmentYear):Person(name,birthYear),employmentYear(employmentYear){}
	  /*{
		this->employmentYear = employmentYear;
	  }*/
	
	
	/* */
	void Print() {cout<<name<<' '<<birthYear<<' '<<employmentYear<<endl;}
	void SetEmploymentYear(int employmentYear)
	  {
		this->employmentYear = employmentYear;
	  }

	/* */
  };


int main()
{
	Employee e("Ubul",1965, 1965);
	e.SetBirthYear(1975);
	e.Print();
	Person person("Garfield",1965);
	Employee employee("Ubul",1964,1965);
	person.SetBirthYear(1964);
	
	employee.SetBirthYear(1964);
	person.Print();
	employee.Print();

	Employee employee2("Ubul",1964,1965);
	Person* pPerson = &employee2;

	//pPerson->SetEmploymentYear(1980);
	pPerson->Print();
	employee2.Print();
}
