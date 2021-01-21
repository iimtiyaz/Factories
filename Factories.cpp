#include <iostream>
#include<bits/stdc++.h> 
using std::runtime_error;
using namespace std;
int n,w,h;
int main() {
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
          cin>>w>>h;
        int b[h][w];
        int c[h][w];
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin>>b[i][j];
             c[i][j]=1;
		}
	}
	int x1[n];
	int y1[n];
for(int v=0;v<n;v++){
	//for(int v=n-1;v>=0;v--){
    int x =0;
	int y =0;
	long min =LONG_MAX;
	long d[h][w];
		for(int i=0;i<h;i++){
			long count =0;
		     int w1 =i-a[v]+1;
		     int w2=i+a[v];
		     if(w1<0){
		     	w1=0;
		     }
		     if(w2>=h){
		     	w2=h;
		     }
		     for(int k=w1;k<w2;k++){
					  int w3=1-a[v];
					  int w4 =a[v];
					  if(w3<0){
					  	w3=0;
					  }
					  if(w4>=w){
					  	w4=w;
					  }
					  for(int f=w3;f<w4;f++){
							 count += (b[k][f])*c[k][f];
							
					  }
				  }
				  d[i][0]=count;
				   if(min>=count){
							 	x=i;
							 	y=0;
							 	min=count;
							 }
			
		}
	
		for(int i=0;i<h;i++){
			for(int j=1;j<w;j++){
				long count1=0;
				long count2=0;
				int w1=i-a[v]+1;
				int w2 = i+a[v];
				if(w1<0){
					w1=0;
				}
				if(w2>=h){
					w2=h;
				}
				for(int k=w1;k<w2;k++){
					if(j+a[v]-1<w){
						count1+=b[k][j+a[v]-1]*c[k][j+a[v]-1];
					}
				}
				for(int k=w1;k<w2;k++){
					if(j-a[v]>=0){
						count2 +=b[k][j-a[v]]*c[k][j-a[v]];
					}
				}
				d[i][j]=(d[i][j-1]+count1-count2);
				 if(min>=(d[i][j])){
							 	x=i;
							 	y=j;
							 	min=d[i][j];
							 }
			}
		}
      for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				cout<<d[i][j]<<" ";
			}
			cout<<"\n";
		}
		cout<<"\n";
		        int w1=x-a[v]+1;
				int w2 = x+a[v];
				if(w1<0){
					w1=0;
				}
				if(w2>=h){
					w2=h;
				}
				int w3 =y-a[v]+1;
				if(w3<0){
					  	w3=0;
					  }
					  int w4=y+a[v];
					  if(w4>=w){
					  	w4=w;
					  }
for(int i=w1;i<w2;i++){
		for(int j=w3;j<w4;j++){
				c[i][j]++;
		}
	}
//cout<<x<<" "<<y<<"\n";
x1[v]=x;
y1[v]=y;
	}
	for(int i=0;i<n;i++){
		cout<<x1[i]<<" "<<y1[i]<<"\n";
	}
	return 0;
}