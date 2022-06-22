//  IOInterface 클래스 선언 및 구현부

#include <iostream>
#include <string>
#include "InputUtil.h"
using namespace std;

/* 헤더 파일 중복 오류를 막기 위한 솔루션 */
#ifndef IOINTERFACE_H  
#define IOINTERFACE_H

class IOInterface{
    public:
        /* 가상 소멸자 함수 */
        virtual ~IOInterface(){
            cout << "IOInterface의 소멸자 호출됨" << "\n\n";
            //아무것도 안함
        }
        
        /* 순수 가상 멤버함수(기본 클래스에서 원형만 제공, 파생 클래스에서 반드시 재정의) */
        virtual void InputData() = 0;
        virtual void PrintData() const = 0;
        virtual void Modify() = 0;
};

#endif
