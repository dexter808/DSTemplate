import java.util.ArrayList;
import java.util.List;

public class SegmentTree<T> {
	
	@FunctionalInterface
	interface binFInterf<T>{
		T foo(T a,T b);
	}
	
	private List<T> ar,t;
	private T RD;
	private int n;
	private binFInterf<T> func;
	SegmentTree(List<T> ar1,T rd,binFInterf<T> func1)
	{
		
		ar=new ArrayList<T>(ar1);
		n=ar1.size();
		func=func1;
		RD=rd;
		t=new ArrayList<T>(4*n+1);

		//Setting default redundant value in the tree
		int s=4*n+1;
		while(s-- > 0)
			t.add(rd);
		//Value Set Completed

		build(1,0,n-1);
	}
	void build(int v,int tl,int tr)
	{
		if(tl==tr)
			t.set(v, ar.get(tl));
		else
		{
			int m=(tl+tr)/2;
			build(2*v,tl,m);
			build(2*v+1,m+1,tr);
			t.set(v, func.foo(t.get(v*2),t.get(v*2+1)));
		}
	}
	T querry(int l,int r)
	{
		return querry(l,r,1,0,n-1);
	}
	T querry(int l,int r,int v,int tl,int tr)
	{
		if(l>r)
			return RD;
		else if(l==tl && r==tr)
		{
			return t.get(v);
		}
		else
		{
			int m=(tl+tr)/2;
			return func.foo(querry(l,Math.min(m,r),v*2,tl,m),querry(Math.max(m+1,l),r,v*2+1,m+1,tr));
		}
	}
	void update(int pos,T new_val)
	{
		update(pos,new_val,1,0,n-1);
	}
	void update(int pos,T new_val,int v,int tl,int tr)
	{
		if(tl==tr)
			t.set(v, new_val);
		else
		{
			int m=(tl+tr)/2;
			if(pos<=m)
				update(pos,new_val,2*v,tl,m);
			else
				update(pos,new_val,2*v+1,m+1,tr);
			t.set(v,func.foo(t.get(2*v),t.get(2*v+1)));
		}
	}
}
