#include "../includes/Matrix.hpp"
#include "../includes/ActivationFunctions.hpp"
#include "../includes/Perceptron.hpp"
#include <cstdio>
#include <iostream>
#include <ostream>
int main()
{
	ActivationFunction<double>a("trelu");
	Perceptron<double>p("sigmoid");
	std::cout << "A = " << a.activate(3.0, false) << std::endl;
}

