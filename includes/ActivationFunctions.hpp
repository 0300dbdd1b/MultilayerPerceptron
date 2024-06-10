#include <cstring>
#if !defined(__ACTIVATION_FUNCTIONS__)
# define __ACTIVATION_FUNCTIONS__
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wc++11-extensions"

# include <cmath>
# define ACTIVATION_FUNCTION_SIZE 2

template  <typename T>
T sigmoid(T val, bool derivative = false)
{
	T sigmoid_value =  1 / (1 + std::exp(-val));
	if (derivative)
	{
		return  sigmoid_value * (1 - sigmoid_value);
	}
	return sigmoid_value;
}

template <typename T>
T tanh(T val, bool derivative = false)
{
	T tanh_value = std::tanh(val);
	if (derivative)
	{
		return 1 - (tanh_value * tanh_value);
	}
	return tanh_value;
}

template <typename T>
class ActivationFunction
{
	public:
	const char *name;
	const char *names[ACTIVATION_FUNCTION_SIZE] = {"sigmoid", "tanh"};
	typedef T (*FunctionPointer)(T, bool);
	FunctionPointer functions[ACTIVATION_FUNCTION_SIZE] = {sigmoid<T>, tanh<T>};
	T activate(T val, bool derivative = false);
	ActivationFunction();
	ActivationFunction(const char *name);
};

template  <typename T>
ActivationFunction<T>::ActivationFunction(){}

template  <typename T>
ActivationFunction<T>::ActivationFunction(const char *name)
{
	this->name = name;
}

template <typename T>
T ActivationFunction<T>::activate(T val, bool derivative)
{
	for (int i = 0; i < ACTIVATION_FUNCTION_SIZE; i++)
	{
		if (std::strcmp(this->names[i], this->name) == 0)
		{
			return this->functions[i](val, derivative);
		}
		return (T)0;
	}
	return (T)0;
}

# pragma GCC diagnostic pop
#endif
