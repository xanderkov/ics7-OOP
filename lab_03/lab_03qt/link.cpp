#include "link.h"

Link::Link()
{
    this->begin = 0;
    this->end = 0;
}

Link::Link(const size_t begin, const size_t end)
{
    this->begin = begin;
    this->end = end;
}

Link::Link(const Link &other)
{
    this->begin = other.GetBegin();
    this->end = other.GetEnd();
}

Link::~Link() {}

Link &Link::operator=(const Link &other)
{
    this->begin = other.GetBegin();
    this->end = other.GetEnd();

    return *this;
}

size_t Link::GetBegin() const
{
    return begin;
}

size_t Link::GetEnd() const
{
    return end;
}

void Link::SetBegin(size_t begin)
{
    this->begin = begin;
}

void Link::SetEnd(size_t end)
{
    this->end = end;
}
