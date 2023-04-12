#include "Multiplication.h"

Multiplication::Multiplication(ICalculatable* left, ICalculatable* right) :
	_leftOperand(left), _rightOperand(right) {}

Multiplication::~Multiplication() {
	delete _leftOperand;
	delete _rightOperand;
}

double Multiplication::Calculate() const {
	return _leftOperand->Calculate() * _rightOperand->Calculate();
}
