package t3;

public class MaxNiceMatrixDiv1 {
	public int[] getMaxMatrix(int a, int b, int c) {
		int [] ans= new int [50500];
		int [][] w= new int [1010][55];
		int t=b-a;
		for (int i=1;i<=c;i++)
			for (int j=0;j<=t;j++)
				for (int k=0;k<=t;k++)
				f[i][j]=min(f[i-1][j+k],f[i][j]);
				
			}
		return ans;
	}
}
