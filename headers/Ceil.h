#pragma once

#include "ICalculatable.h"
#include <cmath>

class Ceil : public ICalculatable {
private:
	ICalculatable* _Operand;
public:
	Ceil(ICalculatable* operand);
	virtual ~Ceil();
	virtual double Calculate() const override;
};