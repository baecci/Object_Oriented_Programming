#include <iostream>
#include <string>
using namespace std;

#include "Subject.h"

//  Subject ����Լ� ������

/* Subject Ŭ���� ��ü �⺻ �ʱ�ȭ */
void Subject::Initialize(){
    m_name = "";
    m_hakjum = 0;
    m_grade = "";
    m_GPA = 0.0;
}

/* Subject Ŭ���� ��ü�� ���ڸ� ���� �ʱ�ȭ */
void Subject::Initialize(string x, int y, string z){
    m_name = x;
    m_hakjum = y;
    m_grade = z;
    CalcGPA();
}


/* ������ ���� �����͸� �Է��Ѵ�. */
inline void Subject::InputValue(int& x){
    cin>>x;
    cin.ignore();  //���ۿ� �ִ� '������ ����(\n)'�� ó���Ѵ�.
}  
/* ���ڿ� ���� �����͸� �Է��Ѵ�. */
inline void Subject::InputValue(string& str){
    getline(cin, str); 
}  

/* ���������� �Է��Ѵ�. */
void Subject::InputData(){
    cout<<"������ �̸�: ";
    InputValue(m_name);
    cout<<"\n���� ������: ";
    InputValue(m_hakjum);
    cout<<"\n���� ���: ";
    InputValue(m_grade);
    CalcGPA();
}


/* ���� Ÿ��Ʋ ��� */
void Subject::PrintTitle(){
    cout<<"------------------------------------------------------------------"<<endl;
    cout.width(10);
    cout<<"�����"<<"\t����������"<<"\t ������"<<"\t ��������"<<endl;
    cout<<"------------------------------------------------------------------"<<endl;
}

/* �������� ��� */
void Subject::PrintData(){
    cout.width(10);
    cout<<m_name<<"\t\t"<<m_hakjum<<"\t\t"<<m_grade<<"\t\t"<<m_GPA<<endl;
}


/* �������� ��� */
void Subject::CalcGPA(){
    if(m_grade=="A+"){
        m_GPA=4.5*(m_hakjum);
    }
    if(m_grade=="A0" || m_grade=="A"){
        m_GPA=4.0*(m_hakjum);
    }
    if(m_grade=="B+"){
        m_GPA=3.5*(m_hakjum);
    }
    if(m_grade=="B0" || m_grade=="B"){
        m_GPA=3.0*(m_hakjum);
    }
    if(m_grade=="C+"){
        m_GPA=2.5*(m_hakjum);
    }
    if(m_grade=="C0" || m_grade=="C"){
        m_GPA=2.0*(m_hakjum);
    }
    if(m_grade=="D+"){
        m_GPA=1.5*(m_hakjum);
    }
    if(m_grade=="D0" || m_grade=="D"){
        m_GPA=1.0*(m_hakjum);
    }
    if(m_grade=="F"){
        m_GPA=0.0*(m_hakjum);
    }
}


/* Subject Ŭ���� read�� ������ �Լ� ���� */
string Subject::GetName(){
    return m_name;
}
int Subject::GetHakjum(){
    return m_hakjum;
}
string Subject::GetGrade(){
    return m_grade;
}
float Subject::GetGPA(){
    return m_GPA;
}