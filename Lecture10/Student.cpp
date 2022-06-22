#include <iostream>
#include <string>
using namespace std;

#include "Student.h"



//  Student ����Լ� ������ 

/* �л����� �⺻ �ʱ�ȭ */
void Student::Initialize(){
    string m_name = "";
    int m_hakbun = 0;
    int m_subnum = 0;
    Subject* m_sub = NULL;
    float m_aveGPA = 0.0;
}

/* �л����� ���ڷ� �ʱ�ȭ */
void Student::Initialize(string x, int y, int z, Subject* tsub){
    m_name = x;
    m_hakbun = y;
    m_subnum = z;
    m_sub = tsub;  //���� ���� �ʱ�ȭ 

    CalcAveGPA();  //��� ���� ���
}


/* ���� �Ҵ� ���� */
void Student::Remove(){
    delete [] m_sub;
}


/* �� �������� �Է��Լ��� ���� */
inline void Student::InputValue(int& x){
    cin>>x;
    cin.ignore(); 
}
inline void Student::InputValue(string& str){
    getline(cin, str);
}

/* �л����� �� �������� �Է� */
void Student::InputData(){
    cout << "�л��� �̸�: ";
    InputValue(m_name); 

    cout << "�л��� �й�: ";
    InputValue(m_hakbun);

    cout << "�л��� �����ϴ� ������ ��: ";
    InputValue(m_subnum);
    m_sub = new Subject[m_subnum];

    for(int i = 0; i < m_subnum ;i++ ) (m_sub+i)->InputData();  

    CalcAveGPA();
}


/* �л������� �������� ��� */
void Student::PrintData(){
    cout << "------------------------------------------------------------------" << endl;
    cout.width(10);
    cout << "�̸�: " << m_name << "\t\t�й�: " << m_hakbun << endl;
    m_sub->PrintTitle();
    for(int i = 0; i < m_subnum ;i++ ){
        cout.width(10);
        cout << (m_sub+i)->GetName() << "\t\t" << (m_sub+i)->GetHakjum() << "\t\t" << (m_sub+i)->GetGrade() << "\t " << (m_sub+i)->GetGPA() << endl;
    }
    cout << "------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t�������\t" << m_aveGPA;
}


/* ���� �л��� ��� ���� ��� */
void Student::CalcAveGPA(){  
    float SumGPA=0.0;  //GPA�� ���� ������ �Ǽ��� ������ �����Ѵ�.
    for(int i=0; i<m_subnum; i++){  //�ּҸ� �̵��ϸ� GPA���� �����ش�.
        SumGPA += (m_sub+i)->GetGPA();  
    }

    m_aveGPA = SumGPA/m_subnum;  //��� ������ ��� ���� �����Ѵ�.
} 


/* Student Ŭ���� read�� ������ �Լ� ���� */
string Student::GetName(){
    return m_name;
}
int Student::GetHakbun(){
    return m_hakbun;
}
int Student::GetSubNum(){
    return m_subnum;
}
float Student::GetAveGPA(){
    return m_aveGPA;
}