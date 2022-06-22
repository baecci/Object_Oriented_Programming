#include <iostream>
#include <cstring>
using namespace std;

/*
                HW#4 : ������ �Լ����                    
  �ۼ��� : ���� 2021041081         ��¥ : 2022�� 04�� 07��   
                                                           
  ���� ���� : ����ó�����α׷�#3(�ζ��� �Լ� ����ؼ� #2�� ����)                             
                                          
*/
      
#define StdNum 2  //�л� ��.
#define SubNum 3  //������ ��.

struct Subject{  //���������� ���� ����ü.
    char subName[30];
    int Hakjum;
    char Grade[10];
    float GPA;
};
struct Student{  //�л������� ���� ����ü.
    char stName[30];
    int Hakbun;
    Subject Sub[3];
    float AveGPA;
};
Student st[StdNum];  //Student Ÿ�� ����ü �迭 ����.

inline void PrintMenu();  
inline void InputValue(char *str);  
inline void InputValue(int &i);  
void PrintAllStdList(Student *pSt, int StudentNum);  
void CalcGPA(Subject& Sub); 
float CalcAveGPA(Subject* Sub);  
void PrintAllData(const Student* pSt, int StudentNum);  
void PrintOneData(const Student& rSt);  
Student* StdSearch(Student* pSt, int StudentNum);  
void ModifyStdInfo(Student *pSt);  

int main(){   
    while(1){  //�޴�->���->�޴� ���ѹݺ�.
        PrintMenu();  
        int m;  
        InputValue(m);  //�޴����� ��� �����ϱ�.
        if(m==1){  //1�� ���.
            int i;
            for(i=0;i<StdNum;i++){  //�� �л� �Ż� �Է��ϱ�. 
                cout<<"\n\n"<<i+1<<"�� �л��� �̸��� �й��� �Է��ϼ���.";
                cout<<"\n�̸�: ";
                InputValue(st[i].stName);
                cout<<"�й�: ";
                InputValue(st[i].Hakbun);
                cout<<"\n\n�л��� ������ ���� 3���� �����, ����������, �������� �Է��ϼ���.";
                int j;
                for(j=0;j<SubNum;j++){  //�л��� ���� ���� �Է��ϱ�.
                    cout<<"\n\n�����: ";
                    InputValue(st[i].Sub[j].subName);
                    cout<<"����������: ";
                    InputValue(st[i].Sub[j].Hakjum);
                    cout<<"������(A+ ~ F): ";
                    InputValue(st[i].Sub[j].Grade);
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
            PrintAllStdList(st, StdNum);
        }
        if(m==5){  //5�� ���
            ModifyStdInfo(st);
        }
        if(m==6){  //6�� ���
            return 0;
        }
    }
}


inline void PrintMenu(){
    cout<<"\n[�ѤѤѤѤѤѸ޴��ѤѤѤѤѤ�]\n";
    cout<<" 1. �л� ���� �Է��ϱ�\n";
    cout<<" 2. ��ü �л� ���� Ȯ���ϱ�\n";
    cout<<" 3. �л��� �̸� �˻��ϱ�\n";
    cout<<" 4. ��ü �л� ��� ����\n";
    cout<<" 5. �л� ���� �����ϱ�\n";
    cout<<" 6. ���α׷� �����ϱ�\n";
    cout<<"\n ���Ͻô� �޴��� �Է��ϼ���: ";
} //�ζ��� �Լ��� �޴��� �� ȿ�����̰� ����Ѵ�.


inline void InputValue(char *str){  
    cin>>str;
} //���ڿ� ���� �����͸� �Է��Ѵ�. (�л� �̸�, �����, ������)


inline void InputValue(int &i){
    cin>>i;
} //������ ���� �����͸� �Է��Ѵ�. (�޴� ��ȣ, �й�, ����)


void PrintAllStdList(Student *pSt, int StudentNum){
    cout<<"\n----------------------------------------------------\n";
    cout.width(10);
    cout<<"�й� "<<"\t�̸� ";
    cout<<"\n----------------------------------------------------\n";
    for(int i = 0; i < StudentNum; i++){
        cout.width(10);
        cout<<(pSt + i)->Hakbun<<"\t"<<(pSt + i)->stName<<"\n";
    }
    cout<<"----------------------------------------------------\n";
} //��ü �л��� �й��� �̸��� ����Ʈ�� ����Ѵ�.


void CalcGPA(Subject& Sub){  //�������� ������ ��ȯ�ϰ�, ���۷����� �����Ͽ� GPA�� ����Ѵ�.
    if(Sub.Grade[0]=='A'){
        if(Sub.Grade[1]=='+') Sub.GPA=4.5*(Sub.Hakjum);
        else if(Sub.Grade[1]=='0') Sub.GPA=4.0*(Sub.Hakjum);
    }
    if(Sub.Grade[0]=='B'){
        if(Sub.Grade[1]=='+') Sub.GPA=3.5*(Sub.Hakjum);
        else if(Sub.Grade[1]=='0') Sub.GPA=3.0*(Sub.Hakjum);
    }
    if(Sub.Grade[0]=='C'){
        if(Sub.Grade[1]=='+') Sub.GPA=2.5*(Sub.Hakjum);
        else if(Sub.Grade[1]=='0') Sub.GPA=2.0*(Sub.Hakjum);
    }
    if(Sub.Grade[0]=='D'){
        if(Sub.Grade[1]=='+') Sub.GPA=1.5*(Sub.Hakjum);
        else if(Sub.Grade[1]=='0') Sub.GPA=1.0*(Sub.Hakjum);
    }
    if(Sub.Grade[0]=='F'){
        Sub.GPA=0.0*(Sub.Hakjum);
    }
} //�� ������ ������ ����Ѵ�.


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
} //���� �л��� ������ ��������� ����Ѵ�. (�� ������ ������ ��� ��� �� �� ���� ��հ��)


void PrintAllData(const Student* pSt, int StudentNum){ //Student�� �����Ͱ� ����Ű�� �ּ� ���� ���� ���������Ƿ� �б� �����̴�.
    cout<<"\n"<<"                  [��ü �л��� ���� ����]\n";
    cout<<"--------------------------------------------------------------\n";
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
} //��ü �л� �Ż�&���� ������ ����Ѵ�.


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
} //���� �л��� �Ż�&���� ������ ����Ѵ�.


Student* StdSearch(Student* pSt, int StudentNum){
    char SearchName[30];  //ã�� �̸��� �Է¹��� ���ڿ� ������ �����Ѵ�.
    cout<<"�˻� �� �л��� �̸��� �Է��ϼ���: ";
    InputValue(SearchName);
    for(int i=0;i<StudentNum;i++){  //�л����� �̸��� ���ڿ����Լ��� ���Ͽ� �˻��� �̸��� ������(�Լ� ���� ���� 0�̸�) �ش� �л��� �ε��� �ּҸ� �����Ѵ�.
        if(strcmp((pSt+i)->stName,SearchName)==0) return &st[i];  
    }
    return NULL;  //�߰����� ���ߴٸ� NULL�� ������ ã�� ���ߴٴ� ���� �˸���.
} //�л� �̸� �˻� �� �ش� �л��� ������ �ִ� ���� �ּҸ� �����Ѵ�.


void ModifyStdInfo(Student *pSt){
    pSt=StdSearch(st,StdNum);  //StdSearch�Լ��� ȣ���� �л��� ã��, �ش� �л��� ������ �ּҸ� pSt�� �����Ѵ�.
    if(pSt != NULL){
        cout<<"\n["<<pSt->stName<<" "<<pSt->Hakbun<<"]�� ������ �����ϼ���.\n\n";  //�����͸� �����Ѵ�.
        cout<<"������ �̸�: ";
        InputValue(pSt->stName);
        cout<<"������ �й�: ";
        InputValue(pSt->Hakbun);
        cout<<"\n����Ǿ����ϴ�.\n";  
    }
    else cout<<"\n�ش� �л��� ������ ã�� �� �����ϴ�.\n";  //�л��� ã�� ���� ��� ���������� ����Ѵ�.
} //�˻��� �л��� �Ż� ������ �����Ѵ�.