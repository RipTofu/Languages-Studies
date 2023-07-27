import selenium.common.exceptions
from selenium import webdriver
from selenium.webdriver.common.by import By
import time

mail = "mail"
password = "pass"
driver = webdriver.Edge()
driver.get("https://canvas.unab.cl/courses/22789")
content = driver.page_source
# Click en login via mail
driver.find_element("xpath", '//*[@id="content"]/div/div[2]/div/div/div[2]/button[1]').click()

# Input mail y clave
time.sleep(1)
driver.find_element("xpath", '/html/body/div/form[1]/div/div/div[2]/div[1]/div/div/div/div/div[1]/div[3]/div/div/div/div[2]/div[2]/div/input[1]').send_keys(mail)
driver.find_element("xpath", '/html/body/div/form[1]/div/div/div[2]/div[1]/div/div/div/div/div[1]/div[3]/div/div/div/div[4]/div/div/div/div/input').click()
time.sleep(1)
driver.find_element("xpath", '/html/body/div/form[1]/div/div/div[2]/div[1]/div/div/div/div/div/div[3]/div/div[2]/div/div[3]/div/div[2]/input').send_keys(password)
driver.find_element("xpath", '/html/body/div/form[1]/div/div/div[2]/div[1]/div/div/div/div/div/div[3]/div/div[2]/div/div[4]/div[2]/div/div/div/div/input').click()
time.sleep(1)
driver.find_element("xpath", '/html/body/div/form/div/div/div[2]/div[1]/div/div/div/div/div/div[3]/div/div[2]/div/div[3]/div[2]/div/div/div[1]/input').click()

# Encuentra links en el sitio.
elementosh = driver.find_elements(By.TAG_NAME, "a")
driver.find_element("xpath", '/html/body/div[5]/div[4]/div/div/div/span[2]/span[2]/button[1]').click()
time.sleep(1)
driver.find_element("xpath", '/html/body/div[5]/div[4]/div/div/div/span[2]/span[2]/button').click()
time.sleep(1)
# Encuentra links correspondientes a la "Semana" y agrega a lista de links.
links = []
for a in elementosh:
    if "Semana" in a.text:
        links.append(a.get_attribute('href'))
print("Links extraídos")

# Recorre lista de links.
for link in links:
    time.sleep(1)
    driver.get(link)
    time.sleep(1)
    # Intenta cerrar popup que impide clickear links de descarga, si aparece.
    try:
        driver.find_element("xpath", '/html/body/div[5]/div[4]/div/div/div/span[1]/span/button').click()
        time.sleep(1)
        driver.find_element("xpath", '/html/body/div[6]/div[4]/div/div/div/span[2]/span[2]/button').click()
    except selenium.common.exceptions.NoSuchElementException:
        pass
    # Encuentra links de descarga y, si es posible, clickea para descargar los archivos.
    for i in driver.find_elements(By.TAG_NAME, "a"):
        try:
            if "Download" in i.text and ".pdf" in i.text:
                print("encontrado: " + i.text)
                i.click()
                print("Descargando archivo")
        except selenium.common.exceptions.StaleElementReferenceException:
            pass
