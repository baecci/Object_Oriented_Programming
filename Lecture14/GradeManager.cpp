//  GradeManger Ŭ���� ����Լ� ������


#include <iostream>
#include <string>
using namespace std;

#include "GradeManager.h"
#include "Student.h"

GradeManager::GradeManager(){
    Student* m_std = NULL;
    int m_stdnum = 0;
}
GradeManager::GradeManager(int m_stdnum){
    this -> m_stdnum = m_stdnum;
    m_std = new Student[m_stdnum];
}

GradeManager::~GradeManager(){
    delete[] m_std;
}

void GradeManager::PrintMenu(){
    cout << endl;
    cout << "====== �޴� ======" << endl;
    cout << "1. �л�  ����  �Է�" << endl;
    cout << "2. ��ü  ����  ����" << endl;
    cout << "3. �л�  �˻�" << endl;
    cout << "4. �л�  ���  ����" << endl;
    cout << "5. �л�  ����  ����" << endl;
    cout << "6. ���α׷�  ����" << endl;
    cout << endl;
    cout << "���ϴ� ����� �Է��ϼ���(��ȣ�Է�): ";
}

void GradeManager::Execute(){
    while(true){
        PrintMenu();
        int command;
        InputUtil::InputValue(command);
        if(command == 1){ //�л� ���� �Է�
            for(int i = 0; i<m_stdnum; i++){
                cout << i+1 << "��° �л��� ������ �Է��ϼ���." << endl;
                m_std[i].InputData();
            }
        }
        if(command == 2){  // �л� ���� ���
            for(int i = 0; i<m_stdnum; i++){
                m_std[i].PrintData();
            }
        }
        if(command == 3){  // �л� �̸����� �˻� �� ���� ���
            string searchstdname;
            cout << "ã�� �л��� �̸��� �з��ϼ���: ";
            InputUtil::InputValue(searchstdname);
            
            Student* std = StdSearch(searchstdname);

            if(std == NULL){
                cout << "\nã���ô� �л��� �����ϴ�." << endl;
                continue;
            }
            else
                std->PrintData();
        }
        if(command == 4){  // ��ü �л� ����Ʈ ���
            PrintAllStdList();
        }
        if(command == 5){  // �˻��� �л��� ���� ����
            Modify();
        }
        if(command == 6){  // ���α׷� ����
            cout << "\n���α׷��� �����մϴ�." << endl;
            break;
        }
        else cout << "\n�������� �ʴ� Ŀ�ǵ��Դϴ�." << endl;
    }
}

Student* GradeManager::StdSearch(string stdname) const{
    for(int i = 0; i<m_stdnum; i++){
        /* �߰߿� ������ �ش� �л�Ŭ���� ��ü�� �ּ� ���� */
        if(stdname == m_std[i].GetName()){
            return &m_std[i];
        }
    }
    /* �л��� �߰����� ���ϸ� NULL���� */
    return NULL;
}

void GradeManager::PrintAllStdList() const{
    cout << "----------------------------------" << endl;
    for(int i = 0; i<m_stdnum; i++){
        cout.width(10);
        cout << m_std[i].GetName() << "\t" << m_std[i].GetHakbun() << endl;
    }
    cout << "----------------------------------" << endl;
} 

void GradeManager::Modify(){
    string searchname;
    cout << "������ �л��� �̸��� �Է��ϼ���: ";
    InputUtil::InputValue(searchname);

    Student* foundstd = StdSearch(searchname);

    /* �ش� �ٻ��� ã�� ���ϸ� ���� ���� ��� */
    if(foundstd == NULL){
        cout << "\nã���ô� �л��� �����ϴ�." << endl;
    }
    /* �л��� ã�Ҵٸ� StudentŬ������ Modify�Լ� ȣ�� */
    else foundstd->Modify();
}