#pragma once

class Barrier
{
public:
    Position getPostion();
    bool canCreate();

private:
    Position m_postion;
};