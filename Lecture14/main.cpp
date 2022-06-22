#include <iostream>
#include <string>
using namespace std;

#include "InputUtil.h"
#include "Subject.h"
#include "Student.h"
#include "GradeManager.h"


/*
                HW#12 : ��ü�������� ����ó�����α׷�#5             
  �ۼ��� : ���� 2021041081         ��¥ : 2022�� 06�� 3��   

  ���� ���� : �����Լ��� ������ & �߻� Ŭ���� �׽�Ʈ
*/
// int main(){

//   Student std;
//   std.InputData();    

//   IOInterface* IO[2]  = {new Subject("������",3,"A+"), &std}; 

//   for (int i=0; i<2; i++) {
//     cout << "\n * " << i+1 << "��°  ������  : " << "\n";
//     IO[i]->PrintData();   // �Ļ�Ŭ������  ����Լ���  ȣ��Ǿ��  �� 
//     //�⺻ Ŭ������ IOInterface�� PrintData() ���� �Լ�ȭ
//   }
// }


/*
                HW#12 : ��ü�������� ����ó�����α׷�#5             
  �ۼ��� : ���� 2021041081         ��¥ : 2022�� 06�� 3��   

  ���� ���� : GradeManger Ŭ���� �׽�Ʈ
*/
int main() { 
  int stdnum;
  
  cout << "�л� ���� �Է��ϼ���: "; 
  InputUtil::InputValue(stdnum); 
  cout << endl;

  /* GradeManager Ŭ������ ��ü ���α׷� ���� */
  GradeManager GradeMgr(stdnum); 
  GradeMgr.Execute();
}