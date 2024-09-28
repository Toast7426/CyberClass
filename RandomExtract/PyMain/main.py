import sys
import pygame
import random
pygame.init()
screen = pygame.display.set_mode((800, 450))
pygame.display.set_caption('RandomExtract')

bg = pygame.image.load('res/back_ground.png').convert()
img = pygame.image.load("res/carrot_on_a_stick.png")
pygame.display.set_icon(img)
file = open('properties.txt', 'r')    #配置文件
properties = file.readlines()
file = open('name.txt', 'r')    #姓名文件
names = file.readlines()

rolling = False
number = 0
lenthOfNameList = len(names)
black = 0, 0, 0
white = 255, 255, 255
font1 = pygame.font.Font('res/JetBrainsMono-Medium.ttf', 160)
font2 = pygame.font.Font('res/simsun.ttc', 160)


screen.blit(bg, (0, 0))
pygame.display.flip()
clock = pygame.time.Clock()
while True:
    clock.tick(30)    #fps
    for event in pygame.event.get():
        if event.type == pygame.MOUSEBUTTONUP:
            rolling = not rolling
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
    if rolling == True and properties[3] == 'number\n':    #学号模式
        number = random.randint(1, int(properties[1]))    #随机抽取
        numberToRender = font1.render(str(number), False, properties[5])    #准备元素
        screen.blit(bg, (0, 0))    #渲染
        screen.blit(numberToRender, (310, 100))
        pygame.display.flip()
    if rolling == True and properties[3] == 'name\n':    #姓名模式
        nameSequence = random.randint(1, lenthOfNameList)    #随机抽取
        nameToRender = font2.render(names[nameSequence - 1], False, properties[5])    #准备元素
        screen.blit(bg, (0, 0))    #渲染
        screen.blit(nameToRender, (90, 100))
        pygame.display.flip()
