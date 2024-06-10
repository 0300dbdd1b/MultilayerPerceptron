#include "../includes/Perceptron.hpp"

template <typename T>
Perceptron<T>::Perceptron(const char* activation_fn)
{
	this->function = ActivationFunction(activation_fn);
}
