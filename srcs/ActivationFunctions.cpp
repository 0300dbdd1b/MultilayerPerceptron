#include "../includes/ActivationFunctions.hpp"

template  <typename T>
ActivationFunction<T>::ActivationFunction(const char *name)
{
	this->name = name;
}

template <typename T>
T ActivationFunction<T>::activate(T val, bool derivative)
{
	int arraySize = sizeof(this->names) / sizeof(this->names[0]);
	for (int i = 0; i < arraySize; ++i)
	{
		if (!strcmp(this->names[i], this->name))
		{
			return this->functions[i](val, derivative);
		}
	}
	return;
}

template <typename T>
T sigmoid(T val, bool derivative)
{
	T sigmoid_value = 1 / (1 + std::exp(-val));
	if (derivative) 
	{
		return sigmoid_value * (1 - sigmoid_value);
	}
	else
	{
		return  sigmoid_value;
	}
}

template <typename T>
T tanh(T val, bool derivative)
{
	T tanh_value = std::tanh(val);
	if (derivative)
	{
		return 1 - (tanh_value * tanh_value);
	}
	else
	{
		return tanh_value;
	}
}
