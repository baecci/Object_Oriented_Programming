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
        void InputData();

        static void PrintTitle();
        void PrintData() const;
        void CalcGPA();

        void Modify();    
        
        /* ������ �Լ� */
        string GetName() const;
        int GetHakjum() const;
        string GetGrade() const;
        float GetGPA() const;
};

#endif