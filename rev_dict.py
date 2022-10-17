

# initializing dictionary
test_dict = { 'gfg' : 10, 'is' : 15, 'best' : 20, 'for' : 10, 'geeks' : 20}

# printing original dictionary
print("The original dictionary is : " + str(test_dict))

# Remove duplicate values in dictionary
# Using loop
temp = []
res = dict()
for key, val in test_dict.items():
	if val not in temp:
		temp.append(val)
		res[key] = val

# printing result
print("The dictionary after values removal : " + str(res))
