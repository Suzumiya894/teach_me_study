#ifndef UPLOAD_H
#define UPLOAD_H
#include "basic_class.h"
#include <windows.h>
#include <objidl.h>
#include <gdiplus.h>
using namespace std;
#include <stdexcept>
#include <fstream>
#include "user_manager.h"


int GetEncoderClsid(const WCHAR* format, CLSID* pClsid);



class Upload_Manage                         //上传管理类
{
    private:
        Database *DB;
    public:
        void write_question(Question &_question);            //向数据库写入题目,包装函数
        //图片裁剪，传入参数为：原始图片保存路径，左上角坐标，右下角坐标，是题干部分还是答案部分，题干是0答案是1
        string image_tailor(string origin_image, int x1, int y1, int x2, int y2, int which_part);   
        Upload_Manage(Database &database):DB(&database){}  

};

#endif