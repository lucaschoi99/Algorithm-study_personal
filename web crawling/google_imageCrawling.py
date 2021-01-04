from selenium import webdriver
from selenium.webdriver.common.keys import Keys
import time
import urllib.request

#chrome web driver path
driver = webdriver.Chrome("C:\Chrome_Driver\chromedriver.exe")

#google image site
driver.get("https://www.google.co.kr/imghp?hl=ko&tab=wi&ogbl")

#검색창 찾은뒤 검색
elem = driver.find_element_by_name("q")
elem.send_keys("박보영")
elem.send_keys(Keys.RETURN) #enter key

#scroll down images
SCROLL_PAUSE_TIME = 1.5

# Get scroll height
last_height = driver.execute_script("return document.body.scrollHeight")

while True:
    # Scroll down to bottom
    driver.execute_script("window.scrollTo(0, document.body.scrollHeight);")

    # Wait to load page
    time.sleep(SCROLL_PAUSE_TIME)

    # Calculate new scroll height and compare with last scroll height
    new_height = driver.execute_script("return document.body.scrollHeight")
    if new_height == last_height:
        try:
            driver.find_element_by_css_selector(".mye4qd").click() # 결과 더보기 버튼 클릭
        except:
            break # done
    last_height = new_height
    
    
#click all images & get src & download to testImage folder
cnt = 1
images = driver.find_elements_by_css_selector(".rg_i.Q4LuWd")
for image in images:
    try:
        image.click()
        time.sleep(0.5)
        imgUrl = driver.find_element_by_css_selector(".n3VNCb").get_attribute("src")
        urllib.request.urlretrieve(imgUrl, "C:\\Users\\lucas\\Desktop\\testImage\\" + str(cnt) + ".jpg")
        cnt += 1
    except:
        print("Error occured")
        pass

# close web browser
driver.close()
