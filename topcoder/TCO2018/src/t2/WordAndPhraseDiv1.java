package t2;

public class WordAndPhraseDiv1 {
	public int findNumberOfPhrases(String s) {
		int cnt=0, n=s.length(), mo=1000000007;
		int [] p=new int [2000];
		long [][] f=new long [2000][5];
		f[0][0]=1;
		for (int i=1;i<n;i++) {
			if (s.charAt(i)!='_') continue;
			if (i<n-1 && (s.charAt(i+1)<'0' || s.charAt(i+1)>'9')) {
				p[++cnt]=i;
				if (p[cnt-1]==i-1) {
					f[cnt][0]=(f[cnt-1][0]+f[cnt-1][1])%mo;
					f[cnt][1]=f[cnt-1][0];
				}
				else {
					f[cnt][0]=(f[cnt-1][0]+f[cnt-1][1])%mo;
					f[cnt][1]=(f[cnt-1][0]+f[cnt-1][1])%mo;
				}
			}
		}
		return (int)((f[cnt][0]+f[cnt][1])%mo);
	}
}
