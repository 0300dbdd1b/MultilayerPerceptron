#include <cstring>
#include <stdexcept>
#ifndef __ACTIVATION_FUNCTIONS__
# define __ACTIVATION_FUNCTIONS__
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wc++11-extensions"

# include <cmath>

# ifndef  ELU_ALPHA
#  define ELU_ALPHA 1
# endif

# ifndef  TRELU_TRESHOLD
#  define TRELU_TRESHOLD 0.5
# endif

# ifndef LRELU_ALPHA
#  define LRELU_ALPHA 0.001
# endif

//# define TRELU_TRESHOLD
//# define LRELU_ALPHA
# define ACTIVATION_FUNCTION_SIZE 10


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
T relu(T val, bool derivative = false)
{
	if (derivative)
	{
		return val > 0 ? 1 : 0;
	}
	return  val > 0 ? val : 0;
}

template <typename T>
T lrelu(T val, bool derivative = false)
{
	if (derivative)
	{
		return val > 0 ? 1 : T(LRELU_ALPHA);
	}
	return val > 0 ? val : T(LRELU_ALPHA) * val;
}

template <typename T>
T trelu(T val, bool derivative = false)
{
	if (derivative)
	{
		return (val > (T)TRELU_TRESHOLD) ? 1 : 0;
	}
	return (val > (T)TRELU_TRESHOLD) ? val : 0;
}

template <typename T>
T elu(T val, bool derivative = false)
{
	if (derivative)
	{
		return (val > 0) ? 1 : (T)(ELU_ALPHA * std::exp(val));
	}
	return (val >= 0) ? val : (T)(ELU_ALPHA * (std::exp(val) - 1));
}

template <typename T>
T selu(T val, bool derivative = false)
{
	const T alpha = static_cast<T>(1.67326);
	const T lambda = static_cast<T>(1.0507);
	if (derivative)
	{
		return (val > 0) ? lambda : lambda * alpha * std::exp(val);
	}
	return (val > 0) ? lambda * val : lambda * alpha * (std::exp(val)-1);
}

template <typename T>
T gelu(T val, bool derivative = false)
{
	const T sqrt_2_over_pi = std::sqrt(2.0 / M_PI);
	const T coeff = 0.044715;

	if (derivative)
	{
		T tanh_value = std::tanh(sqrt_2_over_pi * (val + coeff * std::pow(val, 3)));
		T sec2_value = 1.0 - std::pow(tanh_value, 2);
		T term1 = 0.5 * (1.0 + tanh_value);
        T term2 = sqrt_2_over_pi * val * sec2_value * (1.0 + 3.0 * coeff * std::pow(val, 2));
		return term1 + term2;
	}
    return 0.5 * val * (1.0 + std::tanh(sqrt_2_over_pi * (val + coeff * std::pow(val, 3))));
	
}

template <typename T>
T softsign(T val, bool derivative = false)
{
	if (derivative)
	{
		const T denom = (1 + std::abs(val));
		return 1 / (denom * denom);
	}
	return val / (1 + std::abs(val));
}

template <typename T>
T softplus(T val, bool derivative = false)
{
	if (derivative)
	{
		return 1 / ( 1 + std::exp(-val));
	}
	return std::log(1 + std::exp(val));
}


template <typename T>
class ActivationFunction
{
	public:
		const char *name;
		const char *names[ACTIVATION_FUNCTION_SIZE] = {"sigmoid", "tanh", "relu", "lrelu", "trelu", "elu", "selu", "gelu", "softsign", "softplus"};
		typedef T (*FunctionPointer)(T, bool);
		FunctionPointer functions[ACTIVATION_FUNCTION_SIZE] = 
	{
		sigmoid<T>,
		tanh<T>,
		relu<T>,
		lrelu<T>,
        trelu<T>,
		elu<T>,
		selu<T>,
		gelu<T>,
		softsign<T>,
		softplus<T>
	};
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
	}
	throw  std::runtime_error("Activation function not implemented");
}

# pragma GCC diagnostic pop
#endif
