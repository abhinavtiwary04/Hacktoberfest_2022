#Code to implement binary search using bubble sort

def bs(arr, l, r, x):          #Binary Search
    if r >= l:
        mid = l + (r - l) // 2
        if arr[mid] == x:
            return mid
            
        elif arr[mid] > x:
            return bs(arr, l, mid-1, x)
            
        else:
            return bs(arr, mid + 1, r, x)
 
    else:
        return -1
        
        
def bsort(arr):              #Bubble Sort
    le=len(arr)
    for i in range(le):
        for j in range(0, le-i-1):
            if arr[j]>arr[j+1]:
                arr[j], arr[j+1]=arr[j+1],arr[j]
                


if __name__=="__main__":
    arr=[]
    y=int(input("Enter the number of elements:"))
    if(y!=0):
        print("Enter the numbers:")
    for a in range(0,y):
        b=int(input())
        arr.append(b)
        
        
    
    
    x=int(input("Enter the number to be searched:"))
    l=len(arr)
    
    bsort(arr)
 

    res = bs(arr, 0, len(arr)-1, x)
 
    if res != -1:
        print("Element is present in the array")
    else:
        print("Element not found")
