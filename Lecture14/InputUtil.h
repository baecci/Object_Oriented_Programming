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
        inline static void InputValue(int& i){
            while(true){
                cin >> i;
                if(cin.fail()){  // cin.fail() �Լ��� �������� ���� �ԷµǾ����� Ȯ��
                    cout << "�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���: ";
                    cin.clear();  // cin�� �����÷��� �ʱ�ȭ
                    cin.ignore(100, '\n');  // �Է¹��� ����
                }
                else break;
            }
            cin.ignore(); 
        }
        //���� ����
        
        inline static void InputValue(string& str){ 
            while(true){
                getline(cin, str);
                if(cin.fail()){
                    cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���: ";
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
                    cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���: ";
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
                    cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���: ";
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
                    cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���: ";
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