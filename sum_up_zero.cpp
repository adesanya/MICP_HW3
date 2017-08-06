/**
_____________Assumptions________________

1: Array S contains only integers
2: Array S can be any size n greater or equal to 3
3: Size of Array n is given
4: Solution returns vector or array of pairs eg[(-1,1,0),(2,-1,-1)]

**/

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<numeric>
#include<cassert>
using namespace std;



int sum_all(std::vector<int> content)
{
	return std::accumulate(content.begin(),content.end(),0);
}


std::set<std::vector<int> > three_sum(std::vector<int> int_vec,int size,int sum_val)
{
	std::sort(int_vec.begin(),int_vec.end());
	std::set<std::vector<int> > solution;
	if(size==0) 
	{
		std::set<std::vector<int> > empty;
		return empty;	
	}
	else
	{
		for(int i=0;i<size-2;++i)
		{
			int right=size-1;
			int left=i+1;
			while(left<right)
			{
				std::vector<int> temp;
				temp.push_back(int_vec[i]);
				temp.push_back(int_vec[right]);
				temp.push_back(int_vec[left]);
				int sum=sum_all(temp);
				if(sum==sum_val)	//sum_val==0
				{
					solution.insert(temp);
					--right;
					++left;
				}
				else if(sum>sum_val)
				{
					--right;
				}
				else
				{
					++left;
				}
			} 	
		}
	}
	return solution;
}




void print_match(std::set<std::vector<int> > pair_list)
{
    for(std::set<std::vector<int> >::iterator each=pair_list.begin();each!=pair_list.end();++each)
    {
        cout<<"(";
        for(std::vector<int>::const_iterator num=each->begin();num!=each->end();++num)
        {
            cout<<*num<<" ";
        }
        cout<<") ";
    }
	cout<<endl;
}


int main()
{

	//Test Cases
	int s[]={-1, 0, 1, 2, -1, -4};
	int n=6;
	std::vector<int> s1(s,s+n); 
	std::set<std::vector<int> > ans1=three_sum(s1,6,0);
	cout<<"{-1, 0, 1, 2, -1, -4} =";
	print_match(ans1);
	//should print (-1  1  0  ) (-1  2  -1  )

	int sb[]={1, 0, 1, 2, 1, 4};
	n=6;
	std::vector<int> s2(sb,sb+n);
	cout<<"{1, 0, 1, 2, 1, 4} =";
    print_match(three_sum(s2,6,0));	
	//sould print nothing or ()

    int sc[]={0,0,0,0,0,0,0,0};
    n=8;
    std::vector<int> s3(sc,sc+n);
	cout<<"{0,0,0,0,0,0,0,0} =";
    print_match(three_sum(s3,n,0));
    //sould print (0 0 0)


	return 0;
};




