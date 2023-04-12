#include "Addition.h"

Addition::Addition(ICalculatable* left, ICalculatable* right):
	_leftOperand(left), _rightOperand(right) {}

Addition::~Addition() {
	delete _leftOperand;
	delete _rightOperand;
}

double Addition::Calculate() const override {
	return _leftOperand->Calculate() + _rightOpernd->Calculate();
}