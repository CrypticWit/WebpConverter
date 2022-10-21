#pragma once
#include <cstdint>


#define DLLExport __declspec (dllexport)

extern "C" {
	DLLExport uint8_t* ConvertFromWebp(uint8_t* imgData, int imgDataSize, int& width, int& height, int& colourSpace, int& outputSize);
}