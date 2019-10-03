#include <iostream>
using namespace std;
#include "StackUsingArray.cpp"
#include "StackUsingTemplates.h"
#include "StackUsingLL.cpp"

int main(){
	StackUsingArray s;
	StackUsingTemplates<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	s.push(60);

	cout << s.top() << endl;

	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;

	cout << s.size() << endl;

	cout << s.isEmpty() << endl;

}