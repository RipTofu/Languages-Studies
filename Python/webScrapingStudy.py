from bs4 import BeautifulSoup
from selenium import webdriver
import re

driver = webdriver.Edge()

productos = []
precios = []
raitings = []

driver.get("https://www.solotodo.cl/notebooks?score_games_start=300")
content = driver.page_source
soup = BeautifulSoup(content, features="html.parser")
x = soup.find_all('div', class_="css-1g4yje1")
for i in x:
    nombre = i.find('div', class_="MuiTypography-root MuiTypography-h5 css-1x1x8qm")
    precio = i.find('div', class_="MuiTypography-root MuiTypography-h2 css-1gj9m9x")
    productos.append(nombre)
    precios.append(precio)
    datos = i.find('div', class_="ProductPage_product_specs__bOxSw")
    for elem in datos:
        procesador = elem.find('dt', string=re.compile("Procesador")).find_next('dd').string.strip()
        print(procesador)
        print("----------------------------------------")