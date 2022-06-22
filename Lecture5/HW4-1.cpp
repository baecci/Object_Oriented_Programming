#include <iostream>
#include <cstring>
using namespace std;
#define Num 11

/*
                HW#4 : ������ �Լ����                    
  �ۼ��� : ���� 2021041081         ��¥ : 2022�� 04�� 07��   
                                                           
  ���� ���� : �Լ� �����ε� �����ϱ�                             
                                          
*/

//�Ű������� ������ Ÿ������ �Լ� �����ε�.
int GetMin(int a, int b);  //�� ���� �� �ּҰ��� ���ϴ� �Լ�.
double GetMin(double a, double b);  //�� �Ǽ� �� �ּҰ��� ���ϴ� �Լ�.
void GetMin(char *a, char *b);  //�� ���ڿ� �� �ּҰ��� ���ϴ� �Լ�.
int GetMin(int *a, int b);  //������ �迭�� ���ҵ� �� �ּҰ��� ���ϴ� �Լ�.

int main(){
    //������ �ּ� ���ϱ�
    int i1, i2;
    cout<<"�� ������ �Է��ϼ���: ";
    cin>>i1>>i2;
    cout<<"�� ���� �� �ּҰ��� "<<GetMin(i1, i2)<<"�Դϴ�.\n";

    //�Ǽ� �ּ� ���ϱ�
    double d1, d2;
    cout<<"�� �Ǽ��� �Է��ϼ���: ";
    cin>>d1>>d2;
    cout<<"�� �Ǽ� �� �ּҰ��� "<<GetMin(d1, d2)<<"�Դϴ�.\n";

    //���ڿ� �ּ� ���ϱ�
    char c1[10], c2[10];
    cout<<"�� ���ڿ��� �Է��ϼ���: ";
    cin>>c1>>c2;
    cout<<"�� ���ڿ� �� �ּҰ��� ";
    GetMin(c1, c2);
    cout<<"�Դϴ�.\n";

    //������ �迭�� ���� �ּڰ� ���ϱ�
    int intArray[Num];
    cout<<"�迭�� ���� 10���� �Է��ϼ���: ";
    for(int n=0 ;n<Num-1 ;n++){
        cin>>intArray[n];
    }
    cout<<"���� �� �ּڰ�: "<<GetMin(intArray, Num);

    return 0;
}

int GetMin(int a, int b){
    return a < b ? a : b;
}

double GetMin(double a, double b){
    return a < b ? a : b;
}

void GetMin(char *a, char *b){
    if(strcmp(a, b) == -1) cout<<a;
    else cout<<b;    
}

int GetMin(int *a, int b){
    int min = a[0];
    for(int i = 1; i < b-2; i++) min = min < a[i] ? min : a[i];
    return min;
}
