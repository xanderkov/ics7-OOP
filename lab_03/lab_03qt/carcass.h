#ifndef CARCASS_H
#define CARCASS_H

#include "matrix.h"
#include "points_pair.h"
#include "vector.h"
#include "link.h"
#include "point.h"

// совокупность точек и связей
class Carcass
{
public:
    Carcass() = default;
    Carcass(const Vector<Point<double>> &points, const Vector<Link> &links);
    ~Carcass() = default;

    Vector<Point<double>> &GetPoints();
    Vector<Link> &GetLinks();
    Vector<Pair<Point<double>, Point<double>>> GetEdges();
    Point<double> &GetCentre();
    void Transform(const std::shared_ptr<Matrix<double>> mtr);

private:
    Vector<Point<double>> points_;
    Vector<Link> links_;
    Point<double> centre_;
};

#endif // CARCASS_H
