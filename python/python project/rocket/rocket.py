import pygame

class Rocket:
  def __init__(self, ai_game):
    self.screen = ai_game.screen
    self.image = pygame.image.load('images/rocket.bmp')
    self.screen_rect = ai_game.screen.get_rect()
    self.rect = self.image.get_rect()
    self.rect.midbottom = self.screen_rect.midbottom
    self.moving_up = False
    self.moving_down = False
    self.moving_left = False
    self.moving_right = False
    self.settings = ai_game.settings
    self.x = float(self.rect.x)
    self.y = float(self.rect.y)
  
  def update(self):
    if self.moving_up == True and self.rect.top > 0:
      self.y -= self.settings.rocket_speed
    if self.moving_down == True and self.rect.bottom < self.screen_rect.bottom:
      self.y += self.settings.rocket_speed
    if self.moving_left == True and self.rect.left > 0:
      self.x -= self.settings.rocket_speed
    if self.moving_right == True and self.rect.right < self.screen_rect.right:
      self.x += self.settings.rocket_speed
    self.rect.x = self.x
    self.rect.y = self.y

  def blitme(self):
    self.screen.blit(self.image, self.rect)
