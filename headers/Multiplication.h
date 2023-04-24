#pragma once

#include "ICalculatable.h"

class Multiplication : public ICalculatable {
private:
	std::unique_ptr<ICalculatable> _leftOperand;
	std::unique_ptr<ICalculatable> _rightOperand;
public:
	Multiplication(std::unique_ptr<ICalculatable> left, std::unique_ptr<ICalculatable> right);
	virtual double Calculate() const override;
};
