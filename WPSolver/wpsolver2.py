import os, io, subprocess, sys
from google.cloud import vision
from google.cloud.vision import types

# client = vision.ImageAnnotatorClient()
#
# FILE_PATH = '/Users/sbasnet/Desktop/cropped.jpg'
#
# with io.open(FILE_PATH, 'rb') as image_file:
# 	content = image_file.read()
#
# image = vision.types.Image(content=content)
# response = client.text_detection(image=image)
# texts = response.text_annotations
#
#
# word = ""
# wordSearch = []
# prev = None
#
# texts.pop(0)
# width = None
#
# for text in texts:
#
# 	currentY = text.bounding_poly.vertices[0].y
# 	if prev is None:
# 		prev = currentY
# 		word += text.description
# 	else:
# 		if abs(currentY - prev) > 90:
# 			if width is None:
# 				width = len(word)
# 			word = word[0:width]     # to avoid repetitions
# 			wordSearch.append(word)
# 			word = ""
#
# 		word += text.description
# 		prev = currentY
# wordSearch.append(word)
#
# print(wordSearch)
#
# outputFile = open('wordSearchFile.txt', 'w')
# for w in wordSearch:
# 	print(w, file=outputFile)
# outputFile.close()

wordToFind="ITINERARY"
subprocess.call(["g++", "-std=c++1z", "-w" , "-o" , "../WordSearch/WordSearchProject/WordSearchProject/output", "../WordSearch/WordSearchProject/WordSearchProject/main.cpp"], shell=True)
tmp = subprocess.call("../WordSearch/WordSearchProject/WordSearchProject/output WordSearchFile.txt {}".format(wordToFind),shell=True)








