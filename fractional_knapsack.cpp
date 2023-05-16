//fractional kanpsack

#include<iostream>
using namespace std;
class knapsack{
      public:
     double value;
     double weight;
     knapsack(double v,double w) {
           value=v; weight=w;
    }
     knapsack() {
           value=0; weight=0;
    }
};
//  v/w method
bool checkratio_byratio(knapsack k1,knapsack k2) {
    double d1=(k1.value) / k1.weight;
    double d2=(k2.value) / k2.weight;
   
     return d1>d2;
}
bool checkratio_byweight(knapsack k1,knapsack k2) {
    double d1= k1.weight;
    double d2= k2.weight;  
     return d1>d2;
}
bool checkratio_byvalue(knapsack k1,knapsack k2) {
    double d1=(k1.value);
    double d2=(k2.value);
   
     return d1>d2;
}
bool checkratio_lightest(knapsack k1,knapsack k2) {
    double d1=(k1.value);
    double d2=(k2.value);
   
     return d1<d2;
}
double knapsackk(int w,knapsack arr[],int n,int choice)
{
  //sorting of objects
  if(choice==1)
  {
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            
            if(checkratio_byvalue(arr[j+1],arr[j]))
            {
                knapsack temp;
                temp=arr[j+1];
                 arr[j+1]=arr[j];
                 arr[j]=temp;
            }
            
        }
    }
  }
  
  if(choice==2)
  {
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            
            if(checkratio_byweight(arr[j+1],arr[j]))
            {
                knapsack temp;
                temp=arr[j+1];
                 arr[j+1]=arr[j];
                 arr[j]=temp;
            }
            
        }
    }
  }
  if(choice==3)
  {
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            
            if(checkratio_byratio(arr[j+1],arr[j]))
            {
                knapsack temp;
                temp=arr[j+1];
                 arr[j+1]=arr[j];
                 arr[j]=temp;
            }
            
        }
    }
  }
  if(choice==4)
  {
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            
            if(checkratio_lightest(arr[j+1],arr[j]))
            {
                knapsack temp;
                temp=arr[j+1];
                 arr[j+1]=arr[j];
                 arr[j]=temp;
            }
            
        }
    }
  }

double final_value=0.0;
    for(int i=0;i<n;i++)
    {
        if(w>=arr[i].weight)
        {
            w-=arr[i].weight;
            final_value+=arr[i].value;
        }
        else{
           
           final_value+=(arr[i].value*(w/arr[i].weight));
           break;
        }
    }
    return final_value;
}

int main()
{
    int n,w=10,choice;
    double data1,data2;
   
    cout<<"enter no. of items"<<endl;
    cin>>n;
    cout<<"enter details: "<<endl;
    for(int i=0,j=0;i<n;i++,j+=2)
    {
       cout<<i<<") "<<"value: "; cin>>data1;
       cout<<"   Weight: ";cin>>data2;
       cout<<endl;
        knapsack arr[i]={knapsack(data1,data2)};
    }
    
     knapsack arr[]={{4,3},{1,6},{2.5,1},{6,2},{9,9}};
     cout<<"enter choice:\n1)sorting of value 2)sorting of weight 3)sorting by value/weight 4)lightest item first";
     cin>>choice;
     
     cout<< knapsackk(w,arr,n,choice)<<endl;

}