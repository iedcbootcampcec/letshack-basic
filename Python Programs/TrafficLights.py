#Python solution to 6Kyu CodeWars Traffic Lights - one car
def traffic_lights(road, n):
    noCar = str(road).replace('C', '.')
    noCar = noCar.replace('O', 'N')
    carPos = 0
    ligth1 = {4: ("G", "O"), 5: ("O", "R"), 10: ("R", "G")}
    ligth2 = {4: ("R", "G"), 9: ("G", "O"), 10: ("O", "R")}
    ligth3 = {0: ("N", "M"), 5: ("M", "V"), 10: ("V", "N")}
    arrPos = [road]
    for x in range(n):
        rat = x%11
        if ligth1.__contains__(rat):
            noCar = custRep(noCar, ligth1.get(rat))
        if ligth2.__contains__(rat):
            noCar = custRep(noCar, ligth2.get(rat))
        if ligth3.__contains__(rat):
            noCar = custRep(noCar, ligth3.get(rat))
        if (carPos+1<len(noCar)):
            if (noCar[carPos+1] == "G" or noCar[carPos+1] == "V" or noCar[carPos+1] == "."):
                carPos += 1
            arrPos.append(noCar[:carPos]+"C"+noCar[carPos+1:])
        else:
            arrPos.append(noCar)
    return arrPos


def custRep(string, arr):
    return str(string).replace(arr[0], arr[1])
