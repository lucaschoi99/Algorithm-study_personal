from selenium import webdriver
from time import sleep

#chrome web driver path
driver = webdriver.Chrome("C:\Chrome_Driver\chromedriver.exe")

#chrome - naver login
driver.get("https://nid.naver.com/nidlogin.login")

#type id & password for login
sleep(0.5)
driver.find_element_by_name("id").send_keys('id')
sleep(0.5)
driver.find_element_by_name("pw").send_keys('password')

#click login button
driver.find_element_by_xpath('/html/body/div[2]/div[3]/div/form/fieldset/input').click()

#mail title parsing using Beautifulsoup
from bs4 import BeautifulSoup as bs

driver.get("https://mail.naver.com/")
html = driver.page_source
soup = bs(html, 'lxml')

#parse title
title_list = soup.find_all('strong', 'mail_title')
for title in title_list:
    print(title.text)

