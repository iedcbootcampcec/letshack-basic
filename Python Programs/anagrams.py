def validate(word1,word2):
    word1=word1.lower()
    word2==word2.lower()
    if sorted(word1)==sorted(word2):
        print("anagrams")
    else:
        print("not anagrams")

print("enter the words\n")
word1=input("word1 is ")
word2=input("word2 is ")
validate(word1,word2)
