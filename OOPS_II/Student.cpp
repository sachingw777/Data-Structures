#include <string.h>

class Student {
	int age;
	char *name;

	public :

	Student(int age, char *name) {
		this -> age = age;
		// Shallow copy
		// this -> name = name;
	
		// Deep copy
		this -> name = new char[strlen(name) + 1];
		strcpy(this -> name, name);
	
	}

	//Copy Constructor
	Student(Student const & s){
		this->age = s.age;
		// this->name = s.name;

		this->name = new char[strlen(name) + 1];
		strcpy(this->name, s.name);
	}

	void display() {
		cout << name << " " << age << endl;
	}
};
