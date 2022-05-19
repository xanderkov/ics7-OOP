#ifndef LINK_H
#define LINK_H

#include <istream>

class Link
{
public:
    Link();
    Link(const size_t begin, const size_t end);
    explicit Link(const Link &other);
    Link &operator=(const Link &other);
    ~Link();

    void SetBegin(size_t begin);
    void SetEnd(size_t end);

    size_t GetBegin() const;
    size_t GetEnd() const;

private:
    size_t begin;
    size_t end;
};

inline std::istream &operator>>(std::istream &in, Link &link)
{
    size_t begin, end;
    in >> begin >> end;
    link.SetBegin(begin);
    link.SetEnd(end);

    return in;
}

#endif // LINK_H
