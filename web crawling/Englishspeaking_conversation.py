import requests
from bs4 import BeautifulSoup

#conversation list
class Conversation:
    #question, answer variables
    def __init__(self, question, answer):
        self.question = question
        self.answer = answer
    
    def __str__(self):
        statement = ["Q. ", self.question , " A. ", self.answer]
        return ''.join(statement)

#crawl subjects
def get_subjects():
    subjects = []
    
    req = requests.get("https://basicenglishspeaking.com/daily-english-conversation-topics/")
    html = req.text
    soup = BeautifulSoup(html, "html.parser")
    
    divs = soup.findAll('div', {"class": "thrv_wrapper thrv-columns"})
    for div in divs:
        links = div.findAll('a')
        
        for link in links:
            subject = link.text
            subjects.append(subject)
            
    return subjects

#print subjects
subjects = get_subjects()
print('Total ',len(subjects), 'subjects found...')
print(subjects)

#crawl conversations from each subjects
conversations =[]
i=1

#All conversations
for sub in subjects:
    print('[', i, '/', len(subjects), ']', sub)
    req= requests.get("https://basicenglishspeaking.com/" + sub)
    html = req.text
    soup = BeautifulSoup(html, 'html.parser')
    
    qnas = soup.findAll('div', {"class": "sc_player_container1"})
    
    for qna in qnas:
        if qnas.index(qna) % 2 ==0:
            q= qna.next_sibling
        else:
            a= qna.next_sibling
            c= Conversation(q,a)
            conversations.append(c)
    i+= 1
        
print('Total ', len(conversations), 'conversation found...')

for c in conversations:
    print(str(c))
                                
