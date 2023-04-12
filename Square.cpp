#include "Square.h"

Square::Square(ICalculatable* operand) :
	_Operand(operand) {}

Square::~Square() {
	delete _Operand;
}

double Square::Calculate() const override {
	return std::sqrt(_Operand->Calculate());
}