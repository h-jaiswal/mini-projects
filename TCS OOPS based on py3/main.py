class Table:
    def __init__( self, tableNo, waiterName, status):
        self.tableNo = tableNo;
        self.waiterName = waiterName;
        self.status = status


def findWaiterWiseTotalNoOfTables(tableList):
    waiterNameList = {}
    for table in tableList:
        if table.waiterName not in waiterNameList:

            waiterNameList[ table.waiterName ] = 0
        else:
            waiterNameList[ table.waiterName ] += 1
    return waiterNameList

def findWaiterNameByTableNo(tableList, tableNo):
    for table in tableList:
        if table.tableNo == tableNo:
            return table.waiterName
    return None

def main():

    numTable = int(input())
    tableList = []

    for i in range(numTable):
        tableNo = int(input())
        waiterName = input()
        status = input()

        tableList.append( Table(tableNo, waiterName, status) )
    
    reqTableNo = int(input())

    reqWaiterName = findWaiterNameByTableNo(tableList, reqTableNo)

    reqWaiterNameList = findWaiterWiseTotalNoOfTables(tableList)

    for waiterName, tableCount in reqWaiterNameList.items():
        print(waiterName+"-"+str(tableCount))
    
    print("No Table Found" if reqWaiterName == None else reqWaiterName)

if __name__ == "__main__":
    main()

