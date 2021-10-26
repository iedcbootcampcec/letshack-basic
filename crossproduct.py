print("Enter vector A (x y z):")
vector1 = input().split(' ')

print("Enter vector B (x y z):")
vector2 = input().split(' ')

vector3 = []
vector3.append(int(vector1[1]) * int(vector2[2]) - int(vector1[2]) * int(vector2[1]))
vector3.append(-(int(vector1[0]) * int(vector2[2]) - int(vector1[2]) * int(vector2[0])))
vector3.append(int(vector1[0]) * int(vector2[1]) - int(vector1[1]) * int(vector2[0]))

crossproduct = str(vector3[0]) + 'i + ' + str(vector3[1]) + 'j + ' + str(vector3[2]) + 'k'

print('A X B = ', end='')
print(crossproduct)
