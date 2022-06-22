//  IOInterface Ŭ���� ���� �� ������

#include <iostream>
#include <string>
#include "InputUtil.h"
using namespace std;

/* ��� ���� �ߺ� ������ ���� ���� �ַ�� */
#ifndef IOINTERFACE_H  
#define IOINTERFACE_H

class IOInterface{
    protected:
        /* ������� */
        string m_name;
        int m_data;
    public:
        /* ������ �Լ� */
        IOInterface(){
            cout << "IOInterface�� ����Ʈ ������ ȣ���" << "\n\n";
            m_name = "";
            m_data = 0;
        }
        IOInterface(string m_name, int m_data){
            cout << "IOInterface�� �����ִ� ������ ȣ���" << "\n\n";
            this -> m_name = m_name;
            this -> m_data = m_data;
        }
        
        /* �Ҹ��� �Լ� */
        ~IOInterface(){
            cout << "IOInterface�� �Ҹ��� ȣ���" << "\n\n";
            //�ƹ��͵� ����
        }
        
        /* �Ϲ� ����Լ� */
        void InputData(){
            cout << "�̸� �Է�: ";
            InputUtil::InputValue(m_name);
            cout << "������ �Է�: ";
            InputUtil::InputValue(m_data);
        }
        void PrintData() const{
            cout << m_name << m_data << endl;
        }
        void Modify(){
            cout << "�̸� ����: ";
            InputUtil::InputValue(m_name);
            cout << "������ ����: ";
            InputUtil::InputValue(m_data);
            cout << "����Ǿ����ϴ�." << endl;
        }

        /* ������ �Լ� */
        string GetName() const{
            return m_name;
        }
        int GetData() const{
            return m_data;
        }
};

#endif
