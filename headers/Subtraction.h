#pragma once

#include "ICalculatable.h"

class Subtraction : public ICalculatable {
private:
	ICalculatable* _leftOperand;
	ICalculatable* _rightOperand;
public:
	Subtraction(ICalculatable* left, ICalculatable* right);
	virtual ~Subtraction();
	virtual double Calculate() const override;
};
