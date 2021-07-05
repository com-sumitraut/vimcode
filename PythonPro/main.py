from sys import stdin, stdout, stderr
def getInts(): map(int,stdin.readline().split())
def getInt(): int(stding.readline())

class Solution:
    def isCovered(self, ranges: List[List[int]], left: int, right: int) -> bool:
        mrk=[0]*(200)
        for i,j in range(ranges):
            mrk[i]+=1
            mrk[j+1]-=1
        for i in range(1,r):
            mrk[i]+=mrk[i-1]
        for i in range(l,r+1):
            if mrk[i]==0:
                return False
        return True