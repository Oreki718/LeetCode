# read_list
x = input("Please type the list:")
y = input("Please enter the sum:")
xlist = x.split(",")
try:
    xlist = [int(xlist[i]) for i in range(len(xlist))]
    y = int(y)
except Exception as e:
    print(str(e))
    exit(1)

# 暴力解法
# def twoSum(nums, target):
#     if (len(nums) > 1):
#         for i in range(0, len(nums)-1):
#             for j in range(i+1, len(nums)):
#                 if ((nums[i] + nums[j]) == target):
#                     return ([i, j])
#         return ([])
#     else:
#         return ([])


# 提前将索引填入哈希表，利用哈希表求解,速度更快
def twoSum(nums, target):
    hashmap = {}
    for ind, num in enumerate(nums):
        hashmap[num] = ind
    for i, num in enumerate(nums):
        j = hashmap.get(target - num)
        if j is not None and i != j:
            return ([i, j])
    return ([])


print(twoSum(xlist, y))
