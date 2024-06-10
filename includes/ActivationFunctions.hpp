#if !defined(__ACTIVATION_FUNCTIONS__)
# define __ACTIVATION_FUNCTIONS__
# include <cmath>
# include <cstring>

template  <typename T>
T sigmoid(T val, bool derivative = false);

template <typename T>
T tanh(T val, bool derivative = false);

template <typename T>
class ActivationFunction
{
	public:
	const char *name;
	const char *names[2] = {"sigmoid", "tanh"};
	typedef T (*FunctionPointer)();
	FunctionPointer functions[2] = {sigmoid, tanh};
	T activate(T val, bool derivative = false);
	ActivationFunction(const char *name);
};
#endif
