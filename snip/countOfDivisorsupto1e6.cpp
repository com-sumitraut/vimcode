const int Nax=int(1e6)+1;
int countOfDivisors[Nax],temp[Nax];
int Spf[Nax];
vector<int>  pr;
void generatSpf() {
	countOfDivisors[1]=1;
	for(int i=2;i<Nax;++i) {
		if(Spf[i]==0) {
			Spf[i]=i;
			pr.pb(i);
			countOfDivisors[i]=2;
			temp[i]=1;
		} else if(Spf[i]==Spf[i/Spf[i]]) {
			temp[i]=1+temp[i/Spf[i]];
			countOfDivisors[i]=(temp[i]+1)*(countOfDivisors[i/Spf[i]]/(temp[i/Spf[i]]+1));
		} else {
			temp[i]=1;
			countOfDivisors[i]=2*countOfDivisors[i/Spf[i]];
		}
		for(int j=0;j<int(pr.size())&&pr[j]<=Spf[i]&&i*pr[j]<Nax;++j) {
			Spf[i*pr[j]]=pr[j];
		}
	}
}
