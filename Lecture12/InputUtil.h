#include <iostream>
#include <string>
using namespace std;

#include "Subject.h"
#include "Student.h"

/* 헤더 파일 중복 오류를 막기 위한 솔루션 */
#ifndef InputUtil_H  
#define InputUtil_H


class InputUtil{
    public:
        /* 멤버함수 */
        inline static void InputValue(int& x);
        inline static void InputValue(string& str);
        inline static void InputValue(char* a);
        inline static void InputValue(float& y);
        inline static void InputValue(double& z);
};

#endif