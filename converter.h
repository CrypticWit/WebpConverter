#pragma once
#include <cstdint>

#if defined(_WIN32)
#define DLLExport __declspec (dllexport)
#else
#define DLLExport
#endif

extern "C" {
	DLLExport uint8_t* ConvertFromWebp(uint8_t* imgData, int imgDataSize, int& width, int& height, int& colourSpace, int& outputSize);
}
