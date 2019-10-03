#define MAX_N 100005

int fw[MAX_N];

void add(int idx,int val)
{
    while(idx<MAX_N)
    {
        fw[idx]+=val;
        idx+=(idx&-idx);
    }
}

int sum(int idx)
{
    int ret=0;
    while(idx>0)
    {
        ret+=fw[idx];
        idx-=(idx&-idx);
    }
    return ret;
}
