//  IOInterface 클래스 선언 및 구현부

#include <iostream>
#include <string>
#include "InputUtil.h"
using namespace std;

/* 헤더 파일 중복 오류를 막기 위한 솔루션 */
#ifndef IOINTERFACE_H  
#define IOINTERFACE_H

class IOInterface{
    protected:
        /* 멤버변수 */
        string m_name;
        int m_data;
    public:
        /* 생성자 함수 */
        IOInterface(){
            cout << "IOInterface의 디폴트 생성자 호출됨" << "\n\n";
            m_name = "";
            m_data = 0;
        }
        IOInterface(string m_name, int m_data){
            cout << "IOInterface의 인자있는 생성자 호출됨" << "\n\n";
            this -> m_name = m_name;
            this -> m_data = m_data;
        }
        
        /* 소멸자 함수 */
        ~IOInterface(){
            cout << "IOInterface의 소멸자 호출됨" << "\n\n";
            //아무것도 안함
        }
        
        /* 일반 멤버함수 */
        void InputData(){
            cout << "이름 입력: ";
            InputUtil::InputValue(m_name);
            cout << "데이터 입력: ";
            InputUtil::InputValue(m_data);
        }
        void PrintData() const{
            cout << m_name << m_data << endl;
        }
        void Modify(){
            cout << "이름 수정: ";
            InputUtil::InputValue(m_name);
            cout << "데이터 수정: ";
            InputUtil::InputValue(m_data);
            cout << "변경되었습니다." << endl;
        }

        /* 접근자 함수 */
        string GetName() const{
            return m_name;
        }
        int GetData() const{
            return m_data;
        }
};

#endif
