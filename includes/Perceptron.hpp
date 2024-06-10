#include "../includes/Matrix.hpp"
#include <string>

template <typename T>
class Perceptron
{
	public:
	Matrix<T> ins;
	Matrix<T> weights;
	Matrix<T> outs;

	Perceptron();
	Perceptron(std::string activation_fn);


	private:
	
}
