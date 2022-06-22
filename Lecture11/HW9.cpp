#include <iostream>
#include <string>
using namespace std;

#include "Subject.h"
#include "Student.h"


/*
                HW#9 : ��ü�������� ����ó�����α׷�#2                   
  �ۼ��� : ���� 2021041081         ��¥ : 2022�� 05�� 17��   

  ���� ���� : Modify�Լ� �߰� �� �����ڿ� �Ҹ��� �׽�Ʈ                

*/


int main() {
    Subject sub1("��ǻ��", 3, "C"); 
    Subject sub2(sub1);  //���� ������(���� ���� ����)
    cout << "\n" << "sub1 ����" << "\n"; 
    sub1.PrintData();
    cout << "\n" << "sub2 ����" << "\n"; 
    sub2.PrintData();
    sub2.Modify();
    
    //Student st1;  //����Ʈ ������ ȣ��
    Student st2("ȫ�浿", 2013909845, 1, &sub1);  //st2�� �����ִ� ������, ������� sub ����Ʈ ������ ȣ��
    Student st3("�輺��", 2015909845, 1, &sub2);  // ''
    Student st1(st2);

    st1 = st2;  
    cout << "\n" << "st1 ����" << "\n"; 
    st1.PrintData();    

    cout << "\n" << "st2 ����" << "\n"; 
    st2.PrintData();
    st2.Modify();
    cout << "\n" << "������  st2 ����" << "\n"; 
    
    st2.PrintData();
    cout << "\n" << "st2 ���� �� st1 ����" << "\n";  
    //���� ���縦 �����Ƿ� �л������� st1�� st2�� �ٸ��� ��µǾ���.
    //������ subject Ŭ������ �����ڴ� ���� ���縦 �ϹǷ� st2�� ���������� �����ϴ� st1�� �������� ���� �����Ǿ���.
    st1.PrintData(); 

    cout << "\n" << "st3 ����" << "\n"; 
    st3.PrintData();    
}