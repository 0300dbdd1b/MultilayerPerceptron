#include "../includes/Matrix.hpp"
#include "../includes/ActivationFunctions.hpp"
#include <iostream>
#include <ostream>
int main()
{
	ActivationFunction<int>a = ActivationFunction<int>("sigmoid");
	a.activate(5);

	std::cout << "Hello World" << std::endl;

}
