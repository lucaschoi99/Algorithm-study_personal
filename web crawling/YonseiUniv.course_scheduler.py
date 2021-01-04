from selenium import webdriver
from selenium.webdriver.common.keys import Keys

#chrome web driver path
driver = webdriver.Chrome("C:\Chrome_Driver\chromedriver.exe")

#연세대학교 포탈 수강편람 사이트
driver.get("http://ysweb.yonsei.ac.kr:8888/curri120601/curri_new.jsp#top")

#implicit wait
driver.implicitly_wait(5)

#select option from drop down menu(공과대학)
dep = Select(driver.find_element_by_xpath('/html/body/div[5]/form[2]/table/tbody/tr[1]/td[1]/span[3]/select'))
dep.select_by_value("s1104000H1")

#컴퓨터과학전공
major = Select(driver.find_element_by_xpath('/html/body/div[5]/form[2]/table/tbody/tr[1]/td[1]/span[4]/select'))
major.select_by_value("0412")

#년도(2020)
yr = Select(driver.find_element_by_xpath('/html/body/div[5]/form[2]/table/tbody/tr[1]/td[1]/span[7]/select'))
yr.select_by_value("2020")

#학기(1학기)
semster = Select(driver.find_element_by_xpath('/html/body/div[5]/form[2]/table/tbody/tr[1]/td[1]/span[8]/select'))
semster.select_by_value("1")

#search(click)
search = driver.find_element_by_xpath('/html/body/div[5]/form[2]/table/tbody/tr[1]/td[1]/a[1]/img').click()


#교과목명
cnt = 1
flag = True

#crawl subject, professor from data table
while(True):
    try:
        subject = driver.find_element_by_xpath("/html/body/div[5]/form[2]/table/tbody/tr[3]/td/div/div[2]/div/div[3]/div[2]/div/div[" + str(cnt) + "]/div[9]/span")
        professor = driver.find_element_by_xpath("/html/body/div[5]/form[2]/table/tbody/tr[3]/td/div/div[2]/div/div[3]/div[2]/div/div[" + str(cnt) + "]/div[14]/span")
        print(subject.text, end='/')
        print(professor.text)
        
        cnt += 1 #next subject to fetch
    except:
        #next page
        next_button = driver.find_element_by_xpath('/html/body/div[5]/form[2]/table/tbody/tr[3]/td/div/div[2]/div/div[8]/div/div/div[2]/div').click()
        cnt = 1 #initialize cnt
        
        #find out which page
        clicknum = driver.find_element_by_xpath('/html/body/div[5]/form[2]/table/tbody/tr[3]/td/div/div[2]/div/div[8]/div/div/div[3]').text.split(' ')
        
        #when to stop
        if(clicknum[0][0] == "1"):
            if(flag == True): #first iteration
                flag = False 
                pass
            else: #done with iterating pages
                break 
