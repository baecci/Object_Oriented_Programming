//  Student Ŭ���� �����

#include <string>
#include "Subject.h"
#include "IOInterface.h"

/* ��� ���� �ߺ� ������ ���� ���� �ַ�� */
#ifndef STUDENT_H  
#define STUDENT_H

class Student : public IOInterface{  //�л����� Ŭ����
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
        void InputData();  //IOInterface Ŭ�������� ��ӹ��� ����Լ� ������

        static void PrintTitle();  
        void PrintData() const;  //IOInterface Ŭ�������� ��ӹ��� ����Լ� ������
        void CalcAveGPA();
        friend void ShowData(const Student &);  

        Subject* SubSearch(string subname) const;
        void Modify(); 

        /* ������ �Լ� */
        string GetName() const;
        int GetHakbun() const;
        int GetSubNum() const;
        float GetAveGPA() const;
};

#endif