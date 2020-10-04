#Given an string of numbers separated by spaces, return the nighest and lowest
def HighAndLowest(numbers):
    num = [int(s) for s in numbers.split(' ')]
    return str(max(num)) + ' ' + str(min(num))
