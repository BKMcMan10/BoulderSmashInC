#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>
#include <time.h>

#define LOGLEVEL_INFO 0
#define LOGLEVEL_WARNING 1
#define LOGLEVEL_ERROR 2

/// @brief Writes to the console
/// @param msg 
/// @param name 
/// @param level 
/// @return void
void Logger_WriteConsole(const char* msg, const char* name, int level)
{

    time_t t = time(NULL);
    struct tm* tm = localtime(&t);

    switch (level)
    {
        case 0:
            printf("[%d:%d:%d] [Thread/INFO] [%s]: %s\n", tm->tm_hour, tm->tm_sec, tm->tm_min, name, msg);
            break;

        case 1:
            printf("[%d:%d:%d] [Thread/WARNING] [%s]: %s\n", tm->tm_hour, tm->tm_sec, tm->tm_min, name, msg);
            break;

        case 2:
            printf("[%d:%d:%d] [Thread/ERROR] [%s]: %s\n", tm->tm_hour, tm->tm_sec, tm->tm_min, name, msg);
            break;

        default:
            break;  
    }
}

#endif