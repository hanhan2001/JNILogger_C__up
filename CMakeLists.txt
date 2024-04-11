cmake_minimum_required(VERSION 3.27)
project(JNILogger_C__up)

set(CMAKE_CXX_STANDARD 14)

add_library(JNILogger_C__up SHARED headers/me_xiaoying_logger_JNILogger.h me_xiaoying_logger_JNILogger.cpp Message.cpp headers/Message.h headers/jni.h headers/jni_md.h)