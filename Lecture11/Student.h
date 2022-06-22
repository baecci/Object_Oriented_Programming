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
        /* ������ */
        Student();
        Student(string name, int hakbun, int subnum, Subject* sub);
        Student(const Student& std);

        /* �Ҹ��� */
        ~Student();
        
        /* ����Լ� */
        void Remove();
        void InputValue(int &);
        void InputValue(string &);
        void InputData();

        void PrintData();
        void CalcAveGPA();

        friend void ShowData(const Student &);  //friend �Լ�

        void Modify();  //���� �߰��� �Լ�

        /* ������ �Լ� */
        string GetName();
        int GetHakbun();
        int GetSubNum();
        float GetAveGPA();
};

#endif