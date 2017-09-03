import hashlib
m=hashlib.new('sha224')
m.update(raw_input())
print m.hexdigest()