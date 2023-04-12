#pragma once

#include "ICalculatable"

class Number : public ICalculatble {
private:
	double m_value;
public: 
	Number(double value) : m_value(value) {}

	virtual double Calculate() const override {
		return m_value;
	}
};