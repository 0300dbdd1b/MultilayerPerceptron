#include "../includes/Matrix.hpp"
#include "../includes/ActivationFunctions.hpp"
#include "../includes/Perceptron.hpp"
#include <cstdio>
#include <iostream>
#include <ostream>
int main()
{
	ActivationFunction<double>a("sigmoid");
	Perceptron<double>p("sigmoid");
	std::cout << a.activate(3, false) << std::endl;

}
