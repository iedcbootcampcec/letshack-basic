def getItemIndex(dictionary, newItem):
    itemIndex=0

    for k in range(len(dictionary)):
        if dictionary[k][1] == newItem:
            itemIndex=dictionary[k][0]
            return str(itemIndex)
    
def encoder(data):
    output=""
    dictionary=[[0, '']]
    inputList = list(data) 
    dictIndex=0
    newItem=""
    
    for i in range(len(inputList)):
        for j in range(len(dictionary)):
            if newItem+inputList[i] == dictionary[j][1]:
                newItem+=inputList[i]
                itemFound=True
                if i + 1 == len(inputList):
                    output+=getItemIndex(dictionary, newItem)
                break
            else:
                itemFound=False
            
        if not itemFound:             
            output+=getItemIndex(dictionary, newItem)+inputList[i]
            dictIndex+=1
            dictionary.append([dictIndex, newItem+inputList[i]])
            newItem=""

    return output


def decoder(data):
    output=""
    dictionary=[[0, '']]
    tempList = list(data)
    numList=[]
    letterList=[]
    dictIndex=0
        
    wasNum = False
    for i in range(len(tempList)):
        if tempList[i].isdigit():
            if wasNum:
                numList[-1]+=tempList[i]
            else:
                numList.append(tempList[i])
            wasNum = True
        else:
            letterList.append(tempList[i])
            wasNum = False

    for i in range(len(letterList)):
        if int(numList[i]) == 0:
            output+=letterList[i]
            dictIndex+=1
            dictionary.append([dictIndex, letterList[i]])
        else:
            newItem=dictionary[int(numList[i])][1]+letterList[i]
            output+=newItem
            dictIndex+=1
            dictionary.append([dictIndex, newItem])

    if len(numList) > len(letterList):
        output+=dictionary[int(numList[-1])][1]

    return output

text="AABABABBABCB"
print("original text:", text)
print("encoded text:", encoder(text))
print("decoded text:", decoder(encoder(text)))
