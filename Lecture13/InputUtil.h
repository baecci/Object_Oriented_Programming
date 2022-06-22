//  InputUtil Ŭ���� ���� �� ������

#include <iostream>
#include <string>
using namespace std;

/* ��� ���� �ߺ� ������ ���� ���� �ַ�� */
#ifndef INPUTUTIL_H  
#define INPUTUTIL_H


class InputUtil{
    public:
        /* ����Լ� */
        inline static void InputValue(int& x){
            cin >> x;
            while(cin.fail() == 1){
                cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���: ";
                cin >> x;
            }
            cin.ignore(); 
        }
        inline static void InputValue(string& str){
            getline(cin, str); 
            while(cin.fail() == 1){
                cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���: ";
                cin >> str;
            }
        }
        inline static void InputValue(char* a){
            cin >> a;
            while(cin.fail() == 1){
                cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���: ";
                cin >> a;
            }
        }
        inline static void InputValue(float& y){
            cin >> y;
            while(cin.fail() == 1){
                cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���: ";
                cin >> y;
            }
            cin.ignore();
        }
        inline static void InputValue(double& z){
            cin >> z;
            while(cin.fail() == 1){
                cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���: ";
                cin >> z;
            }
            cin.ignore();
        }
};

#endif