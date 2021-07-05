import cmath,math
def FFT(P):
    n=len(P)
    if n==1: return [complex(P[0],0)]
    wn=cmath.exp(complex(0,2*cmath.pi/n))
    w=complex(1,0)
    Pe,Po=P[::2],P[1::2]
    ye,yo=FFT(Pe),FFT(Po)
    y=[complex(0,0)]*n
    for j in range(n//2):
        y[j]=ye[j]+w*yo[j]
        y[j+n//2]=ye[j]-w*yo[j]
        w*=wn
    return y
def IFFT(P):
    n=len(P)
    if n==1: return P
    wn=cmath.exp(complex(0,-2*cmath.pi/n))
    w=complex(1,0)
    Pe,Po=P[::2],P[1::2]
    ye,yo=IFFT(Pe),IFFT(Po)
    y=[complex(0,0)]*n
    for j in range(n//2):
        y[j]=(ye[j]+w*yo[j])/2
        y[j+n//2]=(ye[j]-w*yo[j])/2
        w*=wn
    return y
def polymul(A,B):
    la,lb=len(A),len(B)
    n=1
    while n<=len(A)+len(B): n<<=1
    for i in range(len(A),n): A.append(0)
    for i in range(len(B),n): B.append(0)
    FA,FB=FFT(A),FFT(B)
    FC=[complex(0,0)]*n
    for i in range(n): FC[i]=FA[i]*FB[i]
    IFC=IFFT(FC)
    C=[0]*n
    for i in range(n): C[i]=round(IFC[i].real)
    return C[:la+lb-1:]
