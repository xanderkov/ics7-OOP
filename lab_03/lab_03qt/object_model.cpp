#include "object_model.h"

#include "object_model.hpp"

Model::Model(const Model &other) : VisibleObject(), _carcass(other._carcass) {}

Model::Model(Model &&other) noexcept : _carcass(other._carcass) {}

Model::Model(std::string name) : _carcass(std::make_shared<Carcass>())
{
    this->_name = name;
}

Model &Model::operator=(const Model &other)
{
    if (this != &other)
    {
        _carcass = other._carcass;
    }

    return *this;
}

Model &Model::operator=(Model &&other) noexcept
{
    if (this != &other)
    {
        _carcass = other._carcass;
    }

    return *this;
}

void Model::Transform(const std::shared_ptr<Matrix<double>> mtr)
{
    _carcass->Transform(mtr);
}

void Model::Accept(std::shared_ptr<Visitor> visitor)
{
    visitor->Visit(*this);
}
