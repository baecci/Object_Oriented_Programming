//  Subject Ŭ���� ����Լ� ������

#include <iostream>
#include <string>
using namespace std;

#include "InputUtil.h"
#include "Subject.h"
#include "Student.h"


/* ����Ʈ �����ڸ� ���� Subject Ŭ���� ��ü�� �ʱ�ȭ */
Subject::Subject(){  //�⺻ Ŭ���� ������ ����� ȣ��
    cout << "Subject�� ����Ʈ �����ڰ� ȣ���" << "\n\n";
    
    m_name = "";
    m_hakjum = 0;
    m_grade = "";
    m_GPA = 0.0;
}

/* �����ִ� �����ڸ� ���� Subject Ŭ���� ��ü�� �ʱ�ȭ */
Subject::Subject(string name, int hakjum, string grade){
    cout << "Subject�� �����ִ� �����ڰ� ȣ���" << "\n\n";

    this -> m_name = name;
    this -> m_hakjum = hakjum;
    this -> m_grade = grade;

    CalcGPA();
}

/* ���� �����ڸ� ���� Subject Ŭ���� ��ü�� �ʱ�ȭ */
Subject::Subject(const Subject& sub){
    cout << "Subject�� ���� �����ڰ� ȣ���" << "\n\n"; 
 
    this -> m_name = sub.m_name;  
    this -> m_hakjum = sub.m_hakjum; 
    this -> m_grade = sub.m_grade;  

    CalcGPA();
}

/* �ƹ��͵� ���ϴ� �Ҹ��� */
Subject::~Subject(){
    cout << "Subject�� �Ҹ��ڰ� ȣ���" << "\n\n"; 
    //�ƹ��ϵ� ���� ����
}


/* ���������� �Է��Ѵ�. */
void Subject::InputData(){
    cout << "������ �̸�: ";
    InputUtil::InputValue(m_name);
    cout << "���� ������: ";
    InputUtil::InputValue(m_hakjum);
    cout << "���� ���: ";
    InputUtil::InputValue(m_grade);
    cout << endl;
    CalcGPA();
}


/* ���� Ÿ��Ʋ ��� */
void Subject::PrintTitle(){
    cout << "------------------------------------------------------------------" << endl;
    cout.width(10);
    cout << "�����"<<"\t����������"<<"\t ������"<<"\t ��������" << endl;
    cout << "------------------------------------------------------------------" << endl;
}

/* �������� ��� */
void Subject::PrintData() const{
    cout.width(10);
    cout << m_name << "\t\t" << m_hakjum << "\t\t" << m_grade << "\t\t" << m_GPA << endl;
}


/* �������� ��� */
void Subject::CalcGPA(){
    if(m_grade == "A+"){
        m_GPA = 4.5*(m_hakjum);
    }
    if(m_grade == "A0" || m_grade == "A"){
        m_GPA = 4.0*(m_hakjum);
    }
    if(m_grade == "B+"){
        m_GPA=3.5*(m_hakjum);
    }
    if(m_grade == "B0" || m_grade == "B"){
        m_GPA = 3.0*(m_hakjum);
    }
    if(m_grade == "C+"){
        m_GPA = 2.5*(m_hakjum);
    }
    if(m_grade == "C0" || m_grade == "C"){
        m_GPA = 2.0*(m_hakjum);
    }
    if(m_grade == "D+"){
        m_GPA = 1.5*(m_hakjum);
    }
    if(m_grade == "D0" || m_grade == "D"){
        m_GPA = 1.0*(m_hakjum);
    }
    if(m_grade == "F"){
        m_GPA = 0.0*(m_hakjum);
    }
}


/* ��������(�������, ����, ���) ���� */
void Subject::Modify(){
    cout << "\n��������� ����: ";
    InputUtil::InputValue(m_name);
    cout << "�������� ����: ";
    InputUtil::InputValue(m_hakjum);
    cout << "�������� ����: ";
    InputUtil::InputValue(m_grade);

    CalcGPA();  //������ ������ ���� ���� ����

    cout << "\n����Ǿ����ϴ�." << endl;
}


/* Subject Ŭ���� read�� ������ �Լ� ���� */
string Subject::GetName() const{
    return m_name;
}
int Subject::GetHakjum() const{
    return m_hakjum;
}
string Subject::GetGrade() const{
    return m_grade;
}
float Subject::GetGPA() const{
    return m_GPA;
}