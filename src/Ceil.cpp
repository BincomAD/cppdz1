#include "Ceil.h"

Ceil::Ceil(ICalculatable* operand) :
	_Operand(operand) {}

Ceil::~Ceil() {
	delete _Operand;
}

double Ceil::Calculate() const {
	return std::ceil(_Operand->Calculate());
}
