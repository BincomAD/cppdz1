#pragma once

#include "ICalculatable.h"
#include <cmath>

class Ceil : public ICalculatable {
private:
	std::unique_ptr<ICalculatable> _Operand;
public:
	Ceil(std::unique_ptr<ICalculatable> operand);
	virtual double Calculate() const override;
};
