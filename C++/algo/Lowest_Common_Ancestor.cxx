int LCA(int x,int y)
{
   while(x!=y)
   {
     if(depth[x]<depth[y])swap(x,y);
     if(depth[x]==depth[y])
     {
        for(int i=18;i>=0;i--)
        {
           if(p[i][x]!=p[i][y])
           {
             x=p[i][x];
             y=p[i][y];
           }
        }
        if(p[0][x]==p[0][y])return p[0][x];
     }
     x=p[(int)log2(depth[x]-depth[y])][x];
   }
   return x;
}