//
// Created by danie on 03.07.2020.
//

#ifndef GAMEFIELDGRAPH_LOG_H
#define GAMEFIELDGRAPH_LOG_H

#include "Logger.h"
#include "FileLogPolicy.h"
#include "CoutLogPolicy.h"

namespace DHBW_LOG
{

    template<LogLevel active_log_level>
    using FileLogger = Logger<FileLogPolicy, active_log_level>;

    template<LogLevel active_log_level = LogLevel::INFO>
    using CoutLogger = Logger<CoutLogPolicy, active_log_level>;

}

#endif //GAMEFIELDGRAPH_LOG_H
