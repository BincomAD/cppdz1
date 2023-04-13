#pragma once

#include "ICalculatable.h"

class Multiplication : public ICalculatable {
private:
	ICalculatable* _leftOperand;
	ICalculatable* _rightOperand;
public:
	Multiplication(ICalculatable* left, ICalculatable* right);
	virtual ~Multiplication();
	virtual double Calculate() const override;
};