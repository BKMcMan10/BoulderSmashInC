#ifndef STRINGHELPER_H
#define STRINGHELPER_H

/// @brief Concatinates 2 strings (const char*)
/// @param str1 
/// @param str2 
/// @return const char*
const char* StringHelper_CombineString(const char* str1, const char* str2)
{
    return str1 + *str2;
}

#endif