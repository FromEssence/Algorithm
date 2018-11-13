/**
 *��������
 *11/8/2018
*/
#include <bits/stdc++.h>
using namespace std;
#define ElementType int
const int Cutoff = 4;
ElementType Median3( ElementType A[], int Left, int Right )
{
    int Center = (Left+Right) / 2;
    if ( A[Left] > A[Center] )
        swap( A[Left], A[Center] );
    if ( A[Left] > A[Right] )
        swap( A[Left], A[Right] );
    if ( A[Center] > A[Right] )
        swap( A[Center], A[Right] );
    /* ��ʱA[Left] <= A[Center] <= A[Right] */
    swap( A[Center], A[Right-1] ); /* ����׼Pivot�ص��ұ�*/
    /* ֻ��Ҫ����A[Left+1] �� A[Right-2] */
    cout  <<A[Right-1];
    return  A[Right-1];  /* ���ػ�׼Pivot */
}

void Qsort( ElementType A[], int Left, int Right )
{ /* ���ĵݹ麯�� */
     int Pivot, Low, High;

     if ( Cutoff <= Right-Left ) { /* �������Ԫ�س�ֶ࣬������� */
          Pivot = Median3( A, Left, Right ); /* ѡ��׼ */
          Low = Left; High = Right-1;
          while (1) { /*�������бȻ�׼С���Ƶ���׼��ߣ�����Ƶ��ұ�*/
               while ( A[++Low] < Pivot ) ;
               while ( A[--High] > Pivot ) ;
               if ( Low < High ) swap( A[Low], A[High] );
               else break;
          }
          swap( A[Low], A[Right-1] );   /* ����׼������ȷ��λ�� */
          Qsort( A, Left, Low-1 );    /* �ݹ������ */
          Qsort( A, Low+1, Right );   /* �ݹ����ұ� */
     }
     else sort( A+Left, A+Right+1 ); /* Ԫ��̫�٣��ü����� */
}

void QuickSort( ElementType A[], int N )
{ /* ͳһ�ӿ� */
     Qsort( A, 0, N-1 ); //������Ԫ�ش�0��
}

int main(){
	int n;
	int elem[100];
	cin >>n;
	for(int i=0; i<n; i++){
		cin >>elem[i];

	}
	QuickSort(elem, n);

	cout <<endl;
	for(int i=0; i<n; i++){
		cout <<elem[i] <<' ';
	}

	return 0;
}


