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
        inline static void InputValue(int& i){
            while(true){
                cin >> i;
                if(cin.fail()){  // cin.fail() 함수로 정상적인 값이 입력되었는지 확인
                    cout << "잘못된 입력입니다. 다시 입력하세요: ";
                    cin.clear();  // cin의 상태플래그 초기화
                    cin.ignore(100, '\n');  // 입력버퍼 비우기
                }
                else break;
            }
            cin.ignore(); 
        }
        //이하 동문
        
        inline static void InputValue(string& str){ 
            while(true){
                getline(cin, str);
                if(cin.fail()){
                    cout << "잘못된 입력입니다. 다시 입력해주세요: ";
                    cin.clear();
                    cin.ignore(100, '\n');
                }
                else break;
            }
        }

        inline static void InputValue(char* c){
            while(true){
                cin >> c;
                if(cin.fail()){
                    cout << "잘못된 입력입니다. 다시 입력해주세요: ";
                    cin.clear();
                    cin.ignore(100, '\n');

                    cin >> c;
                }
                else break;
            }
            cin.ignore();
        }

        inline static void InputValue(float& f){
            while(true){
                cin >> f;
                if(cin.fail()){
                    cout << "잘못된 입력입니다. 다시 입력해주세요: ";
                    cin.clear();
                    cin.ignore(100, '\n');

                    cin >> f;
                }
                else break;
            }
            cin.ignore();
        }

        inline static void InputValue(double& d){
            while(true){
                cin >> d;
                if(cin.fail()){
                    cout << "잘못된 입력입니다. 다시 입력해주세요: ";
                    cin.clear();
                    cin.ignore(100, '\n');

                    cin >> d;
                }
                else break;
            }
            cin.ignore();
        }
};

#endif