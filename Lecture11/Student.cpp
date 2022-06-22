//  Student ����Լ� ������

#include <iostream>
#include <string>
#include <string.h>
using namespace std;

#include "Student.h"
 

/* ����Ʈ �����ڸ� ���� Student Ŭ���� ��ü�� �ʱ�ȭ */
Student::Student(){
    cout << "\n����Ʈ �����ڰ� ȣ���!";  //������ ȣ�� Ȯ�ι���
    
    string m_name = "";
    int m_hakbun = 0;
    int m_subnum = 0;
    Subject* m_sub = NULL;
    float m_aveGPA = 0.0;
}

/* �����ִ� �����ڸ� ���� Student Ŭ���� ��ü�� �ʱ�ȭ(���� ����) */
Student::Student(string name, int hakbun, int subnum, Subject* sub){
    cout << "\n�����ִ� �����ڰ� ȣ���!";  //������ ȣ�� Ȯ�ι���

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
    cout << "\n���� �����ڰ� ȣ���!";  //������ ȣ�� Ȯ�ι���

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
    cout << "\n�Ҹ��ڰ� ȣ���!";  //�Ҹ��� ȣ�� Ȯ�ι���
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
    cout << "\t\t\t\t�������\t" << m_aveGPA << endl;
}


/* ���� �л��� ��� ���� ��� */
void Student::CalcAveGPA(){  
    float SumGPA = 0.0;  //GPA�� ���� ������ �Ǽ��� ������ �����Ѵ�.
    for(int i = 0; i < m_subnum; i++){  //�ּҸ� �̵��ϸ� GPA���� �����ش�.
        SumGPA += (m_sub+i)->GetGPA();  
    }

    m_aveGPA = SumGPA/m_subnum;  //��� ������ ��� ���� �����Ѵ�.
} 


/* ���� ���� */
void Student::Modify(){
    string modifyinfo;
    cout << "\n\n�Է�(�л�����/��������/���) : ";
    InputValue(modifyinfo);
    if(modifyinfo == "�л�����"){
        /* �л����� ���� */
        cout << "\n�л��̸��� ����: ";
        InputValue(m_name);
        cout << "�й��� ����: ";
        InputValue(m_hakbun);

        cout << "\n����Ǿ����ϴ�." << endl;
    }
    if(modifyinfo == "��������"){
        /* �������� ���� */
        for(int i = 0; i < m_subnum; i++) (m_sub+i)->Modify();

        cout << "\n����Ǿ����ϴ�." << endl;
    }
    if(modifyinfo == "���"){
        /* �л�����, �������� ���� */
        cout << "\n�л��̸��� ����: ";
        InputValue(m_name);
        cout << "�й��� ����: ";
        InputValue(m_hakbun);

        for(int i = 0; i < m_subnum; i++) (m_sub+i)->Modify();

        cout << "\n����Ǿ����ϴ�." << endl;
    }
    /* �߸��� �Է��� �������� ��� */
    else cout << "\n�߸��� Ŀ�ǵ��Դϴ�." << endl;
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