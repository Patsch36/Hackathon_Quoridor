#pragma once
#include "../Graph/Graph.h"
#include "Position.h"
#include "AbstractPlayer.h"


#include <array>
#include <list>
#include <memory>
#include <string>
#include <iostream>


class GameField
{
public:
    GameField();
    GameField(std::weak_ptr<AbstractPlayer> player1, std::weak_ptr<AbstractPlayer> player2);
    virtual ~GameField();
    [[nodiscard]] std::string toString() const;

    friend std::ostream &operator<<(std::ostream &os, const GameField &gf);

    [[nodiscard]] const Position &getPosition(Coordinate const &coordinates) const;


    
private:
    std::weak_ptr<AbstractPlayer> m_player1;
    std::weak_ptr<AbstractPlayer> m_player2;
    Position &getPosition(Coordinate const &coordinates);
    // Returns corresponding EdgeId and Graph::INVALID_EDGE_ID if edge is already removed
    [[nodiscard]] Combinatorics::EdgeId getEdgeIdBetweenCoordinates(Coordinate const &a, Coordinate const &b) const;
    [[nodiscard]] Combinatorics::Edge const &getEdgeBetweenCoordinates(Coordinate const &a, Coordinate const &b) const;
    Combinatorics::Edge &getEdgeBetweenCoordinates(Coordinate const &a, Coordinate const &b);
    [[nodiscard]] bool edgeBetweenCoordinatesExists(Coordinate const &a, Coordinate const &b) const;

    //////////////////
    /// Most likely you do not have to touch this
    Combinatorics::Graph m_graph;
    static constexpr int s_width{9};
    static constexpr int s_height{9};
    void printDelimiter(std::string &result, Coordinate const &coordinate) const;
    void printContent(std::string &result, Coordinate const &coordinate) const;
    std::array<std::array<std::unique_ptr<Position>, s_height>, s_width> m_field;
    [[nodiscard]] const Position &at(int x, int y) const;
};
