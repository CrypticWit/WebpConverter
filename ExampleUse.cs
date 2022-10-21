using System.Drawing;
using System.Runtime.InteropServices;

internal class Program
{

    [DllImport("WebpConverter")]
    static extern IntPtr ConvertFromWebp(Byte[] imgData, int imgDataSize, ref int width, ref int height, ref int colourSpace, ref int outputSize);
    

    static public byte[] GetRawImageDataFromWebp(byte[] data, ref int width, ref int height, ref int colourSpace)
    {
        int outputSize = 9;
        IntPtr result = ConvertFromWebp(data, data.Length, ref width, ref height, ref colourSpace, ref outputSize);

        byte[] rawImg = new byte[outputSize];
        Marshal.Copy(result, rawImg, 0, outputSize);

        return rawImg;
    }

    private static void Main(string[] args)
    {
        int width = 0;
        int height = 0;
        int colourSpace = 0;
        byte[] rawImg =  GetRawImageDataFromWebp(File.ReadAllBytes("test.webp"), ref width, ref height, ref colourSpace);


        int stride = colourSpace == 1 ? 4 : 3;

        Bitmap bmp = new Bitmap(width, height);
        for (int y = 0; y < height; ++y)
        {
            for (int x = 0; x < width; ++x)
            {
                int offset = y * width * stride + x * stride;
                int r = rawImg[offset + 0];
                int g = rawImg[offset + 1];
                int b = rawImg[offset + 2];
                bmp.SetPixel(x, y, Color.FromArgb(255, r, g, b));
            }
        }
        bmp.Save("test.png");
    }
}