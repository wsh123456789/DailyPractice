#include <iostream>
using namespace std; 
int abs(int x)
{
	if(x<0)
		return -x;
	return x;
}
int main()
{
	int N;
	int data[50];
	while(cin >> N)
	{
		//��ð���ϵ�����
		int left=0,right=0;
		//��������
		for(int i=0; i<N; ++i)
		{
			cin >> data[i];
		}
		for(int i=1; i<N;++i)
		{
			//�ҵ��������ұ��������ߵ�
			if(data[i]<0&&abs(data[i])>abs(data[0]))
			{
				left++;
			}
			//�ҵ�����������������ߵ�
			if(data[i]>0&&abs(data[i])<abs(data[0]))
			{
				right++;
			}
		}
		//�ж��Ƿ�Ϊ�������
		if((data[0]<0&&right==0)||(data[0]>0&&left==0))
		{//���������
			cout << "1" <<endl;
		}else
		{
			cout << left+right+1 << endl;
		}
	}
	return 0;
}
