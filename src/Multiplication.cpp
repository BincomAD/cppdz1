#include "Multiplication.h"

Multiplication::Multiplication(std::unique_ptr<ICalculatable> left, std::unique_ptr<ICalculatable> right) :
	_leftOperand(std::move(left)), _rightOperand(std::move(right)) {}

double Multiplication::Calculate() const {
	return _leftOperand->Calculate() * _rightOperand->Calculate();
}
