#include <iostream>
using namespace std;
#define Num 5  //�迭 ũ�⸦ �����Ѵ�.

/*
                HW#4 : ������ �Լ����                    
  �ۼ��� : ���� 2021041081         ��¥ : 2022�� 04�� 07��   
                                                           
  ���� ���� : �Լ� ���ø� �����ϱ�                     
                                          
*/

template <class T> void Sort(T *array, int arrayNum);  //�Լ� ���ø��� ���� Sort()�Լ��� �����Ͽ���.

int main(){
    while(1){
        cout<<"\n----------�޴�----------\n"<<" 1. ���� �����ϱ�\n"<<" 2. �Ǽ� �����ϱ�\n"<<" 3. ���α׷� ����\n";  //�޴��� ����Ѵ�.
        cout<<"\n�޴��� �����ϼ���: ";
        int m;
        cin>>m;
        switch(m){
            case 1:
                int iarr[Num];  //������ �迭�� �����Ѵ�.

                for(int i = 0; i < Num; i++){  //�迭 ���Ҹ� �Է��Ѵ�.
                    cout<<i + 1<<"��° �������� �Է��ϼ���: ";
                    cin>>iarr[i];
                }
                Sort(iarr, Num);  //�迭 ���Ҹ� �������� ���������Ѵ�.

                cout<<"���� ��:";
                for(int i = 0; i < Num; i++){  //���ĵ� �迭 ���ҵ� ����Ѵ�.
                    cout<<" "<<iarr[i];
                }

                break;

            case 2:
                float farr[Num];  //�Ǽ��� �迭�� �����Ѵ�.

                for(int i=0;i<Num;i++){  //�� �Ʒ����ʹ� case 1�� ���� �˰����̴�.
                    cout<<i+1<<"��° �Ǽ����� �Է��ϼ���: ";
                    cin>>farr[i];
                }
                Sort(farr, Num);

                cout<<"���� ��:";
                for(int i = 0; i < Num; i++){
                    cout<<" "<<farr[i];
                }
                cout<<"\n\n";
                break;

            case 3:
                return 0;  
            
            default:  //1~3 �̿� ��ȣ �Է½� ���� ������ ����Ѵ�.
                cout<<"\n�ش� ����� �����ϴ�."; 
                break;
        }
    }
}

template <class T> void Sort(T *array, int arrayNum){  //��������.
    T temp;
    for(int i = 0; i < arrayNum-1; i++){
        for(int j = i + 1; j < arrayNum; j++){
            if(array[i] > array[j]){
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

