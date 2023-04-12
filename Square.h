#pragma once

#include "ICalculatable.h"
#include <cmath>

class Square : public ICalculatable {
private:
	ICalculatable* _Operand;
public:
	Square(ICalculatable* operand);
	virtual ~Square();
	virtual double Calculate() const override;
};