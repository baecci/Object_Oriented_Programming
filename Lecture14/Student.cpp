//  Student Ŭ���� ����Լ� ������

#include <iostream>
#include <string>
using namespace std;

#include "InputUtil.h"  
#include "Student.h"


/* ����Ʈ �����ڸ� ���� Student Ŭ���� ��ü�� �ʱ�ȭ */
Student::Student(){  //�⺻ Ŭ���� ������ ����� ȣ��
    cout << "Student�� ����Ʈ �����ڰ� ȣ���" << "\n\n"; 
    
    string m_name = "";
    int m_hakbun = 0;
    int m_subnum = 0;
    Subject* m_sub = NULL;
    float m_aveGPA = 0.0;
}

/* �����ִ� �����ڸ� ���� Student Ŭ���� ��ü�� �ʱ�ȭ(���� ����) */
Student::Student(string name, int hakbun, int subnum, Subject* sub){
    cout << "Student�� �����ִ� �����ڰ� ȣ���" << "\n\n";

    /* m_name ���� ���� */
    int len = m_name.size();  
    this -> m_name = new char[len+1]; 
    this -> m_name = name; 

    m_hakbun = hakbun;
    m_subnum = subnum;

    /* m_sub ���� ���� */
    m_sub = new Subject[subnum]; 
    for(int i = 0; i < subnum; i++)
        m_sub[i] = sub[i];

    CalcAveGPA();  
}

/* ���� �����ڸ� ���� Student Ŭ���� ��ü�� �ʱ�ȭ(���� ����) */
Student::Student(const Student& std){
    cout << "Student�� ���� �����ڰ� ȣ���" << "\n\n";  

    /* m_name ���� ���� */
    int len = (std.m_name).size();  
    this -> m_name = new char[len+1]; 
    this -> m_name = std.m_name;  

    this -> m_hakbun = std.m_hakbun; 
    this -> m_subnum = std.m_subnum;

    /* m_sub ���� ���� */ 
    m_sub = new Subject[std.m_subnum]; 
    for(int i = 0; i < std.m_subnum; i++)
        m_sub[i] = std.m_sub[i];

    CalcAveGPA();
}

/* �Ҹ��ڸ� ���� ���� �Ҵ�� �޸� ���� */
Student::~Student(){
    cout << "Student�� �Ҹ��ڰ� ȣ���" << "\n\n";  
    //�ƹ��ϵ� ���� ����
}


/* �л����� �� �������� �Է� */
void Student::InputData(){
    cout << "�л��� �̸�: ";
    InputUtil::InputValue(m_name); 

    cout << "�л��� �й�: ";
    InputUtil::InputValue(m_hakbun);

    cout << "�л��� �����ϴ� ������ ��: ";
    InputUtil::InputValue(m_subnum);
    m_sub = new Subject[m_subnum];

    for(int i = 0; i < m_subnum ;i++ ) (m_sub+i)->InputData();  

    CalcAveGPA();
}


/* �л������� �������� ��� */
void Student::PrintData() const{
    cout << "------------------------------------------------------------------" << endl;
    cout.width(10);
    cout << "�̸�: " << m_name << "\t\t�й�: " << m_hakbun << endl;
    m_sub->PrintTitle();
    for(int i = 0; i < m_subnum ;i++ ){
        cout.width(10);
        cout << (m_sub+i)->GetName() << "\t\t" << (m_sub+i)->GetHakjum() << "\t\t" << (m_sub+i)->GetGrade() << "\t " << (m_sub+i)->GetGPA() << endl;
    }
    cout << "------------------------------------------------------------------" << endl;
    cout << " \t\t\t\t�������\t" << m_aveGPA << "\n\n";
}


/* ���� �л��� ��� ���� ��� */
void Student::CalcAveGPA(){  
    float SumGPA = 0.0;  //GPA�� ���� ������ �Ǽ��� ������ �����Ѵ�.
    for(int i = 0; i < m_subnum; i++){  //�ּҸ� �̵��ϸ� GPA���� �����ش�.
        SumGPA += (m_sub+i)->GetGPA();  
    }

    m_aveGPA = SumGPA/m_subnum;  //��� ������ ��� ���� �����Ѵ�.
} 


/* ���� ã�� */
Subject* Student::SubSearch(string subname) const{
    for(int i = 0; i<m_subnum; i++){
        /* �ش� ������ ã�� ��� ���� �ּҸ� ���� */
        if((m_sub+i)->GetName() == subname) 
            return m_sub+i;
    }
    /* �ش� ������ �߰����� ���ϸ� NULL���� */
    return NULL;
}


/* ���� ���� */
void Student::Modify(){
    string modifyinfo;
    cout << "\n\n�Է�(�л�����/��������/���) : ";
    InputUtil::InputValue(modifyinfo);
    if(modifyinfo == "�л�����"){
        /* �л����� ���� */
        cout << "\n�л��̸��� ����: ";
        InputUtil::InputValue(m_name);
        cout << "�й��� ����: ";
        InputUtil::InputValue(m_hakbun);

        cout << "\n����Ǿ����ϴ�." << endl;
    }
    if(modifyinfo == "��������"){
        /* �������� ���� */
        string searchsub;
        Subject* foundsub;
        cout << "�����Ϸ��� ���� �̸��� �Է�: ";
        InputUtil::InputValue(searchsub);

        foundsub = SubSearch(searchsub);

        if(foundsub == NULL){
            cout << "\n�߰����� ���߽��ϴ�." << endl;
        }
        else{
            foundsub->Modify();
            CalcAveGPA();
            cout << "\n����Ǿ����ϴ�." << endl;
        }
    }
    if(modifyinfo == "���"){
        /* �л�����, �������� ���� */
        cout << "\n�л��̸��� ����: ";
        InputUtil::InputValue(m_name);
        cout << "�й��� ����: ";
        InputUtil::InputValue(m_hakbun);

        for(int i = 0; i < m_subnum; i++) (m_sub+i)->Modify();

        cout << "\n����Ǿ����ϴ�." << endl;
    }
}


/* Student Ŭ���� read�� ������ �Լ� ���� */
string Student::GetName() const{
    return m_name;
}
int Student::GetHakbun() const{
    return m_hakbun;
}
int Student::GetSubNum() const{
    return m_subnum;
}
float Student::GetAveGPA() const{
    return m_aveGPA;
}