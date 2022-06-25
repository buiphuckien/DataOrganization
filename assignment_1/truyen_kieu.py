f1 = open(r"truyen_kieu.txt" ,'r')
str = f1.read()
str_list = str.split(' ')
new_str = ''
for e in str_list:
    new_str += '\\' + 'x' + e
f2 = open('tk.txt', 'w')
f2.write(new_str)