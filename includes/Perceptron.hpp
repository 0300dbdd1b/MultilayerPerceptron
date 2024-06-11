#ifndef __PERCEPTRON__
# define __PERCEPTRON__
# include "../includes/Matrix.hpp"
# include "../includes/ActivationFunctions.hpp"

template <typename T>
class Perceptron
{
	public:
	
		ActivationFunction<T> function;
		Matrix<T>	weights;

		Perceptron();
		Perceptron(const char* activation_fn);
	
		T activate(Matrix<T> ins, const bool derivative = false);

	private:
	
};

template  <typename T>
Perceptron<T>::Perceptron(){}

template <typename T>
Perceptron<T>::Perceptron(const char *activation_fn)
{
	this->function = ActivationFunction<T>(activation_fn);
}

template <typename T>
T Perceptron<T>::activate(Matrix<T> ins, const bool derivative)
{
	T sum = (T)0;
	for (int i = 0; i < ins.ncol; i++)
	{
		for (int j = 0; j < ins.nrow; j++)
		{
			sum += (ins[i][j] * weights[i][j]);
		}
	}
	return this->function.activate(sum, derivative);
}
#endif
