//incomplete range tree refer wiki for complete functionality
struct range_tree
{
	int nodes[LIMIT3],*temp,n;
	range_tree()
	{
		temp=0;
	}
	int initialize(int node,int l,int u)
	{
		if(node==0)
			memset(nodes,0,sizeof(nodes));
		if(l==u)
		{
			nodes[node]=temp[l];
			return temp[l];
		}
		else
		{
			int mid=(l+u)/2;
			nodes[node]=initialize(left(node),l,mid);
			mid=initialize(right(node),mid+1,u);
			return max(nodes[node],mid);
		}
	}
	bool range_query(int l,int u)
	{
		int p=0,val1=-1;
		while(1)
		{
			if(nodes[p]==l)
			{
				val1=l;
				break;
			}
			if(nodes[p]<l)
			{
				if(nodes[right(p)])
					p=right(p);
				else break;
			}
			else
			{
				if(nodes[left(p)])
					p=left(p);
				else
				{
					val1=nodes[p];
					break;
				}
			}
		}
		if(val1==-1 || val1>u)
			return false;
		return true;
	}
	void display()
	{
		for(int i=0;i<20;i++)
			putintc(nodes[i]);
	}
};

