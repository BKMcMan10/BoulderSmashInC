#ifndef MEMORYHELPER_H
#define MEMORYHELPER_H

#include <stdio.h>
#include <stdlib.h>
#include <mem.h>

typedef struct _Freed
{
    double time;
};

typedef struct _Freed _Freed;

typedef void Memory;

_Freed* memoryToFree[1000];

/// @brief Allocates memory
/// @param _Size 
/// @return void
void* __cdecl MemoryHelper_AllocateMemory(size_t _Size) 
{
    return malloc(_Size);
}

void MemoryHelper_Free(Memory* memory)
{
    free(memory);
}

void MemoryHelper_Update()
{
    int m = 0;
    while (m < 1000 && memoryToFree[m] != NULL)
    {
        memoryToFree[m]->time -= 0.01f;
        m++;
    }
    
}

void MemoryHelper_FreeTimed(Memory* memory, double time)
{
    int m = 0;
    while (m < 1000)
    {
        if(memoryToFree[m] == NULL)
        {
            memoryToFree[m] = (_Freed*)MemoryHelper_AllocateMemory(sizeof(memoryToFree[m]));
            memoryToFree[m]->time = time;
            break;
        }
        m++;
    }
}

#endif