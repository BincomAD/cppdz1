#include "Bracket.h"

Bracket::Bracket(ICalculatable* operand) :
	_Operand(operand) {}

Bracket::~Bracket() {
	delete _Operand;
}

double Bracket::Calculate() const {
	return _Operand->Calculate();
}
