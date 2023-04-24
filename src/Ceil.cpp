#include "Ceil.h"

Ceil::Ceil(std::unique_ptr<ICalculatable> operand) :
	_Operand(std::move(operand)) {}

double Ceil::Calculate() const {
	return std::ceil(_Operand->Calculate());
}
