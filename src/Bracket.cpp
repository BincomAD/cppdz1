#include "Bracket.h"

Bracket::Bracket(std::unique_ptr<ICalculatable> operand) :
	_Operand(std::move(operand)) {}

double Bracket::Calculate() const {
	return _Operand->Calculate();
}
