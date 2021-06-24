//
// Created by danie on 20.07.2020.
//

#ifndef HACKATHON_COORDINATE_H
#define HACKATHON_COORDINATE_H

#include <ostream>

class Coordinate
{
public:
    Coordinate(int x, int y);

    [[nodiscard]] int x() const;
    [[nodiscard]] int y() const;

    [[nodiscard]] Coordinate getLeftCoordinate() const;
    [[nodiscard]] Coordinate getRightCoordinate() const;
    [[nodiscard]] Coordinate getAboveCoordinate() const;
    [[nodiscard]] Coordinate getBelowCoordinate() const;
    virtual bool operator==(const Coordinate &other) const;

private:
    int m_x;
    int m_y;
};

std::ostream &operator<<(std::ostream &out, Coordinate const &coord);

#endif // HACKATHON_COORDINATE_H
