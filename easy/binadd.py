
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        res = []

        if len(a) > len(b):
            b = "0" * (len(a) - len(b)) + b
        else:
            a = "0" * (len(b) - len(a)) + a

        carry = 0
        for i in range( len(a) - 1, -1, -1 ):
            nxt = int( a[i] ) ^ int( b[i] ) ^ carry
            res.append( str(nxt) )
            carry = 1 if int( a[i] ) + int( b[i] ) + carry >= 2 else 0
        
        if carry == 1:
            res.append( "1" )
        
        strnum = "".join( res[::-1] )
        return strnum


Solution().addBinary( "101", "1" )