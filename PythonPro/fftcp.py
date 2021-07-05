import cmath,math
def FFT(P,invert):
    n=len(P)
    if n==1: return P
    wn=cmath.exp(complex(0,2*cmath.pi/n*(-1 if invert else 1)))
    w=complex(1,0)
    Pe,Po=P[::2],P[1::2]
    ye,yo=FFT(Pe,invert),FFT(Po,invert)
    y=[complex(0,0)]*n
    for j in range(n//2):
        y[j]=ye[j]+w*yo[j]
        y[j+n//2]=ye[j]-w*yo[j]
        if invert:
            y[j]/=2
            y[j+n//2]/=2
        w*=wn
    return y
def polymul(A,B):
    la,lb=len(A),len(B)
    n=1
    while n<=len(A)+len(B): n<<=1
    FA=[complex(a,0) for a in A]
    FB=[complex(b,0) for b in B]
    for i in range(len(A),n): FA.append(0+0j)
    for i in range(len(B),n): FB.append(0+0j)
    FA,FB=FFT(FA,False),FFT(FB,False)
    FC=[complex(0,0)]*n
    for i in range(n): FC[i]=FA[i]*FB[i]
    IFC=FFT(FC,True)
    C=[0]*n
    for i in range(n): C[i]=round(IFC[i].real)
    return C[:la+lb-1:]


