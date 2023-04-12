#pragma once

#include "ICalculatable.h"

class Addition : public ICalculatable {
private:
	ICalculatable* _leftOperand;
	ICalculatable* _rightOperand;

public:
	Addition(ICalculatable* left, ICalculatable* right);
	virtual ~Addition();
	virtual double Calculate() const override;
};
