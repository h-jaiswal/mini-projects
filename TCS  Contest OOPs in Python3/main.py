class Container:
    def __init__(self, id, length, breadth, height, pricePerSqrFt):
        self.id = id
        self.length = length
        self.breadth = breadth
        self.height = height
        self.pricePerSqrFt = pricePerSqrFt

    def findVolume(self):
        return self.length * self.breadth * self.height
    
class PackagingCompany:
    def __init__(self, containerList):
        self.containerList = containerList
    def findContainerCost(self, id):
        for container in self.containerList:
            if container.id == id:
                cost = container.findVolume() * container.pricePerSqrFt
                return cost
            return None
    def findLargestContainer(self):
        maxVolume = self.containerList[0].findVolume()
        maxContainer = self.containerList[0]
        for container in self.containerList:
            volume = container.findVolume()
            if volume > maxVolume:
                maxVolume = volume
                maxContainer = container
        return maxContainer

def main():
    numContainer = int( input() )
    containerList = []
    for i in range(numContainer):
        id = int( input() )
        length = int( input() )
        breadth = int( input() )
        height = int ( input() )
        pricePerSqrFt = int( input() )

        containerList.append( Container( id, length, breadth, height, pricePerSqrFt))

    company = PackagingCompany(containerList)
    idQuery = int(input())
    cost = company.findContainerCost(idQuery)
    if cost == None:
        print("No Container Found")
    else:
        print(cost)
    maxContainer = company.findLargestContainer()
    print( f"{maxContainer.id} {maxContainer.findVolume()}")

if __name__ == "__main__":
    main()
