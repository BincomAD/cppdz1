#pragma once

#include "ICalculatable.h"
#include <cmath>

class Bracket : public ICalculatable {
private:
	std::unique_ptr<ICalculatable> _Operand;
public:
	Bracket(std::unique_ptr<ICalculatable> operand);
	virtual double Calculate() const override;
};
