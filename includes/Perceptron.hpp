#if !defined(__PERCEPTRON__)
# define __PERCEPTRON__
# include "../includes/Matrix.hpp"
# include "../includes/ActivationFunctions.hpp"

template <typename T>
class Perceptron
{
	public:
	
	ActivationFunction<T> function;
	Matrix<T>	ins;
	Matrix<T>	weights;
	Matrix<T>	outs;

	Perceptron();
	Perceptron(const char* activation_fn);


	private:
	
};

template  <typename T>
Perceptron<T>::Perceptron(){}

template <typename T>
Perceptron<T>::Perceptron(const char *activation_fn)
{
	this->function = ActivationFunction<T>(activation_fn);
}
#endif
