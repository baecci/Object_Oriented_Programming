//  IOInterface Ŭ���� ���� �� ������

#include <iostream>
#include <string>
#include "InputUtil.h"
using namespace std;

/* ��� ���� �ߺ� ������ ���� ���� �ַ�� */
#ifndef IOINTERFACE_H  
#define IOINTERFACE_H

class IOInterface{
    public:
        /* ���� �Ҹ��� �Լ� */
        virtual ~IOInterface(){
            cout << "IOInterface�� �Ҹ��� ȣ���" << "\n\n";
            //�ƹ��͵� ����
        }
        
        /* ���� ���� ����Լ�(�⺻ Ŭ�������� ������ ����, �Ļ� Ŭ�������� �ݵ�� ������) */
        virtual void InputData() = 0;
        virtual void PrintData() const = 0;
        virtual void Modify() = 0;
};

#endif
