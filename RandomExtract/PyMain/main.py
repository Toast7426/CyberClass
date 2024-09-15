import sys
import pygame
import random
pygame.init()
screen = pygame.display.set_mode((800, 450))
pygame.display.set_caption('RandomExtract')

bg = pygame.image.load('res/back_ground.png').convert()
img = pygame.image.load("res/carrot_on_a_stick.png")
pygame.display.set_icon(img)
file = open('properties.txt', 'r')
lines = file.readlines()

rolling = False
number = 0
black = 0, 0, 0
white = 255, 255, 255
font = pygame.font.Font('res/JetBrainsMono-Medium.ttf', 160)

clock = pygame.time.Clock()
while True:
    clock.tick(60)    #fps
    for event in pygame.event.get():
        if event.type == pygame.MOUSEBUTTONUP:
            rolling = not rolling
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
    if rolling == True:
        number = random.randint(1, int(lines[1]))
    screen.blit(bg, (0, 0))
    numberToRender = font.render(str(number), False, lines[3])
    screen.blit(numberToRender, (310, 100))
    pygame.display.flip()
