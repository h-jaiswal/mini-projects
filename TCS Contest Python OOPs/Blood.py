class Blood:
    def __init__(self, bloodGroup, unitInHand):
        self.bloodGroup = upper(bloodGroup)
        self.unitInHand = unitInHand

class BloodBank:
    def __init__(self, bloodList):
        self.bloodList = bloodList
    def isBloodAvailable(self, bloodGroupRequired, unitRequired):
        for blood in self.bloodList:
            if blood.bloodGroup == bloodGroupRequired and blood.unitInHand >= unitRequired:
                return True
        return False
    
    def findMinBloodStock(self):
        minStockValue = 0
        for blood in self.bloodList:
            if blood.unitInHand <= minStockValue:
                minStockValue = blood.unitInHand
        for blood in self.bloodList:
            if blood.unitInHand == minStockValue:
                minBloodList.append(blood)
        return minBloodList


def main():
    numBloodGroup = int(input())
    bloodList = []
    for i in range(numBloodGroup):
        bloodGroup = input()
        unitInHand = int(input())
        bloodList.append( Blood(bloodGroup, unitInHand))
    
    bank = BloodBank(bloodList)

    bloodGroupRequired = upper(input())

    unitRequired = int(input())

    if ( bank.isBloodAvailable(bloodGroupRequired, unitRequired) ):
        print("Blood Available")
    else:
        print("Blood not Available")
    
    minBloodList = findMinBloodStock()
    for blood in minBloodList:
        print(blood.bloodGroup)