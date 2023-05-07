#ifndef FILEHELPER_H
#define FILEHELPER_H

#include <stdio.h>
#include <stdlib.h>
#include <fileapi.h>

/// @brief Loads in a file from a certain path
/// @param path 
/// @return const char*
const char* FileHelper_LoadFileFromPath(char* path)
{
    FILE* file = fopen(path, "rb");
    char* ch;

    ch = fgets(path, FILENAME_MAX, file);

    if(ch)
    {
        while (*ch != '\0' && *ch != '\n')
        {
            ch++;
            if(*ch == '\n')
            {
                *ch = '\0';
            }
        }
    }

    return ch;
}

#endif