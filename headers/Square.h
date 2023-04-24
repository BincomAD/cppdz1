#pragma once

#include "ICalculatable.h"
#include <cmath>

class Square : public ICalculatable {
private:
	std::unique_ptr<ICalculatable> _Operand;
public:
	Square(std::unique_ptr<ICalculatable> operand);
	virtual double Calculate() const override;
};
