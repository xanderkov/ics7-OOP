#include "carcass.h"

Carcass::Carcass(const Vector<Point<double>> &points, const Vector<Link> &links)
{
    points_ = points;
    links_ = links;
}

Vector<Link> &Carcass::GetLinks()
{
    return links_;
}

Point<double> &Carcass::GetCentre()
{
    return centre_;
}

Vector<Point<double>> &Carcass::GetPoints()
{
    return points_;
}

Vector<Pair<Point<double>, Point<double>>> Carcass::GetEdges()
{
    Vector<Pair<Point<double>, Point<double>>> edges;

    for (size_t i = 0; i < links_.getLen(); i++)
    {
        Pair<Point<double>, Point<double>> tmp(points_[links_[i].GetBegin()], points_[links_[i].GetEnd()]);
        edges.push_back(tmp);
    }

    return edges;
}

void Carcass::Transform(const std::shared_ptr<Matrix<double>> mtr)
{
    if (mtr->IsMove())
    {
        centre_.Transform(mtr);
    }
    else
    {
        for (size_t i = 0; i < points_.getLen(); i++)
        {
            points_[i].Transform(mtr);
        }
    }
}
