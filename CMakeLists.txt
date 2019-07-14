cmake_minimum_required(VERSION 3.12)
project(th8)

set(CMAKE_CXX_STANDARD 14)



#首先定义两个变量INC_DIR和LINK_DIR，用来表示头文件路径和库的路径：
set(INC_DIR /usr/local/include)
set(LINK_DIR /usr/local/lib64)
#然后依次设置头文件目录、库目录、要链接的库：
include_directories(${INC_DIR})
link_directories(${LINK_DIR})
link_libraries(libssl.so libcrypto.so)



add_executable(th8
        BaseASN1.cpp
        BaseASN1.h
        ClientOperation.cpp
        ClientOperation.h
        Codec.cpp
        Codec.h
        FactoryCodec.cpp
        FactoryCodec.h
        ItcastLog.cpp
        ItcastLog.h
        main.cpp
        RequestCodec.cpp
        RequestCodec.h
        RequestFactory.cpp
        RequestFactory.h
        RespondCodec.cpp
        RespondCodec.h
        RespondFactory.cpp
        RespondFactory.h
        SecKeyShm.cpp
        SecKeyShm.h
        SequenceASN1.cpp
        SequenceASN1.h
        ServerOperation.cpp
        ServerOperation.h
        ShareMemory.cpp
        ShareMemory.h
        TcpServer.cpp
        TcpServer.h
        TcpSocket.cpp
        TcpSocket.h)

#使用如下语句完成库的链接操作：
target_link_libraries(th8 libssl.so libcrypto.so)