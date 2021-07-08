create database if not exists HY_vod_system;
use HY_vod_system;
create table if not exists tb_video(
    id int primary key auto_increment,
    name varchar(32),
    vdesc text,
    video_url varchar(255),
    image_url varchar(255),
    ctime datetime
);

insert tb_video values(null,"许巍-故乡","许巍的经典现场","/video/xuwei.mp4","image/xuwei.jpg",now());
