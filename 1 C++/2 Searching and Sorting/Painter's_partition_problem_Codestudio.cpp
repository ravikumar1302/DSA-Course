/*
Painter's_partition_problem_Codestudio
Given an array/list of length ‘N’, where the array/list represents the boards and each element of the given array/list represents the length of each board. 
Some ‘K’ numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint.
You are supposed to return the area of the minimum time to get this job done of painting all the ‘N’ boards under a constraint that any painter will only paint the continuous sections of boards.
*/

bool ispossible(vector<int> &boards, int k, int mid)
{
	int paintercount=1;
	int boardsection=0;
	for(int i=0;i<boards.size();i++)
	{
		if(boardsection+boards[i]<=mid)
			boardsection+=boards[i];
		else
		{
			paintercount++;
			if(paintercount>k || boards[i]>mid)
				return false;
			boardsection=boards[i];
		}
	}
	return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
	int sum=0,s=0;
	for(int i:boards)
		sum+=i;
	int e=sum; //end value = total unit area need to be painted
	int ans=-1;
	int mid=s+(e-s)/2;
	while(s<=e)
	{
		if(ispossible(boards,k,mid))
		{
			ans=mid;
			e=mid-1;
		}
		else
			s=mid+1;
		mid=s+(e-s)/2;
	}
	return ans;
}