#pragma once
#include "../Graph/Vertex.h"
#include "Coordinate.h"

#include <memory>
#include <string>

class Position : public Coordinate
{
public:
    explicit Position(Coordinate const &coordinate, Combinatorics::Vertex &vertex);
    explicit Position(int x, int y, Combinatorics::Vertex &vertex);
    [[nodiscard]] Combinatorics::Vertex const &getVertex() const;
    [[nodiscard]] Combinatorics::Vertex &getVertex();
    [[nodiscard]] std::string toString() const;
    bool operator==(const Position &other) const;
    bool operator==(const Coordinate &other) const override;
   

private:
    Combinatorics::Vertex &m_vertex;
};
