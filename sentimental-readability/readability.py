from cs50 import get_string

s = get_string("Text: ")

letters = 0
sentence = 0
words = 0


for char in s:
   if char.isalpha():
      letters += 1
   if char.isspace():
      words += 1
   if char in ['.', '!', '?']:
      sentence += 1
      
words += 1
L = (letters / words) * 100
S = (sentence / words) * 100
index = int((0.0588 * L - 0.296 * S - 15.8) + 0.5)

if index < 1:
   print ("Before Grade 1")
elif index >= 16:
   print ("Grade 16+")
else:
   print (f"Grade, {index}")
