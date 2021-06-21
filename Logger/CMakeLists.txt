add_library(LoggerLib
        STATIC
        Logger.h
        LogPolicyInterface.h
        FileLogPolicy.cpp
        FileLogPolicy.h
        CoutLogPolicy.cpp
        CoutLogPolicy.h
        LogLevel.cpp
        LogLevel.h
        Log.h)

set_project_warnings(LoggerLib)