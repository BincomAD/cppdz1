#pragma once

#include <memory>

class ICalculatable
{
public:
    virtual double Calculate() const = 0;
};
