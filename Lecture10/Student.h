#include <string>
#include "Subject.h"

/* ��� ���� �ߺ� ������ ���� ���� �ַ�� */
#ifndef STUDENT_H  
#define STUDENT_H

class Student{  //�л����� Ŭ����
    protected:
        /* ������� */
        string m_name;  //�л� �̸�
        int m_hakbun;  //�й�
        int m_subnum;  //�������� ����
        Subject* m_sub;  //��������� ����
        float m_aveGPA;  //��� ����
    public:
        /* ����Լ� */
        void Initialize();
        void Initialize(string, int, int, Subject*);

        void Remove();
        void InputValue(int &);
        void InputValue(string &);
        void InputData();

        void PrintData();
        void CalcAveGPA();

        friend void ShowData(const Student &);  //friend �Լ�
    public:
        /* ������ �Լ� */
        string GetName();
        int GetHakbun();
        int GetSubNum();
        float GetAveGPA();
};

#endif