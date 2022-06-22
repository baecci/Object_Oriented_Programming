#include <iostream>
#include <string>
using namespace std;

#include "InputUtil.h" 
#include "Student.h"
#include "Subject.h" 

void InputUtil::InputValue(int& x){
    cin >> x;
    while(cin.fail() != true){
            cout << "잘못된 입력입니다. 다시 입력해주세요: ";
            cin >> x;
        }
        cin.ignore(); 
}

void InputUtil::InputValue(string& str){
    getline(cin, str); 
    while(cin.fail() != true){
        cout << "잘못된 입력입니다. 다시 입력해주세요: ";
        cin >> str;
    }
}

void InputUtil::InputValue(char* a){
    cin >> a;
    while(cin.fail() != true){
        cout << "잘못된 입력입니다. 다시 입력해주세요: ";
        cin >> a;
    }
}

void InputUtil::InputValue(float& y){
    cin >> y;
    while(cin.fail() != true){
        cout << "잘못된 입력입니다. 다시 입력해주세요: ";
        cin >> y;
    }
    cin.ignore();
} 

void InputUtil::InputValue(double& z){
    cin >> z;
    while(cin.fail() != true){
        cout << "잘못된 입력입니다. 다시 입력해주세요: ";
        cin >> z;
    }
    cin.ignore();
}