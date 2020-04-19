from tkinter import *
from chatterbot import ChatBot
from chatterbot.trainers import ListTrainer,ChatterBotCorpusTrainer
from PIL import Image , ImageTk
chatbot=ChatBot('ChatBot')

conversation = [
    "Good morning",
    "Good morning, how are you?",
    "I am doing well, how about you?",
    "I'm also good.",
    "That's good to hear.",
    "Yes it is.",
    "Hello",
    "Hi",
    "How are you doing?",
    "I am doing well.",
    "That is good to hear",
    "Yes it is.",
    "Can I help you with anything?",
    "Yes, I have a question.",
    "What is your question?",
    "Could I borrow a cup of sugar?",
    "I'm sorry, but I don't have any.",
    "Thank you anyway",
    "No problem",
    "How are you doing?",
    "I am doing well, how about you?",
    "I am also good.",
    "That's good.",
    "Have you heard the news?",
    "What good news?",
    "What is your favorite book?",
    "I can't read.",
    "So what's your favorite color?",
    "Blue"
    "Hi there!",
    "How are you doing?",
    "I'm doing great.",
    "That is good to hear",
    "Thank you.",
    "You're welcome.",
    "What is your name",
    "My name is chatbot",
]

english_bot = ChatBot("Chatterbot", storage_adapter="chatterbot.storage.SQLStorageAdapter")
trainer = ChatterBotCorpusTrainer(english_bot)
trainer.train("chatterbot.corpus.english")

def getval():
    con=text.get()
    res=chatbot.get_response(con)
    box.insert(END,"You :"+con)
    box.insert(END,"Cisco :"+ str(res))
    texte.delete(0,END)
    


#a=getval()
tk=Tk()
tk.title("CHATBOT")
tk.geometry("550x650")
tk.minsize(500,600)
tk.configure(background='grey')


img=Image.open("logo.jpg")
imge=ImageTk.PhotoImage(img)
img_label=Label(image=imge)
img_label.pack()


frame=Frame(tk, width=100, height=100,)
sc=Scrollbar(frame)


box=Listbox(frame, width=50, height=20)
sc.pack(side=RIGHT, fill=Y)
box.pack(side=LEFT, fill=BOTH, pady=10)
frame.pack()


text=StringVar()
texte=Entry(tk,textvariable=text)
texte.pack(pady=10)
'''
text = Entry(tk, font=("Verdana", 16))
text.pack(pady=10)
'''
btn=Button(tk,text="ASK",command=getval)
btn.pack()

tk.mainloop()