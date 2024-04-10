class Solution:
    def reformatNumber(self, number: str) -> str:
        pureNumber = [] # list of char
        for i, n in enumerate(number):
            if not n.isdigit():
                continue
            pureNumber.append(n)
        
        part1Num = len(pureNumber) // 3
        if (len(pureNumber) % 3) in (0, 1):
            part1Num -= 1
        
        formatNumber = ''
        for i in range(0, part1Num):
            formatNumber += ''.join(pureNumber[3 * i : 3 * i + 3]) + '-'
        
        remainingPart = pureNumber[part1Num * 3 :]
        if len(remainingPart) in (2, 3):
            formatNumber += ''.join(remainingPart)
        else:
            formatNumber += ''.join(remainingPart[:2]) + '-' + ''.join(remainingPart[-2:])
        return formatNumber