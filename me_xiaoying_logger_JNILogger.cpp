#include "headers/me_xiaoying_logger_JNILogger.h"

#include <iostream>
#include "map"
#include "headers/Message.h"

JNIEXPORT void JNICALL Java_me_xiaoying_logger_JNILogger_send(JNIEnv* env, jobject, jstring jmessage, jstring jaltCharColor) {
    jboolean isCopy = false;
    std::string message = (env)->GetStringUTFChars(jmessage, &isCopy);
    std::string altCharColor = (env)->GetStringUTFChars(jaltCharColor, &isCopy);

    char color = 'f';
    bool getColor = false;
    char alt = altCharColor[0];
    std::string m;
    std::map<int, Message> knownMessage;
    for (char s : message) {
        // 判断是否使用色彩字符
        if (s == alt) {
            if (!m.empty())
                knownMessage.insert(std::pair<int, Message>(knownMessage.size(), Message(m, color)));
            m = "";
            getColor = true;
            continue;
        }

        // 判断是否重复使用色彩字符
        if (s == alt && getColor) {
            m = m + alt;
            getColor = false;
            if (!m.empty())
                knownMessage.insert(std::pair<int, Message>(knownMessage.size(), Message(m, color)));
            continue;
        }

        // 获取色彩字符
        if (getColor) {
            color = s;
            getColor = false;
            continue;
        }

        m = m + s;
    }

    if (!m.empty())
        knownMessage.insert(std::pair<int, Message>(knownMessage.size(), Message(m, color)));

    for (int i = 0; i < knownMessage.size(); ++i)
        knownMessage.find(i)->second.send(false);
    std::cout << "\n";
}