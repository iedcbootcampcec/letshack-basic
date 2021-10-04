def convert(s):
    f = float(s)
    c = (f - 32) * 5/9
    return c
cel=int(input("enter yout farenheit:"))
print(convert(cel))
