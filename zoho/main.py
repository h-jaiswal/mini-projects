import math

def main():
    # number of elements 
    n = int(input("Enter number of elements : ")) 
  
    # Below line read inputs from user using map() function  
    a = list(map(int,input("\nEnter the numbers : ").strip().split()))[:n]


    b = []
    for i in range(n):
        k = [-math.inf]*3
        k[0] = a[i-1] if i-1>=0 else 0
        k[1] = a[i]
        try:
            k[2] = a[i+1]
        except:
            k[2] = 0

        b.append( sum(k) )

    print( b )

if __name__ == "__main__":
    main()