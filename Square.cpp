#include "Square.h"

Square::Square(ICalculatable* operand) :
	_Operand(operand) {}

Square::~Square() {
	delete _Operand;
}

double Square::Calculate() const {
	return std::sqrt(_Operand->Calculate());
}
