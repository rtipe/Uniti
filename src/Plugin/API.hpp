//
// Created by youba on 25/10/2023.
//

#pragma once

#if defined(_WIN32) || defined(_WIN64)
#define EXPORT_FUNCTION __declspec(dllexport)
#else
#define EXPORT_FUNCTION
#endif

extern "C" {
EXPORT_FUNCTION void *getCreator(void);
EXPORT_FUNCTION void deleteCreator(void *creator);
}
