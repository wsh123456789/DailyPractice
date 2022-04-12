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
		//感冒蚂蚁的数量
		int left=0,right=0;
		//输入数据
		for(int i=0; i<N; ++i)
		{
			cin >> data[i];
		}
		for(int i=1; i<N;++i)
		{
			//找到该蚂蚁右边且向左走的
			if(data[i]<0&&abs(data[i])>abs(data[0]))
			{
				left++;
			}
			//找到该蚂蚁左边且向右走的
			if(data[i]>0&&abs(data[i])<abs(data[0]))
			{
				right++;
			}
		}
		//判断是否为特殊情况
		if((data[0]<0&&right==0)||(data[0]>0&&left==0))
		{//见上面解析
			cout << "1" <<endl;
		}else
		{
			cout << left+right+1 << endl;
		}
	}
	return 0;
}
