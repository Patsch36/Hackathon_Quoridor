//
// Created by danie on 03.07.2020.
//

#include "CoutLogPolicy.h"
#include <iostream>


void CoutLogPolicy::open_ostream() const
{
    // nothing to do here
}

void CoutLogPolicy::close_ostream() const
{
    // nothing to do here
}

void CoutLogPolicy::write(std::string const &msg) const
{
    std::cout << msg;
}
