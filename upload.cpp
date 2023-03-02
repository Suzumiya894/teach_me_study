#include "upload.h"

void Upload_Manage::write_question(Question &_question)
{
    DB->write_question(_question);
    return ;
}

string Upload_Manage::image_tailor(string origin_image, int x1, int y1, int x2, int y2, int which_part)
{
    string file_name;
    int id = DB->get_current_id();
    if( which_part )
        file_name = "Question\\question_answer_" + to_string(id) + ".png";   //保存的图片路径
    else
        file_name = "Question\\question_content_" + to_string(id) + ".png";
    #pragma comment (lib,"Gdiplus.lib")
    Gdiplus::GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR           gdiplusToken;
   
    // Initialize GDI+.
    Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

    {
        const char* c_name = origin_image.c_str();                //string转成char*
        int c_size = MultiByteToWideChar(CP_OEMCP, 0, c_name, strlen(c_name) + 1, NULL, 0);     //确认为wchar_t*开辟多大空间
        wchar_t* image_name = new wchar_t[c_size];
        MultiByteToWideChar(CP_OEMCP, 0, c_name, strlen(c_name) + 1, image_name, c_size);       //char*转换成wchar_t*
        Gdiplus::Image image(image_name);                            //上传的图片路径
        UINT width=image.GetWidth();
        
        UINT height=image.GetHeight();
        Gdiplus::RectF smallrect(0, 0, width, height);
        Gdiplus::Bitmap myBitmap( width, height, PixelFormat32bppARGB );
        Gdiplus::Graphics g(&myBitmap);
        g.DrawImage(&image, smallrect, (UINT)x1, (UINT)y1, (UINT)x2, (UINT)y2, Gdiplus::UnitPixel);

        c_name = file_name.c_str();                //string转成char*
        c_size = MultiByteToWideChar(CP_OEMCP, 0, c_name, strlen(c_name) + 1, NULL, 0);     //确认为wchar_t*开辟多大空间
        wchar_t* w_file_name = new wchar_t[c_size];
        MultiByteToWideChar(CP_OEMCP, 0, c_name, strlen(c_name) + 1, w_file_name, c_size);       //char*转换成wchar_t*

        CLSID pngClsid;
        int result = GetEncoderClsid( L"image/png", &pngClsid );             
        if ( result == -1 )
            throw runtime_error( "GetEncoderClsid" );
        if ( Gdiplus::Ok != myBitmap.Save( w_file_name, &pngClsid, NULL ) )         //保存为w_file_name
        {
            throw runtime_error( "Bitmap::Save" );
        }
        
        //cout << "裁剪成功." << endl;
    }
    Gdiplus::GdiplusShutdown(gdiplusToken);
    return file_name;
}

int GetEncoderClsid(const WCHAR* format, CLSID* pClsid)
{
	UINT  num = 0;          // number of image encoders
	UINT  size = 0;         // size of the image encoder array in bytes
 
	Gdiplus::ImageCodecInfo* pImageCodecInfo = NULL;
 
	Gdiplus::GetImageEncodersSize(&num, &size);
	if (size == 0)
		return -1;  // Failure
 
	pImageCodecInfo = (Gdiplus::ImageCodecInfo*)(malloc(size));
	if (pImageCodecInfo == NULL)
		return -1;  // Failure
 
	Gdiplus::GetImageEncoders(num, size, pImageCodecInfo);
 
	for (UINT j = 0; j < num; ++j)
	{
		if (wcscmp(pImageCodecInfo[j].MimeType, format) == 0)
		{
			*pClsid = pImageCodecInfo[j].Clsid;
			free(pImageCodecInfo);
			return j;  // Success
		}
	}
 
	free(pImageCodecInfo);
	return -1;  // Failure
}