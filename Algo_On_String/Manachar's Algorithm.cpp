//模板测试：http://www.spoj.com/problems/LPS/en/
void Manachar(string &str, int P[], int len){
	memset(P, 0, sizeof(int)*len);
	int C=0, R=-1, rad;
	for(int i=0; i<len; i++){
		if(i < R){
			rad = min(P[2*C-i], R-i);
		}
		else rad=0;
		//Try to extend
		while(i+rad+1 < len && i-(rad+1)>=0 && str[i-rad-1]==str[i+rad+1]){
			rad++;
		}
		P[i] = rad;
		if(i+rad > R){
			C=i;
			R=i+rad;
		}
	}
}
