void solve(int& n,int& k, string& s) {	
	int64_t np1=3,np2=5;
	set<pair<int64_t,int64_t>>st;
	vector<int64_t> hash1(n+1), hash2(n+1), pnp1(n+1), pnp2(n+1);
	auto pre=[&]() {
		pnp1[0]=1;
		pnp2[0]=1;
		hash1[0]=0;
		hash2[0]=0;
		for(int i=0;i<n;++i) {
			hash1[i+1]=(hash1[i]+pnp1[i]*(s[i]-'0'+1)%mod)%mod;
			hash2[i+1]=(hash2[i]+pnp2[i]*(s[i]-'0'+1)%mod)%mod;
			pnp1[i+1]=pnp1[i]*np1%mod;
			pnp2[i+1]=pnp2[i]*np2%mod;
		}
	};
	pre();
	auto calcsub=[&](int i, int K) {
		return make_pair((pnp1[n-k-i]*((hash1[i+K]-hash1[i])%mod+mod)%mod)%mod, (pnp2[n-k-i]*((hash2[i+K]-hash2[i])%mod+mod)%mod)%mod);
	};
	auto insert=[&](int i, int K) {
		st.insert(calcsub(i, K));
	};
	
	string p(k, '0');
	
	auto calcstr=[&]() {
		int64_t hs1=0, hs2=0;
		for(int i=0;i<k;++i) {
			hs1=(hs1+pnp1[i]*(p[i]-'0'+1)%mod)%mod;
			hs2=(hs2+pnp2[i]*(p[i]-'0'+1)%mod)%mod;
		}
		return make_pair(hs1*pnp1[n-k]%mod, hs2*pnp2[n-k]%mod);
	};

	pair<int64_t,int64_t> Hs=calcstr();
	
	auto rem=[&](int i) {
		Hs.first=(Hs.first-pnp1[n-k+i]*(p[i]-'0'+1)%mod+mod)%mod;
		Hs.second=(Hs.second-pnp2[n-k+i]*(p[i]-'0'+1)%mod+mod)%mod;
	};
	auto add=[&](int i) {
		Hs.first=(Hs.first+pnp1[n-k+i]*(p[i]-'0'+1)%mod)%mod;
		Hs.second=(Hs.second+pnp2[n-k+i]*(p[i]-'0'+1)%mod)%mod;
	};
	auto nxt=[&]() {
		int i=p.length()-1;
		while(i!=-1&&p[i]=='1') {
			rem(i);
			p[i]='0';
			add(i);
			--i;
		}
		if(i!=-1) {
			rem(i);
			p[i]='1';
			add(i);
			return true;
		}
		return false;
	};

	for(int i=0;i+k<=n;++i)
		insert(i, k);
	do {
		if(!st.count(Hs)) {
			cout<<"YES\n"<<p<<'\n';
			return;
		}
	} while(nxt());
	cout<<"NO\n";
}


