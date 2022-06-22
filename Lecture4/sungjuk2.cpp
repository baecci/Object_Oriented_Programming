/*
    ��ü�������α׷��� ����ó�����α׷�#2
    
    ��米��: �ְ��� ������ / TA: ������, ������ �����

    ���� 2021041081                  
*/  

#include <iostream>
#include <string.h>
using namespace std;      
#define StdNum 2  //�л� ��.
#define SubNum 3  //������ ��.

struct Subject{  //���������� ���� ����ü.
    char subName[30];
    int Hakjum;
    string Grade;
    float GPA;
};
struct Student{  //�л������� ���� ����ü.
    char stName[30];
    int Hakbun;
    Subject Sub[3];
    float AveGPA;
};
Student st[StdNum];  //Student Ÿ�� ����ü �迭 ����.

void PrintMenu();  //�޴��� ����Ѵ�.
void CalcGPA(Subject& Sub); //�� ������ ������ ����Ѵ�.
float CalcAveGPA(Subject* Sub);  //���� �л��� �� ������ ��������� ����Ѵ�.
void PrintAllData(const Student* pSt, int StudentNum);  //��ü �л� �Ż�&���� ���� ����Ѵ�.
void PrintOneData(const Student& rSt);  //���� �л� �Ż�&���� ������ ����Ѵ�.
Student* StdSearch(Student* pSt, int StudentNum);  //�л� �̸� �˻� �� �ش� �л��� ������ �ִ� ���� �ּҸ� �����Ѵ�.

int main(){   
    while(1){  //�޴�->���->�޴� ���ѹݺ�.
        PrintMenu();  
        int m;  
        cin>>m;  //�޴����� ��� �����ϱ�.
        if(m==1){  //1�� ���.
            int i;
            for(i=0;i<StdNum;i++){  //�� �л� �Ż� �Է��ϱ�. 
                cout<<"\n\n"<<i+1<<"�� �л��� �̸��� �й��� �Է��ϼ���.";
                cout<<"\n�̸�: ";
                cin>>st[i].stName;
                cout<<"�й�: ";
                cin>>st[i].Hakbun;
                cout<<"\n\n�л��� ������ ���� 3���� �����, ����������, �������� �Է��ϼ���.";
                int j;
                for(j=0;j<SubNum;j++){  //�л��� ���� ���� �Է��ϱ�.
                    cout<<"\n\n�����: ";
                    cin>>st[i].Sub[j].subName;
                    cout<<"����������: ";
                    cin>>st[i].Sub[j].Hakjum;
                    cout<<"������(A+ ~ F): ";
                    cin>>st[i].Sub[j].Grade;
                    CalcGPA(st[i].Sub[j]);  //�л��� ���� �ּҸ� ���ڷ� �Ѱ��ش�.
                }
                st[i].AveGPA=CalcAveGPA(st[i].Sub);  //��� ������ ����ؼ� �� �л� ����ü�� �����Ѵ�.
            }
        }
        if(m==2){  //2�� ���
            PrintAllData(st,StdNum);  //����ü �迭 st�� �ּҿ� �л� ���� ���ڷ� �Ѱ��ش�.
        }
        if(m==3){  //3�� ���
            Student* FindName;  //ã�� �л� ������ �ּҸ� ������ ����ü �������̴�.
            FindName=StdSearch(st,StdNum);  //����ü �迭 st�� �ּҿ� �л� ���� ���ڷ� �Ѱ��ش�.
            if(FindName != NULL) PrintOneData(*FindName);  //�л� ������ ã������, ã�� �л��� ������ ���� �Ѱ��ش�.
            else cout<<"�ش� �л��� ������ ã�� �� �����ϴ�.";
        }
        if(m==4){  //4�� ���
            return 0;
        }
    }
}

void PrintMenu(){
    cout<<"\n[�ѤѤѤѤѤѸ޴��ѤѤѤѤѤ�]\n";
    cout<<" 1. �л� ���� �Է��ϱ�\n";
    cout<<" 2. ��ü �л� ���� Ȯ���ϱ�\n";
    cout<<" 3. �л��� �̸� �˻��ϱ�\n";
    cout<<" 4. ���α׷� �����ϱ�\n";
    cout<<"\n ���Ͻô� �޴��� �Է��ϼ���: ";
} //�޴� ���

void CalcGPA(Subject& Sub){  //�������� ������ ��ȯ�ϰ�, ���۷����� �����Ͽ� GPA�� ����Ѵ�.
    if(Sub.Grade=="A+"){
        Sub.GPA=4.5*(Sub.Hakjum);
    }
    if(Sub.Grade=="A0"){
        Sub.GPA=4.0*(Sub.Hakjum);
    }
    if(Sub.Grade=="B+"){
        Sub.GPA=3.5*(Sub.Hakjum);
    }
    if(Sub.Grade=="B0"){
        Sub.GPA=3.0*(Sub.Hakjum);
    }
    if(Sub.Grade=="C+"){
        Sub.GPA=2.5*(Sub.Hakjum);
    }
    if(Sub.Grade=="C0"){
        Sub.GPA=2.0*(Sub.Hakjum);
    }
    if(Sub.Grade=="D+"){
        Sub.GPA=1.5*(Sub.Hakjum);
    }
    if(Sub.Grade=="D0"){
        Sub.GPA=1.0*(Sub.Hakjum);
    }
    if(Sub.Grade=="F"){
        Sub.GPA=0.0*(Sub.Hakjum);
    }
} //�� �������� ���� ���

float CalcAveGPA(Subject* Sub){  
    float SumGPA=0.0;  //GPA�� ���� ������ �Ǽ��� ������ �����Ѵ�.
    for(int i=0;i<SubNum;i++){  //����ü �ּҸ� �̵��ϸ� GPA���� �����ش�.
        SumGPA += (Sub+i)->GPA;  
    }

    float SumHakjum=0.0;  //������ ���� ������ �Ǽ��� ������ �����Ѵ�.
    for(int j=0;j<SubNum;j++){  //����ü �ּҸ� �̵��ϸ� �������� �����ش�.
        SumHakjum += (Sub+j)->Hakjum;
    }

    float R=SumGPA/SumHakjum;  //R������ ��� ������ ��� ���� �����Ѵ�.
    return R;
} //���� �л��� ��� ���� ���(�� ������ ������ ��� ��� �� �� ���� ��հ��)

void PrintAllData(const Student* pSt, int StudentNum){ //Student�� �����Ͱ� ����Ű�� �ּ� ���� ���� ���������Ƿ� �б� �����̴�.
    cout<<"\n"<<"                   ��ü �л��� ���� ����\n";
    cout<<"==============================================================\n";
    for(int i=0;i<StudentNum;i++){
        cout.width(10);
        cout<<"�̸�: "<<(pSt+i)->stName<<"\t�й�: "<<(pSt+i)->Hakbun;  //�ּҸ� �̵��ϸ� ���ʷ� �л� ������ ����Ѵ�.
        cout<<"\n--------------------------------------------------------------\n";
        cout.width(10);
        cout<<"�����"<<"\t����������"<<"\t������"<<"\t��������";
        cout<<"\n--------------------------------------------------------------\n";
        for(int j=0;j<SubNum;j++){  //���������� ����ü�� �ּҸ� �̵����ָ� �� ������ ������ ����Ѵ�. 
            cout.width(10);
            cout<<(pSt+i)->Sub[j].subName<<"\t\t"<<(pSt+i)->Sub[j].Hakjum<<"\t\t"<<(pSt+i)->Sub[j].Grade<<"\t\t"<<(pSt+i)->Sub[j].GPA<<"\n";
        }   
        cout<<"--------------------------------------------------------------\n"; 
        cout.width(10);
        cout<<"\t\t\t\t\t\t�������= "<<(pSt+i)->AveGPA<<"\n\n";
    }
} //��ü �л� �Ż�&���� ���� ���

void PrintOneData(const Student& rSt){  //read only reference rSt�� �˻��� �л� ���� ���  
    cout.width(10);
    cout<<"\n�̸�: "<<rSt.stName<<"\t�й�: "<<rSt.Hakbun;  //���۷����� �����Ͽ� ������ش�.
    cout<<"\n--------------------------------------------------------------\n";
    cout.width(10);
    cout<<"�����"<<"\t����������"<<"\t������"<<"\t��������";
    cout<<"\n--------------------------------------------------------------\n";
    for(int i=0;i<SubNum;i++){  //���������� ���۷����� �����Ͽ� �� ������ ������ ����Ѵ�.
        cout.width(10);
        cout<<rSt.Sub[i].subName<<"\t\t"<<rSt.Sub[i].Hakjum<<"\t"<<rSt.Sub[i].Grade<<"\t\t"<<rSt.Sub[i].GPA<<"\n";
    } 
    cout<<"--------------------------------------------------------------\n"; 
        cout.width(10);
        cout<<"\t\t\t\t\t\t�������= "<<rSt.AveGPA<<"\n\n";    
} //���� �л� �Ż�&���� ���� ���

Student* StdSearch(Student* pSt, int StudentNum){
    char SearchName[30];  //ã�� �̸��� �Է¹��� ���ڿ� ������ �����Ѵ�.
    cout<<"�˻� �� �л��� �̸��� �Է��ϼ���: ";
    cin>>SearchName;
    for(int i=0;i<StudentNum;i++){  //�л����� �̸��� ���ڿ����Լ��� ���Ͽ� �˻��� �̸��� ������(�Լ� ���� ���� 0�̸�) �ش� �л��� �ε��� �ּҸ� �����Ѵ�.
        if(strcmp((pSt+i)->stName,SearchName)==0) return &st[i];  
    }
    return NULL;  //�߰����� ���ߴٸ� NULL�� ������ ã�� ���ߴٴ� ���� �˸���.
} //�л� �̸� �˻� �� �ش� �л��� ������ �ִ� ���� �ּҸ� ����