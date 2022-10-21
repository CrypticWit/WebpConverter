#include "Converter.h"

#include "libwebp/src/webp/mux_types.h"
#include "libwebp/src/webp/decode.h"

DLLExport uint8_t* ConvertFromWebp(uint8_t* imgData,int imgDataSize, int& width, int& height, int& colourSpace, int& outputSize)
{
	WebPData webp_data;
	WebPDataInit(&webp_data);
	webp_data.bytes = imgData;
	webp_data.size = imgDataSize;

	WebPDecoderConfig config;
	if (WebPInitDecoderConfig(&config) != 1)
	{
		return NULL;
	}

	if (WebPDecode(webp_data.bytes, webp_data.size, &config) != VP8_STATUS_OK)
	{
		return NULL;
	}

	width = config.input.width;
	height = config.input.height;
	outputSize = config.output.u.RGBA.size;
	colourSpace = config.output.colorspace;
	
	return config.output.u.RGBA.rgba;
}
