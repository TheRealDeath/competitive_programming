#Slower but smaller version of parallel prime swing//No imports
def factorialS(n):
    smallOddSwing = [1,1,1,3,3,15,5,35,35, 315, 63, 693, 231, 3003, 429, 6435, 6435, 109395,12155,230945,46189,969969,88179,2028117,676039,16900975,   1300075,35102025,5014575,145422675,9694845,300540195,300540195 ]
    smallOddFactorial = [1,1,1,3,3,15,45,315, 315, 2835, 14175, 155925, 467775, 6081075, 42567525, 638512875, 638512875 ]
    def product(m, len):
        if len == 1: return m
        if len == 2: return m * (m - 2)
        hlen = len >> 1
        return product(m - hlen * 2, len - hlen) * product(m, hlen)
    def oddFactorial(n):
        sqrOddFact = 1
        if n < 17:
            oddFact = smallOddFactorial[n]
            sqrOddFact = smallOddFactorial[n//2]
        else:
            (sqrOddFact, oldOddFact) = oddFactorial(n//2)
            if n < 33: 
                oddSwing = smallOddSwing[n] 
            else:
                len = (n - 1) // 4
                if (n % 4) != 2: len += 1
                high = n - ((n + 1) & 1)
                oddSwing = product(high, len) // oldOddFact
            oddFact = (sqrOddFact**2) * oddSwing
        return (oddFact, sqrOddFact)
    if n == 0: return 1
    if n <  0: return 0
    N, bits = n, n
    while N != 0:
        bits -= N & 1
        N >>= 1
    F = oddFactorial(n)
    return F[0]*2**bits
