#include "Subtraction.h"

Subtraction::Subtraction(ICalculatable* left, ICalculatable* right) :
	_leftOperand(left), _rightOperand(right) {}

Subtraction::~Subtraction() {
	delete _leftOperand;
	delete _rightOperand;
}

double Subtraction::Calculate() const {
	return _leftOperand->Calculate() - _rightOperand->Calculate();
}
