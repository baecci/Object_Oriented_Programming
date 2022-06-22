#include <iostream>
#include <string>
using namespace std;

#include "Subject.h"
#include "Student.h"


/*
                HW#8 : Ŭ���� ����-1                   
  �ۼ��� : ���� 2021041081         ��¥ : 2022�� 05�� 06��   

  ���� ���� : subject Ŭ������ ���� �� �׽�Ʈ(�پ��� ������ ��ü�� �������� �Է¹ް� ���)                 

*/
int main() {

    /* �Ϲݰ�ü, �迭��ü, �����Ͱ�ü�� ��ü���� */
    Subject sub1, sub2, sub3[2], *sub4; 
    int i;

    /* �Ϲݰ�ü, ��ü�迭, ��ü������ �ʱ�ȭ */
    sub1.Initialize();      
    sub2.Initialize("������", 3, "A+"); 
    for (i = 0; i < 2; i++) sub3[i].Initialize("��ǻ��", 3, "C"); 
    sub4 = new Subject[2];
    
    /* ��ü�� �������� �Է� �� ��� */
    sub1.InputData();  
    cout << "\n" << "sub1 ����" << endl; 
    sub1.PrintTitle();          sub1.PrintData(); 

    cout << "\n" << "sub2 ����" << endl; 
    sub2.PrintTitle();          sub2.PrintData();

    cout << "\n" << "sub3 ����" << endl; 
    sub3[0].PrintTitle();
    for (i = 0; i < 2; i++) sub3[i].PrintData();

    for (i = 0; i < 2; i++) (sub4 + i)->InputData(); 
    cout << "\n" << "sub4 ����" << endl;
    sub4->PrintTitle();
    for (i = 0; i < 2; i++) (sub4 + i)->PrintData(); 
    
    /* cout << sub1.m_name;�� protected�� ���� ���� �Ұ� */
    /* read�� ������ �Լ��� �����ؼ� �׽�Ʈ */
    cout << sub1.GetName() << endl;
    cout << sub2.GetName() << endl;
    
    for(i=0; i < 2; i++)
        cout << sub3[i].GetName() << endl;

    cout << sub4->GetName() << endl;

    /* �����Ҵ� ��ü �� ���α׷� ���� */
    delete [] sub4;
    return 0;
}


/*
                HW#8 : Ŭ���� ����-2                  
  �ۼ��� : ���� 2021041081         ��¥ : 2022�� 05�� 10��   

  ���� ���� : student Ŭ������ ���� �� �׽�Ʈ(�پ��� ������ ��ü�� �л����� �� �������� �Է¹ް� ���)                  

*/
// int main() { 
//     Subject sub[2];

//     /* Subject Ŭ������ ��ü �ʱ�ȭ */
//     sub[0].Initialize("��ǻ��", 3, "C"); 
//     sub[1].Initialize("���빫��", 2, "A");
    
//     Student st1, st2;
    
//     /* �� Student Ŭ������ ��ü �ʱ�ȭ */
//     st1.Initialize();      
//     st2.Initialize("ȫ�浿", 2013909845, 2, sub);
    
//     /* st1 ��ü�� �л�����, �������� �Է� */
//     st1.InputData();

//     /* �� Student Ŭ������ ��ü ���� ��� */
//     cout << "\n" << "st1 ����" << "\n"; 
//     st1.PrintData();
//     cout << "\n" << "st2 ����" << "\n"; 
//     st2.PrintData();

//     /* ���� �Ҵ� ���� �� ���α׷� ���� */
//     st1.Remove(); 
//     return 0;
// }


/*
                HW#8 : Ŭ���� ����-3                 
  �ۼ��� : ���� 2021041081         ��¥ : 2022�� 05�� 12��   

  ���� ���� : student Ŭ������ friend �Լ� �׽�Ʈ                  

*/
// void ShowData(const Student &);

// int main() {
//     Student st;

//     /* ��ü �⺻ �ʱ�ȭ �� �л�����, �������� �Է� */
//     st.Initialize();
//     st.InputData();

//     ShowData(st);    
// }

// void ShowData(const Student &s) { // �������α׷��� �ִ� �����Լ�
//     cout << s.m_name << "�� ������ ������ ��" << s.m_subnum << "���� ";
//     cout << "������ ������ ��������� " << s.m_aveGPA << "�Դϴ�.\n";
// }



