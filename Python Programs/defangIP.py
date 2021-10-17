def defang(address):
    ip_address=address.split(".")
    new_address="[.]".join(ip_address)
    print(new_address)   

addrress=input("Link to defang: ")
defang(addrress)
