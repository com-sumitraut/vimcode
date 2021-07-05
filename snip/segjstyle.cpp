const int Nax = (int) 1e5;
int n, id, ql, qr, val, A[Nax];
class SgNode {
public:
    ld ans, sum, ilpsum, irpsum;
    int c;
    SgNode() {
    }

    SgNode(SgNode lhs, SgNode rhs) {
        merge(lhs, rhs);
    }

    void single(int ind) {
        ans = sum = ilpsum = irpsum = A[ind];
        c = 1;
    }

    void merge(SgNode lhs, SgNode rhs) {
        this->ans = lhs.ans + rhs.ans + lhs.ilpsum * rhs.c + rhs.irpsum * lhs.c;
        this->sum = lhs.sum + rhs.sum;
        this->ilpsum = lhs.ilpsum + rhs.ilpsum + lhs.c * rhs.sum;
        this->irpsum = lhs.irpsum + rhs.irpsum + rhs.c * lhs.sum;
        this->c = lhs.c + rhs.c;
    }
};
SgNode Sg[4*Nax];

void build(int nd, int sl, int sr) {
    if (sl == sr) {
        Sg[nd].single(sl);
        return;
    }
    int md = (sl + sr) >> 1, chl = nd << 1 | 1, chr = chl + 1;
    build(chl, sl, md);
    build(chr, md + 1, sr);
    Sg[nd].merge(Sg[chl], Sg[chr]);
}

void update(int nd, int sl, int sr) {
    if (sl == sr) {
        Sg[nd].single(sl);
        return;
    }
    int md = (sl + sr) >> 1, chl = nd << 1 | 1, chr = chl + 1;
    if (id <= md) update(chl, sl, md);
    else update(chr, md + 1, sr);
    Sg[nd].merge(Sg[chl], Sg[chr]);
}

SgNode query(int nd, int sl, int sr) {
    if (ql <= sl && sr <= qr) {
        return Sg[nd];
    }
    int md = (sl + sr) >> 1, chl = nd << 1 | 1, chr = chl + 1;
    if (qr <= md) return query(chl, sl, md);
    else if (md < ql) return query(chr, md + 1, sr);
    return SgNode(query(chl, sl, md), query(chr, md + 1, sr));
}


void solve() {
	cin>>n;
    for (int i = 0; i < n; ++i)
        cin>>A[i];
    --n;
    build(0, 0, n);
    int q;
    cin>>q;
    while (q-- > 0) {
        int op;
        cin>>op;
        if (op == 1) {
        	cin>>id>>val,--id;
            A[id] = val;
            update(0, 0, n);
        } else {
        	cin>>ql>>qr,--ql,--qr;
            cout<<fixed<<query(0, 0, n).ans<<'\n';
        }
    }	
}