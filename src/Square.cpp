#include "Square.h"

Square::Square(std::unique_ptr<ICalculatable> operand) :
	_Operand(std::move(operand)) {}

double Square::Calculate() const {
	return std::sqrt(_Operand->Calculate());
}
