#pip install gTTS otherwise wont work (for beginners)

from gtts import gTTS                #A module for text to speech vonversion



language = 'en'                         #it detects the language we use


txt_val = input("Enter the text to convert into speech:")

speak = gTTS(text=txt_val,lang=language,slow=False)

speak.save("pyaudio.mp3")

# after giving input search for a audio file named pyaudio.mp3 then play it

#if you are running this code in vscode us run using terminal option otherwise it shows some error in some systems




