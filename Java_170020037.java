import java.util.*;
import java.io.*;
class Java_170020037{
	static int b[][] ;
	static int c[][];
public static void main(String[] args) {
Scanner sc =new Scanner(System.in);
int n =sc.nextInt();
int a[] =new int[n];

for(int i=0;i<n;i++){
a[i]=sc.nextInt();
}
int h =sc.nextInt();
int w =sc.nextInt();
b =new int[h][w];
c =new int[h][w];
for(int i=0;i<c.length;i++){
	Arrays.fill(c[i],1);
}
for(int i=0;i<h;i++){
 for(int j=0;j<w;j++){
   b[i][j]=sc.nextInt();
 }
  }
  for(int i=0;i<n;i++){
	  solve(a[i]);
	 //System.out.println(0+ " "+0);
  }
}
public static void solve(int a){
	int x =0;
	int y =0;
	long min =Long.MAX_VALUE;
	long count =0;
	for(int i=0;i<b.length;i++){
		for(int j=0;j<b[0].length;j++){
			count =0;
			      for(int k=i-a+1;k<i+a;k++){
					  if(k>=0 && k<b.length){
					  for(int f=j-a+1;f<j+a;f++){
						  if(f>=0 && f<b[0].length){
							 count += b[k][f]*c[k][f];
						  }
					  }
					  }
				  }
				  if(min >count){
					  x=i;
					  y=j;
					  min =count;
				  }
		}
	}
	for(int i=x-a+1;i<x+a;i++){
		for(int j=y-a+1;j<y+a;j++){
			if(i>=0 &&i<b.length &&j>=0 &&j<b[0].length){
				c[i][j]++;
			}
		}
	}
	System.out.println(x+" "+y);
}
}