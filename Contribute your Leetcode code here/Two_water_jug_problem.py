# Python3 implementation of program to solve the water jug problem (leetcode #365)
class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        x, y = (y, x) if y < x else (x, y)
        if x == z or y == z:
            return True
        if x == 0 or y == 0:
            return False 
        if z > x + y:
            return False
        if z % x == 0:
            return True
        if z == x + y:
            return True 
        if y % x == 0:
            return False
        if math.gcd(x,y) != 1 and z % math.gcd(x,y) != 0:
            return False
        if z % math.gcd(x,y) == 0:
            return True
        return True

#Hidden code 
# Driver class       