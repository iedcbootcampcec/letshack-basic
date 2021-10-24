import re

def Validate_It(IP):
	regex = "(([0-9]|[1-9][0-9]|1[0-9][0-9]|"\
			"2[0-4][0-9]|25[0-5])\\.){3}"\
			"([0-9]|[1-9][0-9]|1[0-9][0-9]|"\
			"2[0-4][0-9]|25[0-5])"
	regex1 = "((([0-9a-fA-F]){1,4})\\:){7}"\
			"([0-9a-fA-F]){1,4}"
	p = re.compile(regex)
	p1 = re.compile(regex1)
	if (re.search(p, IP)):
		return "Valid IPv4"
	elif (re.search(p1, IP)):
		return "Valid IPv6"
	return "Invalid IP"

IP = input('Enter an IP')
print(Validate_It(IP))
