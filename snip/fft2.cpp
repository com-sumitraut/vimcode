const double PI = acos(-1);
using cd = complex<double>;
int reverse(int num,int lg_n) {
	int res=0;
	for(int i=0;i<lg_n;++i) {
		if(num&(1<<i)) {
			res |= 1<<(lg_n-1-i);
		}
	}
	return res;
}
void fft(vector<cd>& a,bool invert) {
	int n=a.size();
	int lg_n=0;
	while((1<<lg_n)<n) ++lg_n;
	for(int i=1;i<n;++i) {
		if(i<reverse(i,lg_n)) {
			swap(a[i],a[reverse(i,lg_n)]);
		}
	}
	for(int len=2;len<=n;len<<=1) {
		double ang=2*PI/len*(invert?-1:1);
		cd wlen(cos(ang),sin(ang));
		for(int i=0;i<n;i+=len) {
			cd w(1);
			for(int j=0;j<len/2;++j) {
				cd u=a[i+j],v=a[i+j+len/2]*w;
				a[i+j]=u+v;
				a[i+j+len/2]=u-v;
				w*=wlen;
			}
		}
	}
	if(invert) {
		for(cd& x:a) {
			x/=n;
		}
	}
}
vector<int> multiply(const vector<int>& a,const vector<int>& b) {
	vector<cd> fa(a.begin(),a.end()),fb(b.begin(),b.end());
	int n=1,fN=a.size()+b.size()-1;
	while(n<a.size()+b.size()) n<<=1;
	fa.resize(n);
	fb.resize(n);
	fft(fa,false);
	fft(fb,false);
	for(int i=0;i<n;++i) fa[i]*=fb[i];
	fft(fa,true);
	vector<int> result(fN);
	for(int i=0;i<fN;++i) result[i]=round(fa[i].real());
	return result;
}


