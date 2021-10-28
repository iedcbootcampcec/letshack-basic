# Wikipedia Article About LZ78 Compression:
# https://en.wikipedia.org/wiki/LZ77_and_LZ78#LZ78

def getItemIndex(dictionary, newItem):
    # set the index to 0
    itemIndex=0
    # for the length of the dictionary
    for k in range(len(dictionary)):
        # if the newItem is equal to an entry in the dictionary
        if dictionary[k][1] == newItem:
            # return the index of the dictionary's entry as a string
            itemIndex=dictionary[k][0]
            return str(itemIndex)
    
def encoder(data):
    # initialize final output
    output=""
    # initialize empty dictionary
    dictionary=[[0, '']]
    # convert input string 'data' to a list
    inputList = list(data) 
    # initialize dictionary index
    dictIndex=0
    # we initialize newItem as nothing
    newItem=""
    
    # for every char in inputList
    for i in range(len(inputList)):
        # for every entry in the dictionary
        for j in range(len(dictionary)):
            # if newItem and the current char are present in the dictionary
            if newItem+inputList[i] == dictionary[j][1]:
                # set newItem to newItem plus the current char
                newItem+=inputList[i]
                # set itemFound to true because we have found an already present entry in the dictionary
                itemFound=True
                # if this is the last loop and the last entry is equal to an already present entry
                if i + 1 == len(inputList):
                    # add only the index of the dictionary to output
                    output+=getItemIndex(dictionary, newItem)
                # then break out of the dictionary loop
                break
            else:
                # if the dictionary loop doesn't find a match set itemFound to false
                itemFound=False
            
        # if we haven't found a match in the dictionary
        if not itemFound:             
            # add to the output the dictionary index and the current char
            output+=getItemIndex(dictionary, newItem)+inputList[i]
            # augment the dictionary index
            dictIndex+=1
            # since it's a new combination we add it to the dictionary
            dictionary.append([dictIndex, newItem+inputList[i]])
            # then we reset newItem
            newItem=""
    
    # once we have gone through all chars in the inputList
    # return the encoded data
    return output


def decoder(data):
    # initialize the output
    output=""
    # initialize an empty dictionary
    dictionary=[[0, '']]
    # transform the input data to a list of chars
    tempList = list(data)
    # initialize two empty arrays to store the indexes and the letters of the encoded string
    numList=[]
    letterList=[]
    # initialize the dictionary index to 0
    dictIndex=0
        
    # initialize the boolean to control is a value was a number (int) to false
    # because we always start a valid encoded string with a letter
    wasNum = False
    # for the length of the encoded string
    for i in range(len(tempList)):
        # if the current char is a number
        if tempList[i].isdigit():
            # if the previous char was a number means that
            # it's a double digit number (>9)
            if wasNum:
                # the last item of numList (ie: 1) is equal itself plus
                # the current char (ie: 0). Which makes 10.
                numList[-1]+=tempList[i]
            else:
                # if it's not a double digit number, add it to numList "as-is"
                numList.append(tempList[i])
            # then set that the last char was a number
            wasNum = True
        else:
            # if the current char it's not a number, add it to letterList instead
            letterList.append(tempList[i])
            # set that the last char wasn't a number
            wasNum = False
                
    # for the length of the list of letters
    for i in range(len(letterList)):
        # if the current index is equal to zero
        # means that is the first time we encounter this
        # letter by itself
        if int(numList[i]) == 0:
            # add the corresponding letter to the output
            output+=letterList[i]
            # increase the dictionary index
            dictIndex+=1
            # and add the current letter to the dictionary 
            dictionary.append([dictIndex, letterList[i]])
        # if the index is not equal to zero, must be <= the length of our dictionary
        else:
            # so add the corresponding entry in the dictionary plus the current letter
            newItem=dictionary[int(numList[i])][1]+letterList[i]
            # set the output to the newly created string
            output+=newItem
            # increase the dictionary index
            dictIndex+=1
            # append the new entry in the dictionary
            dictionary.append([dictIndex, newItem])
    
    # if the length of the list of indexes is greater than the one of the letters
    # means that the last pattern wasn't new
    if len(numList) > len(letterList):
        # so we add the pattern from the last index from the dictionary to the output
        output+=dictionary[int(numList[-1])][1]
        
    # then we return the decoded string
    return output

text="AABABABBABCB"
print("original text:", text)
print("encoded text:", encoder(text))
print("decoded text:", decoder(encoder(text)))
