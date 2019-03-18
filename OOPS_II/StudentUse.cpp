#include <iostream>
using namespace std;
#include "Student.cpp"

int main() {
	char name[] = "abcd";
	Student s1(20,name);
	s1.display();
	name[0] = 'X';
	// Student s2(20,name);
	// s2.display();
	// s1.display();
	
	Student s3(s1);
	s3.display();
}