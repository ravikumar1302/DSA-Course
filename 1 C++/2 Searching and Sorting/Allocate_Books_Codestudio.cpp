/*
Allocate_Books_Codestudio
Given an array ‘arr’ of integer numbers . where ‘arr[i]’ represents the number of pages in the ‘i-th’ book. There are ‘m’ number of students and the task is to allocate all the books to their students. Allocate books in such a way that:
1. Each student gets at least one book.
2. Each book should be allocated to a student.
3. Book allocation should be in a contiguous manner.
You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum.
*/
bool ispossible(vector<int>arr, int n, int m, int mid)
{
	int studentcount=1;
	int pagesum=0;
	for(int i=0;i<n;i++)
	{
		if(pagesum+arr[i]<=mid)
			pagesum+=arr[i];
		else
		{
			studentcount++;
			if(studentcount>m || arr[i]>mid)
				return false;
			pagesum=arr[i];
		}
	}
	return true;
}

int allocateBooks(vector<int> arr, int n, int m) {
    
	int sum=0, s=0;
	for(int i:arr)
		sum+=i;
	
	int e =sum;  //end value equals to sum of total pages
	int ans=-1;
	int mid=s+(e-s)/2;
	
	while(s<=e)
	{
		if(ispossible(arr,n,m,mid))
		{ //if 1, means check value less then mid, as we have to find minimum
			ans=mid;
			e=mid-1;
		}
		else
			s=mid+1;
		mid=s+(e-s)/2;
	}
	return ans;
}