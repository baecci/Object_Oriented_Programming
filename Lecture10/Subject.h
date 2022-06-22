#include <string>

/* ��� ���� �ߺ� ������ ���� ���� �ַ�� */
#ifndef SUBJECT_H  
#define SUBJECT_H

class Subject{  //�������� Ŭ����
    protected:
        /* ������� */
        string m_name;  //���� �̸�
        int m_hakjum;  //������
        string m_grade;  //������
        float m_GPA;  //����
    public:
        /* ����Լ� */
        void Initialize();
        void Initialize(string, int, string);
        void InputValue(int &);
        void InputValue(string &);
        void InputData();

        void PrintTitle();
        void PrintData();
        void CalcGPA();  
    public:
        /* ������ �Լ� */
        string GetName();
        int GetHakjum();
        string GetGrade();
        float GetGPA();
};

#endif