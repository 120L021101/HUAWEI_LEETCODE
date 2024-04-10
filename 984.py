class Solution:
    def strWithout3a3b(self, a: int, b: int) -> str:
        if a > b:
            maxVal, minVal = a, b
            maxCh, minCh = 'a', 'b'
        else:
            maxVal, minVal = b, a
            maxCh, minCh = 'b', 'a'
        
        retStr = []
        while maxVal < 2 * minVal and minVal >= 0 and maxVal >= 0:
            maxVal -= 1
            minVal -= 1
            retStr.extend((maxCh, minCh))
        
        while maxVal > 0 and minVal > 0:
            maxVal -= 2
            minVal -= 1
            retStr.extend((maxCh, maxCh, minCh))

        while maxVal > 0:
            retStr.extend((maxCh))
            maxVal -= 1
        
        while minVal > 0:
            retStr.extend((minCh))
            minVal -= 1
        

        return ''.join(retStr)