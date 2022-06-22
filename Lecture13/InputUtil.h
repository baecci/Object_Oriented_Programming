//  InputUtil 클래스 선언 및 구현부

#include <iostream>
#include <string>
using namespace std;

/* 헤더 파일 중복 오류를 막기 위한 솔루션 */
#ifndef INPUTUTIL_H  
#define INPUTUTIL_H


class InputUtil{
    public:
        /* 멤버함수 */
        inline static void InputValue(int& x){
            cin >> x;
            while(cin.fail() == 1){
                cout << "잘못된 입력입니다. 다시 입력해주세요: ";
                cin >> x;
            }
            cin.ignore(); 
        }
        inline static void InputValue(string& str){
            getline(cin, str); 
            while(cin.fail() == 1){
                cout << "잘못된 입력입니다. 다시 입력해주세요: ";
                cin >> str;
            }
        }
        inline static void InputValue(char* a){
            cin >> a;
            while(cin.fail() == 1){
                cout << "잘못된 입력입니다. 다시 입력해주세요: ";
                cin >> a;
            }
        }
        inline static void InputValue(float& y){
            cin >> y;
            while(cin.fail() == 1){
                cout << "잘못된 입력입니다. 다시 입력해주세요: ";
                cin >> y;
            }
            cin.ignore();
        }
        inline static void InputValue(double& z){
            cin >> z;
            while(cin.fail() == 1){
                cout << "잘못된 입력입니다. 다시 입력해주세요: ";
                cin >> z;
            }
            cin.ignore();
        }
};

#endif