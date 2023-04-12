#pragma once

#include "ICalculatable.h"

class Number : public ICalculatable {
private:
	double m_value;
public: 
	Number(double value) : m_value(value) {}

	virtual double Calculate() const override {
		return m_value;
	}
};
