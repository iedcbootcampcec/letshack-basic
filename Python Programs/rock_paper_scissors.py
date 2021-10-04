from random import randint
game=["rock","paper","scissors"]
chance=game[randint(0,2)]
player=False
while player==False:
    player=input("\nrock/paper/scissors?")
    if player==chance:
        print("\nTie!!!!")
    elif(player=='rock' and chance=='paper'):
         print("\nyou lose!",chance ,"covers",player)
    elif(player=='paper' and chance=='rock'):
         print("\nyou win!",player,"covers",chance)
    elif(player=='paper' and chance=='scissors'):
          print("\nyou lose!",chance ,"cuts",player)
    elif(player=='scissors' and chance=='paper'):
          print("\nyou win!",player,"cuts",chance)
    elif(player=='scissors' and chance=='rock'):
         print("\nyou lose!",chance ,"smashes",player)
    elif(player=='rock' and chance=='scissors'):
         print("\nyou win!",player,"smashes",chance)
    else:
        print("\nThis is not a valid paly.Check your spelling!")
    player=False
    chance=game[randint(0,2)]
        
    
        
        
