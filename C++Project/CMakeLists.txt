cmake_minimum_required(VERSION 3.15)
project(C__Project C)

set(CMAKE_C_STANDARD 11)

add_executable(C__Project main.c minftp.c sysutil.h sysutil.c session.h session.c ftp_proto.h ftp_proto.c par_parent.h par_parent.c str.h str.c ftp_code.h Common.h privsock.h privsock.c parseconf.h parseconf.c tunable.h tunable.c hash.h hash.c)