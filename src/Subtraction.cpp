#include "Subtraction.h"

Subtraction::Subtraction(std::unique_ptr<ICalculatable> left, std::unique_ptr<ICalculatable> right) :
	_leftOperand(std::move(left)), _rightOperand(std::move(right)) {}

double Subtraction::Calculate() const {
	return _leftOperand->Calculate() - _rightOperand->Calculate();
}
