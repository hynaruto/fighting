#include "db.hpp"
#include"httplib.h"

#define WWWROOT "./wwwroot"
using namespace httplib;

vod_system::TableVod *tb_video;
void VideoDelete(const Request &req,Response &rsp)
{
    //req.path=/video/1
    //1.获取视频id
    int video_id = std::stoi(req.matches[1]);
    //2.从数据库中获取到对应的视频信息
    Json::Value video;
    Json::FastWriter writer;
    Json::Value json_rsp;
    bool ret = tb_video->GetOne(video_id,&video);
    if (ret == false)
    {
        std::cout<<"mysql get video info failed!\n";
        rsp.status = 500;
        json_rsp["result"] = false;
        json_rsp["reason"] = "mysql get video info failed!";
        rsp.body = writer.write(json_rsp);
        rsp.set_header("Content-Type","application/json");
        return;
    }
    //3.删除视频文件，封面图片文件
    std::string vpath = WWWROOT + video["video_url"].asString();
    std::string ipath = WWWROOT + video["image_url"].asString();
    unlink(vpath.c_str());
    unlink(ipath.c_str());
    //4.删除数据库中的数据
    bool res = tb_video->Delect(video_id);
    if (res == false)
    {
        rsp.status = 500;
        std::cout<<"mysql delete video failed!\n";
        return;
    }
    //rsp.status = 200 可以不给因为默认就是200-OK
    rsp.status = 200;
}
void VideoUpdate(const Request &req,Response &rsp)
{
    int video_id = std::stoi(req.matches[1]);
    Json::Value video;
    Json::Reader reader;
    bool ret = reader.parse(req.body,video);
    if (ret == false)
    {
        std::cout<<"update video::parse video json failed!\n";
        rsp.status = 400;//表示请求格式有问题
        return;
    }
    ret = tb_video->Update(video_id,video);
    if (ret == false)
    {
        std::cout<<"update video::mysql update failed!\n";
        rsp.status = 500;//表示服务器内部有问题
        return;
    }
    return;
}
void VideoGetALL(const Request &req,Response &rsp)
{
    Json::Value videos;
    Json::FastWriter writer;
    bool ret = tb_video->GetAll(&videos);
    if (ret == false)
    {
        std::cout<<"getadd video:mysql operation failed!\n";
        rsp.status = 500;
        return;
    }
    rsp.body = writer.write(videos);
    rsp.set_header("Content-Type","application/json");
    rsp.status = 200;
}
void VideoGetOne(const Request &req,Response &rsp)
{
    int video_id = std::stoi(req.matches[1]);
    Json::Value video;
    Json::FastWriter writer;
    bool ret = tb_video->GetOne(video_id,&video);
    if (ret == false)
    {
        std::cout<<"getnoe video:mysql operation failed!\n";
        rsp.status = 500;
        return;
    }
    rsp.body = writer.write(video);
    rsp.set_header("Content-Type","application/json");
}
#define VIDEO_PATH "/video/"
#define IMAGE_PATH "/image/"
void VideoUpload(const Request &req,Response &rsp)
{
    auto ret = req.has_file("video_name");
    if (ret == false)
    {
        std::cout<<"have no video name!\n";
        rsp.status = 400;
        return;
    }
    const auto& file = req.get_file_value("video_name");

    ret = req.has_file("video_desc");
    if (ret == false)
    {
        std::cout<<"have no video desc\n";
        rsp.status = 400;
        return;
    }
    const auto& file1 = req.get_file_value("video_desc");

    ret = req.has_file("video_file");
    if (ret == false)
    {
        std::cout<<"have no video file\n";
        rsp.status = 400;
        return;
    }
    const auto& file2 = req.get_file_value("video_file");

    ret = req.has_file("image_file");
    if (ret == false)
    {
        std::cout<<"have no image_file!\n";
        rsp.status = 400;
        return;
    }
    const auto& file3 = req.get_file_value("image_file");
    const std::string &vname = file.content;//许巍
    const std::string &vdesc = file1.content;//无尽光芒
    const std::string &vfile = file2.filename;//**.mp4
    const std::string &vcont = file2.content;//文件数据
    const std::string &ifile = file3.filename;//**.jpg
    const std::string &icont = file3.content;//封面图像文件数据

    std::string vurl = VIDEO_PATH + file2.filename;
    std::string iurl = IMAGE_PATH + file3.filename;
    std::string wwwroot = WWWROOT;
    vod_system::Util::WriteFile(wwwroot + vurl,file2.content);
    vod_system::Util::WriteFile(wwwroot + iurl,file3.content);

    Json::Value video;
    video["name"] = vname;
    video["vdesc"] = vdesc;
    video["video_url"] = vurl;
    video["image_url"] = iurl;
    ret = tb_video->Instert(video);
    if (ret == false)
    {
        rsp.status = 500;
        std::cout<<"insert video:mysql operation failed!\n";
        return;
    }
}
int main()
{
    tb_video = new vod_system::TableVod;
    Server srv;
    //正则表达式,\d-匹配一个数字字符;+匹配一次或者多次
    //R"(string)"取出括号中字符串中每个字符的特殊含义
    srv.set_base_dir("./wwwroot");
    srv.Delete(R"(/video/(\d+))",VideoDelete);
    srv.Put(R"(/video/(\d+))",VideoUpdate);
    srv.Get(R"(/video)",VideoGetALL);
    srv.Get(R"(/video/(\d+))",VideoGetOne);
    srv.Post(R"(/video)",VideoUpload);
    srv.listen("0.0.0.0",9000);
    return 0;
}
/*
void test()
{
    vod_system::TableVod tb_vod;
    Json::Value val;
    //val["name"] = "赵雷-成都";
    //val["vdesc"] = "非常好听的一首歌";
    //val["video_url"] = "/video/zhaolei.mp4";
    //val["image_url"] = "/video/zhaolei.jpg";

    //tb_vod.Instert(val);
    //tb_vod.Update(3,val);
    //tb_vod.Delect(2);
    tb_vod.GetOne(3,&val);
    Json::StyledWriter writer;
    std::cout<<writer.write(val)<<std::endl;
    return;
}

int main()
{
    test();
    return 0;
}
*/
