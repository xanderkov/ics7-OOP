#include <iostream>
#include "wireframe_model_details.hpp"

WireframeModelDetails::WireframeModelDetails(std::vector<Point> &points, std::vector<Edge> &edges)
        : center{}, points(points), edges(edges) {}

WireframeModelDetails::WireframeModelDetails(Point &center, std::vector<Point> &points, std::vector<Edge> &edges) : center(center),
                                                                                                  points(points),
                                                                                                  edges(edges) {}

void WireframeModelDetails::addPoint(const Point &point) {
    this->points.push_back(point);
}

void WireframeModelDetails::addEdge(const Edge &edge) {
    this->edges.push_back(edge);
}

const Point &WireframeModelDetails::getCenter() const {
    return this->center;
}

const std::vector<Point> &WireframeModelDetails::getPoints() const {
    return this->points;
}

const std::vector<Edge> &WireframeModelDetails::getEdges() const {
    return this->edges;
}

void WireframeModelDetails::transform(const Point &move_params, const Point &scale_params, const Point &rotate_params) {
    this->move(-this->center);

    for (auto &point: points)
    {
        point.rotate(rotate_params.getX(), rotate_params.getY(), rotate_params.getZ());
        point.scale(scale_params.getX(), scale_params.getY(), scale_params.getZ());
    }

    this->center.move(move_params.getX(), move_params.getY(), move_params.getZ());
    this->move(this->center);
}

void WireframeModelDetails::setCenter(const Point &point) {
    this->center = point;
}

void WireframeModelDetails::move(const Point &move_params) {
    for (auto &point: points)
        point.move(move_params.getX(), move_params.getY(), move_params.getZ());
}

void WireframeModelDetails::scale(const Point &scale_params) {
    for (auto &point: points)
        point.scale(scale_params.getX(), scale_params.getY(), scale_params.getZ());
}

void WireframeModelDetails::rotate(const Point &rotate_params) {
    for (auto &point: points)
        point.rotate(rotate_params.getX(), rotate_params.getY(), rotate_params.getZ());
}
