#include<iostream>
#include<conio.h>
#include<fstream>
#include <sstream>

using namespace std;
class variable {

public:
	char* name;
	char* value;
	void set_values(char*, char*);
};
void variable::set_values(char* x, char* y) {
	name = x;
	value = y;

}

template <typename T>
T addition(T a, T  b)
{
	return a + b;
}
template <typename T>
T  subtraction(T a, T b)
{
	return a - b;
}
template <typename T>
T  multiplication(T a, T b)
{
	return a*b;
}
template <typename T>
T  division(T a, T b)
{
	return a / b;
}