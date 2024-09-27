n = int(input())

ans = []
def TowerOfHanoi(n , source, destination, auxiliary):
    global ans
    if n==1:
        # print (source,destination)
        ans.append((source,destination))
        return
    TowerOfHanoi(n-1, source, auxiliary, destination)
    # print (source,destination)
    ans.append((source, destination))
    TowerOfHanoi(n-1, auxiliary, destination, source)
        

TowerOfHanoi(n,'1','3','2') 
print(len(ans))
for a in ans:
    print(*a)
