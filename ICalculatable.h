#pragma once

// ��������� ICalculatable
class ICalculatable
{
public:
    virtual double Calculate() const = 0;
    virtual ~ICalculatble() {}
};
