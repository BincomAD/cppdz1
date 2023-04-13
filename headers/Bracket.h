#pragma once

#include "ICalculatable.h"
#include <cmath>

class Bracket : public ICalculatable {
private:
	ICalculatable* _Operand;
public:
	Bracket(ICalculatable* operand);
	virtual ~Bracket();
	virtual double Calculate() const override;
};