'''
Requirements:
    pip install python-whois
'''

import whois
import sys
try:
    name = input("Enter the domain name: ")
    domain = whois.whois(name)
    if domain.domain_name == None:
        sys.exit(1)
except: 
    print("This Domain is available")
else:
    print("Oops! This Domain is already purchased")
