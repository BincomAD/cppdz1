#pragma once

class ICalculatable
{
public:
    virtual ~ICalculatable() {}
    virtual double Calculate() const = 0;
};
