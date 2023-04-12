#include "Subtraction.h"

Subtraction::Subtraction(ICalculatable* left, ICalculatable* right) :
	_leftOperand(left), _rightOperand(right) {}

Subtraction::~Subtraction() {
	delete _leftOperand;
	delete _rightOperand;
}

double Subtraction::Calculate() const override {
	return _leftOperand->Calculate() - _rightOpernd->Calculate();
}