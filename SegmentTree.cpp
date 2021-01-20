#include<bits/stdc++.h>
using namespace std;
/*
Name 			=  	SEGMENT TREE
Class Name		= 	STtree
Constructor		=	STtree(vector<T>,int,T,T(*function)(T,T)) :
	1.vector<T>	=	Array of elements on which Segment Tree is to be formed
	2.int		=	Size of the array
	3.T		=	An identity value..example : 0 for add function,1 for multiplication function,etc.
	4.T function	=	A BINARY FUNCTION on which Segment Tree is to be built
Functions		=
	1.T querry(int l,int r)			=	Will return a querry on the range between l and r inclusive.
	2.void update(int pos,int new_val)	=	Update and make changes accordingly to the segment tree. It will update the position "pos" with the new value "new_val".
*/
template <typename T>
class STtree{
    private:
    vector<T> ar;
    vector<T> t;
    T(*func)(T,T);
    T RD;
    int n;
    public:
	STtree(vector<T> a,int s,T rd,T(*function)(T,T))
	{
		func=function;
		ar=a;
		t.resize(4*s);
		n=s;
		RD=rd;
		build(1,0,n-1);
	}
        void build(int v,int tl,int tr)
        {
		if(tl==tr)
			t[v]=ar[tl];
		else
		{
			int m=(tl+tr)/2;
			build(v*2,tl,m);
			build(v*2+1,m+1,tr);
			t[v]=func(t[v*2],t[v*2+1]);
		}
	}
	T querry(int l,int r,int v=1,int tl=0,int tr=-1)
	{
		if(tr==-1)
			tr+=n;
		if(l>r)
			return RD;
		else if(l==tl && r==tr)
		{
			return t[v];
		}
		else
		{
			int m=(tl+tr)/2;
			return func(querry(l,min(m,r),v*2,tl,m),querry(max(m+1,l),r,v*2+1,m+1,tr));
		}
	}
	void update(int pos,int new_val,int v=1,int tl=0,int tr=-1)
	{
		if(tr==-1)
			tr+=n;
		if(tl==tr)
			t[v]=new_val;
		else
		{
			int m=(tl+tr)/2;
			if(pos<=m)
				update(pos,new_val,2*v,tl,m);
			else
				update(pos,new_val,2*v+1,m+1,tr);
			t[v]=func(t[v*2],t[v*2+1]);
		}
	}
};



/*EXAMPLE USAGE	:
*/
int Add(int a,int b)
{
	return a+b;
}
int main()
{
	//Vector of elements
	vector<int> A={1,2,3,4,5};
	//Initializing and building the segment tree
	STtree<int> tr(A,5,0,Add);
	//Using tr
	cout<<tr.querry(0,2)<<"\n";
	tr.update(1,4);
	cout<<tr.querry(0,2)<<"\n";
	return 0;
}
