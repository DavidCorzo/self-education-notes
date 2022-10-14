import requests
from bs4 import BeautifulSoup

page = 1
next_button = True
while next_button:
    website = requests.get(f'http://quotes.toscrape.com/page/{page}')
    soup = BeautifulSoup(website.text, 'html.parser')
    next_button = soup.select_one('.next > a') # gets the next element and the 'a' tag
    quotes = soup.select('.quote')
    for quote in quotes:
        text = quote.select_one('.text')
        author = quote.select_one('.author')
        tags = quote.select('.tag')
    print(f'Scrapping page={page}')
    page += 1

# Scrapping page=1
# Scrapping page=2
# Scrapping page=3
# Scrapping page=4
# Scrapping page=5
# Scrapping page=6
# Scrapping page=7
# Scrapping page=8
# Scrapping page=9
# Scrapping page=10