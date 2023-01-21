import pygame

class Player:
    def __init__(self, game):
        self.screen = game.screen
        self.screen_rect = game.screen.get_rect()
        self.image = pygame.image.load('images/player_still.png')
        self.settings = game.settings
        self.rect = self.image.get_rect()
        self.rect.midbottom = self.screen_rect.midbottom
        self.moving_right = False
        self.moving_left = False
        self.moving_up = False
        self.x = float(self.rect.x)
        self.y = float(self.rect.y)

    def blitme(self):
        self.screen.blit(self.image, self.rect)

    def update(self):
        if self.moving_right == False and self.moving_left == False and self.moving_up == False:
            self.image = pygame.image.load('images/player_still.png')
        elif self.moving_up == True:
            self.y -= self.settings.dy
        elif self.moving_right == True and self.rect.right < self.screen_rect.right:
            self.x += self.settings.dx
            self.image = pygame.image.load('images/player_running_right.png')
        elif self.moving_left == True and self.rect.left > 0:
            self.x -= self.settings.dx
            self.image = pygame.image.load('images/player_running_left.png')
        self.rect.x = self.x
        self.rect.y = self.y