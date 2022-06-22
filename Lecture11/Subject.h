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
        /* ������ */
        Subject();  
        Subject(string name, int hakjum, string grade);  
        Subject(const Subject& sub);  
        
        /* �Ҹ��� */
        ~Subject();
        
        /* ����Լ� */
        void InputValue(int &);
        void InputValue(string &);
        void InputData();

        void PrintTitle();
        void PrintData();
        void CalcGPA();

        void Modify();  //���� �߰��� �Լ�  
        
        /* ������ �Լ� */
        string GetName();
        int GetHakjum();
        string GetGrade();
        float GetGPA();
};

#endif